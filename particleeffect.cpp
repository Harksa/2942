#include "particleeffect.h"

#include <QMovie>
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>

#include "sprite.h"

ParticleEffect::ParticleEffect(QString path, int frameRate, QGraphicsItem *parent) : Sprite(path, parent) {
    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(loopAnimation()));
    timer->start(frameRate);
}

void ParticleEffect::loopAnimation() {
    Sprite::loopAnimation();

    if(animation->currentFrameNumber() + 1 >= animation->frameCount()) {
        timer->stop();
        scene()->removeItem(this);
        delete this;
    }
}
