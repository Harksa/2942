#ifndef SPAWNER_H
#define SPAWNER_H

#include <QObject>

#include "enemy.h"

struct Vague {
    Enemy * enemy;
    int number;
    int position;

    Vague(Enemy * e, int n, int pos) {
       enemy = e;
       number = n;
       position = pos;
    }
};

class Spawner : public QObject {
    Q_OBJECT
public:
    explicit Spawner(QObject *parent = nullptr);

private:
    QList<Vague> vagues;

    int delayBeforeSpawn = 50;
    int delayBeforeNewVague = 5000;

public slots:
    void spawn();
};

#endif // SPAWNER_H
