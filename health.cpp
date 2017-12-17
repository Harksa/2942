#include "health.h"

#include <QFont>
#include <QFontDatabase>

#include "game.h"

extern Game * game;

Health::Health(QGraphicsItem *parent){
    setZValue(1);

    health = 3;

    setPlainText("Health : " + QString::number(health));
    setDefaultTextColor(Qt::red);

    QString font = QFontDatabase::applicationFontFamilies(0).at(0);

    setFont(QFont(font));

    Q_UNUSED(parent);
}

void Health::decrease(){
    if(health > 0)
    health--;
    setPlainText("Health : " + QString::number(health));

    if(health == 0) {
        game->spawner->canSpawn = false;

        QGraphicsTextItem * gameover = new QGraphicsTextItem("Game Over");
        gameover->setDefaultTextColor(Qt::white);
        QString font = QFontDatabase::applicationFontFamilies(0).at(0);
        gameover->setFont(QFont(font, 20));
        scene()->addItem(gameover);

        gameover->setPos(scene()->width() / 2 - 135, scene()->height() / 2 - 20);
    }
}

int Health::getHealth(){
    return health;
}
