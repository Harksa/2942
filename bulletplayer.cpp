#include "bullet.h"
#include "bulletplayer.h"

#include "game.h"
#include "enemygreen.h"
#include "enemyred.h"
#include "spacerock.h"

extern Game * game;

PlayerBullet::PlayerBullet(float speed, int damages, QGraphicsItem *parent): Bullet(speed, damages, parent){
    setPixmap(QPixmap(":/pictures/Images/laserGreen.png"));
}

void PlayerBullet::move() {
    //Gérer collision avec ennemis.
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for(int i = 0 ; i < colliding_items.size() ; i++) {
        //Si collision avec object de type Enemy
        if(CheckCollision(*(colliding_items[i]))) {
            dynamic_cast<Enemy*>(colliding_items[i])->decrementeLife(bulletDamage);
            scene()->removeItem(this);
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

bool PlayerBullet::CheckCollision(const QGraphicsItem &item) {
    if(typeid(item) == typeid(EnemyGreen) || typeid(item) == typeid(EnemyRed) || typeid(item) == typeid(SpaceRock))
        return true;

    return false;
}

