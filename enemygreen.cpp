#include "enemy.h"
#include "enemygreen.h"

#include "game.h"

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
    destroyWhenOutsideMap();
}
