#include "enemy_firing.h"
#include "enemy.h"

#include <QTimer>

EnemyFiring::EnemyFiring(int pos_x) : Enemy(pos_x) {
    Q_UNUSED(pos_x);
}

void EnemyFiring::startFiring() {
    QTimer * openFire = new QTimer();
    connect(openFire, SIGNAL(timeout()), this, SLOT(fire()));
    openFire->start(fireRate);
}
