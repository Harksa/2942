#include "highscores.h"

#include <QInputDialog>
#include <QLabel>

#include "game.h"

extern Game * game;

HighScores::HighScores(QGraphicsItem *parent){
	for(int i = 0 ; i < 10 ; i++){
		highScores[i].playerName = " ";
		highScores[i].playerScore = -1;
	}

	Q_UNUSED(parent);
}
	
/***Verifie si le score du joueur fait partie des dix meilleurs****/
void HighScores::checkHighScores(int score){
	for(int i = 0 ; i < 10 ; i++){
        if(score >= highScores[i].playerScore){
            QString name = getPlayerName();
            newHighScore(name, score, i);
            break;
        }
	}
}

//Màj du tableau des scores s'il y en a un nouveau
void HighScores::newHighScore(QString name, int score, int position){
    for(int i = 9 ; i >= position ; i--){
        if(i == position) { //si on est à la position du nouveau score
            highScores[i].playerScore = score;
            highScores[i].playerName = name;
        }
        else {
            highScores[i].playerScore = highScores[i-1].playerScore;
            highScores[i].playerName = highScores[i-1].playerName;
        }
    }
}

//Récupération du nom du joueur
QString HighScores::getPlayerName(){
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
void HighScores::showHighScores(int offset){
    for(int i = 0 ; i < 10 ; i++) {
		if(highScores[i].playerScore == -1){
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
