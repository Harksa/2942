#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> //rand()

#include "constants.h"
#include "game.h"

extern Game * game;

Enemy::Enemy(): QObject(), QGraphicsPixmapItem(){
    life = 2;
    scoreGiven = 10;
    moveSpeed = 0.5f;

    setPixmap(QPixmap(":/pictures/Images/enemyShip.png"));

    //Random pos.
    int rand_x = rand() % width_scene - pixmap().width();
    if(rand_x < pixmap().width()) rand_x = pixmap().width();
    setPos(rand_x, -pixmap().height());

    TimerAvancer();
}

Enemy::Enemy(int pos_x): QObject(), QGraphicsPixmapItem() {
        setPixmap(QPixmap(":/pictures/Images/enemyShip.png"));

        setPos(pos_x, -pixmap().height());

        TimerAvancer();
}

void Enemy::TimerAvancer() {
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(5);
}

void Enemy::decrementeLife(int damage) {
    life -= damage;

    if(life <= 0) {
        scene()->removeItem(this);
        game->score->increase(scoreGiven);
        delete this;
    }
}

void Enemy::move(){
    setPos(x(), y() + moveSpeed);

    if(pos().y() + pixmap().height() > height_scene + pixmap().height()) {
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}
