#include "sprite.h"

#include <QMovie>
#include <QTimer>

Sprite::Sprite(QString path, int frameRate, QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
    animation = new QMovie(path);

    QTimer * timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(loopAnimation()));
    timer->start(frameRate);
}

Sprite::Sprite(QString path, QGraphicsItem *parent) :  QGraphicsPixmapItem(parent) {
    animation = new QMovie(path);
}

void Sprite::loopAnimation() {
    animation->jumpToNextFrame();
    setPixmap(animation->currentPixmap());
}
