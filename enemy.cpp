#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> //rand()

#include "constants.h"
#include "game.h"

extern Game * game;

Enemy::Enemy(): QObject(), QGraphicsPixmapItem(){
    //Random pos.
    int rand_x = rand() % width_scene - 100;
    if(rand_x < 100) rand_x = 100;
    setPos(rand_x,0);

    setPixmap(QPixmap(":/pictures/Images/enemyShip.png"));

    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(5);
}

void Enemy::move(){
    setPos(x(), y() + 0.5f);

    if(pos().y() + pixmap().height() > height_scene + 100) {
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}
