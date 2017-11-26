#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QMediaPlayer>
#include <QTimer>

#include "playerstats.h"

class Player : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Player(QGraphicsItem *parent = 0);
    void fire();
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent *event);
    void KeysProcessing(QSet<int> keys);

private:
    QMediaPlayer * bulletSound;
    QSet<int> keysPressed;
    bool m_bFirstrealase;

    PlayerStats playerStats;
public slots:
    void spawn();
};

#endif // MYRECT_H
