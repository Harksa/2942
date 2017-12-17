#ifndef SPRITE_H
#define SPRITE_H

#include <QObject>
#include <QMovie>
#include <QGraphicsPixmapItem>
#include <QPixmap>

class Sprite : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Sprite(QString path, int frameRate, QGraphicsItem *parent = 0);
    Sprite(QString path, QGraphicsItem *parent = 0);

protected:
    QMovie * animation;

protected slots:
   void loopAnimation();
};

#endif // SPRITE_H
