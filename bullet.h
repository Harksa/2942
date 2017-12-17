#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Bullet : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Bullet(QGraphicsItem *parent = 0);
    virtual bool CheckCollision(const QGraphicsItem &item) = 0;
	
protected:
    float bulletSpeed = 0.8f;
    int bulletDamage = 1;
	
public slots:
    virtual void move() = 0;
};

#endif // BULLET_H
