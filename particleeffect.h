#ifndef PARTICLEEFFECT_H
#define PARTICLEEFFECT_H

#include <QObject>
#include <QGraphicsPixmapItem>

#include "sprite.h"

class ParticleEffect : public Sprite {
    Q_OBJECT
public:
    ParticleEffect();
};

#endif // PARTICLEEFFECT_H
