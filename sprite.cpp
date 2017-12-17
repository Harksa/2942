#include "sprite.h"

#include <QMovie>
#include <QTimer>

Sprite::Sprite(QString path, int loopTime, QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
    animation = new QMovie(path);

    QTimer * timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(loopAnimation()));
    timer->start(loopTime);
}

void Sprite::loopAnimation() {
    animation->jumpToNextFrame();
    setPixmap(animation->currentPixmap());
}
