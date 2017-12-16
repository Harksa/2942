#include "enemy.h"
#include "enemygreen.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> //rand()

#include "game.h"
#include "constants.h"

extern Game * game;

EnemyGreen::EnemyGreen(int pos_x) : Enemy(pos_x){
    life = 2;
    scoreGiven = 10;
    moveSpeed = 0.5f;

    setPixmap(QPixmap(":/pictures/Images/enemyShip.png"));
    spawn(pos_x);
}

void EnemyGreen::move(){
    setPos(x(), y() + moveSpeed);

    if(pos().y() + pixmap().height() > height_scene + pixmap().height()) {
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}
