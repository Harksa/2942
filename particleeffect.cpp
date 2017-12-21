#include "particleeffect.h"

#include <QMovie>
#include <QTimer>
#include <QGraphicsScene>

#include "sprite.h"

ParticleEffect::ParticleEffect(QString path, int frameRate, QGraphicsItem *parent) : Sprite(path, parent) {
    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(animateThenDie()));
    timer->start(frameRate);
}

void ParticleEffect::animateThenDie() {
    Sprite::loopAnimation();

    if(animation->currentFrameNumber() + 1 >= animation->frameCount()) {
        timer->stop();
        scene()->removeItem(this);
        delete this;
    }
}
