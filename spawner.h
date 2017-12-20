#ifndef SPAWNER_H
#define SPAWNER_H

#include <QObject>

#include "enemy.h"

enum TypeEnemy {
    GREEN,
    RED
};

struct Wave {
    TypeEnemy type;
    int number;
    int position;

    Wave(TypeEnemy t, int n, int pos) {
       type = t;
       number = n;
       position = pos;
    }
};

class Spawner : public QObject {
    Q_OBJECT
public:
    explicit Spawner(QObject *parent = nullptr);
    void startSpawning();
private:
    QList<Wave> waves;

    int delayBeforeSpawn = 50;
    int delayBeforeNewVague = 2000;

private slots:
    void spawn();
};

#endif // SPAWNER_H
