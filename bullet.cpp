#include <QTimer>
#include <QGraphicsScene>
#include <QList>

#include "bullet.h"
#include "enemy.h"

#include "game.h"
extern Game * game;

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent) {
    setPixmap(QPixmap(":/pictures/Images/laserGreen.png"));

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(1);
}

void Bullet::move() {
    //Gérer collision avec ennemis.
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for(int i = 0 ; i < colliding_items.size() ; i++) {
        //Si collision avec object de type Enemy
        if(typeid(*(colliding_items[i])) == typeid(Enemy)) {
            //Rajouter le score avant la suppression.
            game->score->increase();

            //Destruction des deux objets.
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return; //Ne pas continuer le code si collision.
        }
    }

    setPos(x(), y() - bulletSpeed);

    if(pos().y() < 0 - pixmap().height()) {
        scene()->removeItem(this);
        delete this;
    }
}
