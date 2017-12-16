#ifndef ENEMYGREEN_H
#define ENEMYGREEN_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

#include "enemy.h"

class EnemyGreen : public Enemy {
        Q_OBJECT
public:
    EnemyGreen(int pos_x = -1);

public slots:
    void move();
};

#endif // ENEMYGREEN_H
