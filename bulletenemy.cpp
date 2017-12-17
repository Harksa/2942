#include "bullet.h"
#include "bulletenemy.h"

#include "game.h"
#include "Player.h"

extern Game * game;
	
EnemyBullet::EnemyBullet(QGraphicsItem *parent): Bullet(parent) {
    setPixmap(QPixmap(":/pictures/Images/laserRed.png"));
}

void EnemyBullet::move() {
    //Gérer collision avec ennemis.
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for(int i = 0 ; i < colliding_items.size() ; i++) {
        //Si collision avec object de type Enemy
        if(CheckCollision(*(colliding_items[i]))) {
            game->player->decreaseHealth();
            scene()->removeItem(this);
            delete this;
            return; //Ne pas continuer le code si collision.
        }
    }

    setPos(x(), y() + bulletSpeed);

    if(pos().y() > scene()->height() + pixmap().height()) {
        scene()->removeItem(this);
        delete this;
    }
}


bool EnemyBullet::CheckCollision(const QGraphicsItem &item) {
    if(typeid(item) == typeid(Player))
        return true;

    return false;
}