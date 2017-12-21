#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> //rand()

#include "constants.h"
#include "game.h"
#include "particleeffect.h"

#include "powerup.h"
#include "poweruphealth.h"
#include "powerupscore.h"

extern Game * game;

Enemy::Enemy(int pos_x): QObject(), QGraphicsPixmapItem() {
    Q_UNUSED(pos_x);
}

void Enemy::TimerAvancer() {
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(5);
}


void Enemy::DestroyWhenContactWithPlayer() {
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for(int i = 0 ; i < colliding_items.size() ; i++) {
        //Si collision avec object de type Enemy
        if(checkCollisionWithPlayer(*(colliding_items[i]))) {
            dynamic_cast<Player*>(colliding_items[i])->decreaseHealth();
            explode();

            return; //Ne pas continuer le code si collision.
        }
    }
}

void Enemy::decrementeLife(int damage) {
    life -= damage;

    if(life <= 0) {
        if(game->getOnGoing()){
			game->score->increase(scoreGiven);
		}
        explode();
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
        scene()->removeItem(this);
        delete this;
    }
}

bool Enemy::checkCollisionWithPlayer(const QGraphicsItem &item){
    if(typeid(item) == typeid(Player))
        return true;

    return false;
}

void Enemy::explode(){
    spawnPowerUp();

    ParticleEffect * particle = new ParticleEffect(":/pictures/Images/explosion.gif", 50);
    particle->setPos(x() + pixmap().width() / 2 - particle->pixmap().width() / 2, y() + pixmap().height() / 2);
    scene()->addItem(particle);

    scene()->removeItem(this);
    delete this;
}

void Enemy::spawnPowerUp(){
    int r = rand() % 10;

    if(r > 2) return;
    else {
        r = rand() % 10;
        PowerUp * powerUp;
        if(r < 5) {
           powerUp = new HealthPowerUp(":/pictures/Images/powerup_life.gif", 50, 1);
        } else {
           powerUp = new ScorePowerUp(":/pictures/Images/powerup_score.gif", 50, 30);
        }
        powerUp->setPos(x() + pixmap().width() / 2, y() + pixmap().height() / 2);
        scene()->addItem(powerUp);
    }
}
