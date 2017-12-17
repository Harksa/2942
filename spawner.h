#ifndef SPAWNER_H
#define SPAWNER_H

#include <QObject>

#include "enemy.h"

class Spawner : public QObject
{
    Q_OBJECT
public:
    explicit Spawner(QObject *parent = nullptr);

    bool canSpawn = true;

signals:

public slots:
    void spawn();
};

#endif // SPAWNER_H
