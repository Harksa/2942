#ifndef PLAYERBULLET_H
#define PLAYERBULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

#include "bullet.h"

class PlayerBullet : public Bullet {
        Q_OBJECT
public:
    PlayerBullet(QGraphicsItem *parent = 0);
	bool CheckCollision(const QGraphicsItem &item);
	
public slots:
    void move();
};

#endif // PLAYERBULLET_H
