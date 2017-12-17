#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QFontDatabase>

#include "Player.h"
#include "score.h"
#include "healthUI.h"
#include "spawner.h"

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    HealthUI * health;
    Spawner * spawner;

private:
    void mousePressEvent(QMouseEvent *event);

public slots:
    void restartMusic();

};

#endif // GAME_H
