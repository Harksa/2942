#include "enemy.h"
#include "enemyred.h"
#include <cmath>

EnemyRed::EnemyRed(int pos_x) : Enemy(pos_x){
    life = 2;
    scoreGiven = 15;
    moveSpeed = 0.6f;

    setPixmap(QPixmap(":/pictures/Images/enemyShipRed.png"));
    spawn(pos_x);
}

void EnemyRed::move() {
    float radius{1.2f};
    setPos(sin((float) time++ / 100.0f) * radius + x(), y() + moveSpeed);
    DestroyWhenContactWithPlayer();
    destroyWhenOutsideMap();
}
