#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class Enemy : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(int pos_x = -1);

    void decrementeLife(int damage);
    int getLife() const {return life;}
    int getScore() const {return scoreGiven;}
private:
    void TimerAvancer();

protected:
    int life;
    float moveSpeed;
    int scoreGiven;

    void spawn(int i = -1);
public slots:
    virtual void move() = 0;
};

#endif // ENEMY_H
