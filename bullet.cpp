#include <QTimer>
#include <QGraphicsScene>
#include <QList>

#include "bullet.h"
#include "enemy.h"

#include "game.h"
extern Game * game;

Bullet::Bullet(float speed, int damage, QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent) {
    bulletSpeed = speed;
    bulletDamage = damage;

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(1);
}
