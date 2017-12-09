#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class Enemy : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy();
    Enemy(int pos_x);

    void decrementeLife(int damage);
    int getLife() const {return life;}
    int getScore() const {return scoreGiven;}
private:
    void TimerAvancer();

protected:
    int life;
    float moveSpeed;
    int scoreGiven;
public slots:
    void move();
};

#endif // ENEMY_H
