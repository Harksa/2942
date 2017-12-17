#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Bullet : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Bullet(float speed, int damage, QGraphicsItem *parent = 0);
    virtual bool CheckCollision(const QGraphicsItem &item) = 0;
	
protected:
    float bulletSpeed;
    int bulletDamage;
	
protected slots:
    virtual void move() = 0;
};

#endif // BULLET_H
