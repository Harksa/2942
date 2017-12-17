#ifndef ENEMY_FIRING_H
#define ENEMY_FIRING_H

#include <QObject>

#include "enemy.h"

class EnemyFiring : public Enemy {
    Q_OBJECT
public:
    EnemyFiring(int pos_x = -1);

protected:
    int fireRate;
    float bulletSpeed;
    int bulletDamage;

protected slots:
    virtual void fire() = 0;
};

#endif // ENEMY_FIRING_H
