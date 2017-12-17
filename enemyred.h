#ifndef ENEMYRED_H
#define ENEMYRED_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

#include "enemy.h"

class EnemyRed : public Enemy {
        Q_OBJECT
public:
    EnemyRed(int pos_x = - 1);

private:
    int gitan = 0;
public slots:
    void move();
};

#endif // ENEMYRED_H
