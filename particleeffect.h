#ifndef PARTICLEEFFECT_H
#define PARTICLEEFFECT_H

#include <QObject>
#include <QGraphicsPixmapItem>

#include "sprite.h"

class ParticleEffect : public Sprite {
    Q_OBJECT
public:
    ParticleEffect(QString path, int frameRate, QGraphicsItem *parent = 0);

private:
    QTimer * timer;

private slots:
    void loopAnimation();
};

#endif // PARTICLEEFFECT_H
