#include "score.h"

#include <QFont>
#include <QFontDatabase>

#include "game.h"

extern Game * game;

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    setZValue(1);

    score = 0;

    setPlainText("Score : " + QString::number(score));
    setDefaultTextColor(Qt::white);

    QString font = QFontDatabase::applicationFontFamilies(0).at(0);

    setFont(QFont(font));
}

void Score::increase(int number){
    score += number;
    setPlainText("Score: " + QString::number(score));
}

int Score::getScore(){
    return score;
}
