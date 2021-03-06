#include "enemy.h"
#include "enemygreen.h"

EnemyGreen::EnemyGreen(int pos_x) : Enemy(pos_x){
    life = 1;
    scoreGiven = 10;
    moveSpeed = 0.5f;

    setPixmap(QPixmap(":/pictures/Images/enemyShip.png"));
    spawn(pos_x);
}

void EnemyGreen::move(){
    setPos(x(), y() + moveSpeed);
    DestroyWhenContactWithPlayer();
    destroyWhenOutsideMap();
}
