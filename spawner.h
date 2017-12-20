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
    int quantity;
    int position;

    Wave(TypeEnemy t, int q, int pos) {
       type = t;
       quantity = q;
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

    QTimer * timerSpawnWave;
    QTimer * timerSpawnEnemies;
    int delayBeforeSpawn = 500;         //Optimal pour la taille actuelle des vaisseaux
    int delayBeforeNewVague = 3000;

    int currentWave;
    int enemy_count;

    Enemy *chooseEnemyFromType(TypeEnemy type);

private slots:
    void spawnWave();
    void spawnEnemy();
};

#endif // SPAWNER_H
