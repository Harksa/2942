#include "score.h"

#include <QFont>
#include <QFontDatabase>
#include <QInputDialog>
#include <QLabel>

#include "game.h"

extern Game * game;

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    setZValue(1);

    score = 0;

    //Afficher le texte.
    setPlainText("Score : " + QString::number(score));
    setDefaultTextColor(Qt::white);

    QString font = QFontDatabase::applicationFontFamilies(0).at(0);

    setFont(QFont(font));
	
	for(int i = 0 ; i < 10 ; i++)
	{
		highScores[i].playerName = " ";
		highScores[i].playerScore = -1;
	}
}

void Score::increase(int number){
    score += number;
    setPlainText("Score: " + QString::number(score));
}

int Score::getScore(){
    return score;
}

/***Verifie si le score du joueur fait partie des dix meilleurs****/
void Score::checkHighScores(int score)
{
	for(int i = 0 ; i < 10 ; i++)
	{
			if(score >= highScores[i].playerScore)
			{
                QString name = getPlayerName();
				newHighScore(name, score, i);
				break;
			}
	}
}

//Màj du tableau des scores s'il y en a un nouveau
void Score::newHighScore(QString name, int score, int position)
{
		for(int i = 9 ; i >= position ; i--)
		{
			if(i == position)//si on est à la position du nouveau score
			{
				highScores[i].playerScore = score;
				highScores[i].playerName = name;
			}
			else
			{
				highScores[i].playerScore = highScores[i-1].playerScore; 
				highScores[i].playerName = highScores[i-1].playerName;
			}
		}
}

//Récupération du nom du joueur
QString Score::getPlayerName()
{
        //QString name = "patate";
		QString label = "Felicitations, vous êtes dans le TOP 10 !";
		QString textBox = "Pseudo";
   
		bool ok;
		
		QString name = QInputDialog::getText(0, 
										" ",
                                        label, 
										QLineEdit::Normal,
                                        textBox,
										&ok);
		return name;
}

//Affichage du tableau des highScores
void Score::showHighScores()
{
	int offset = 0;
	for(int i = 0 ; i < 10 ; i++)
	{
		if(highScores[i].playerScore == -1)
		{
			break;
		}
		offset+=scene()->height() / 30;
        QGraphicsTextItem * name = new QGraphicsTextItem(highScores[i].playerName);
        name->setDefaultTextColor(Qt::white);
        QString font = QFontDatabase::applicationFontFamilies(0).at(0);
        name->setFont(QFont(font, 20));
        scene()->addItem(name);

        name->setPos(scene()->width() * 0.5 / 6, scene()->height() / 2 + offset);
		
		QGraphicsTextItem * score = new QGraphicsTextItem( QString::number(highScores[i].playerScore));
        score->setDefaultTextColor(Qt::white);
        score->setFont(QFont(font, 20));
        scene()->addItem(score);

        score->setPos(scene()->width() * 4 / 6, scene()->height() / 2 + offset);
    }
}
