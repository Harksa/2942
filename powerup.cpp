#include "powerup.h"

#include <QTimer>
#include <QGraphicsScene>

#include "sprite.h"
#include "constants.h"
#include "player.h"


PowerUp::PowerUp(QString path, int frameRate, int value_given, QGraphicsItem *parent) : Sprite(path, frameRate, parent){
    value = value_given;

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(deleteAfterTime()));
    timer->start(timeBeforeDestruction);

    QTimer * collisions = new QTimer();
    connect(collisions, SIGNAL(timeout()), this, SLOT(checkCollisions()));
    collisions->start(5);

}

void PowerUp::checkCollisions() {
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for(int i = 0 ; i < colliding_items.size() ; i++) {
        if(checkIfCollisionWithPlayer(*(colliding_items[i]))) {
            applyPowerUp();
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
}

bool PowerUp::checkIfCollisionWithPlayer(const QGraphicsItem &item){
    if(typeid(item) == typeid(Player))
        return true;

    return false;
}

void PowerUp::deleteAfterTime(){
    scene()->removeItem(this);
    delete this;
}
