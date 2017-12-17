#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> //rand()

#include "constants.h"
#include "game.h"
#include "particleeffect.h"

extern Game * game;

Enemy::Enemy(int pos_x): QObject(), QGraphicsPixmapItem() {
    Q_UNUSED(pos_x);
}

void Enemy::TimerAvancer() {
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(5);
}

void Enemy::decrementeLife(int damage) {
    life -= damage;

    if(life <= 0) {
        ParticleEffect * particle = new ParticleEffect(":/pictures/Images/explosion.gif", 50);
        particle->setPos(x(), y());
        scene()->addItem(particle);

        scene()->removeItem(this);
        game->score->increase(scoreGiven);
        delete this;
    }
}

void Enemy::spawn(int i) {
    if(i == -1) {
        int rand_x = rand() % width_scene - pixmap().width();
        if(rand_x < pixmap().width()) rand_x = pixmap().width();
        setPos(rand_x, -pixmap().height());
    } else {
            setPos(i, -pixmap().height());
    }

    TimerAvancer();
}

void Enemy::destroyWhenOutsideMap() {
    if(pos().y() + pixmap().height() > height_scene + pixmap().height()) {
        game->player->decreaseHealth();
        scene()->removeItem(this);
        delete this;
    }
}
