#ifndef SPAWNER_H
#define SPAWNER_H

#include <QObject>

class Spawner : public QObject
{
    Q_OBJECT
public:
    explicit Spawner(QObject *parent = nullptr);

signals:

public slots:
    void spawn();
};

#endif // SPAWNER_H
