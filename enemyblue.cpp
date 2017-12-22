#include "enemyblue.h"

#include <QGraphicsScene>

#include "bulletenemy.h"
#include "game.h"

extern Game * game;

EnemyBlue::EnemyBlue(int pos_x) : EnemyFiring(pos_x){
    life = 3;
    scoreGiven = 20;
    moveSpeed = 0.6f;

    fireRate = 500;
    bulletDamage = 1;
    bulletSpeed = 0.5f;

    setPixmap(QPixmap(":/pictures/Images/enemyShipBlue.png"));
    spawn(pos_x);

    startFiring();
}

void EnemyBlue::fire(){
    EnemyBullet * bullet = new EnemyBullet(bulletSpeed, bulletDamage);
    bullet->setPos(x() + pixmap().width() / 2 - bullet->pixmap().width() / 2, y() + pixmap().height());
    scene()->addItem(bullet);
}

void EnemyBlue::move(){
    setPos(x(), y() + moveSpeed);
    DestroyWhenContactWithPlayer();
    destroyWhenOutsideMap();
}
