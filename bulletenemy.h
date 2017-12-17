#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

#include "bullet.h"

class EnemyBullet : public Bullet {
        Q_OBJECT
public:
    EnemyBullet(QGraphicsItem *parent = 0);
	bool CheckCollision(const QGraphicsItem &item);

public slots:
    void move();
};

#endif // ENEMYBULLET_H

