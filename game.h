#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QFont>
#include <QFontDatabase>
#include <QString>
#include <QTimer>
#include <QImage>
#include <QBrush>
#include <QFileDialog>
#include <QMouseEvent>
#include <QApplication>
#include <QDesktopWidget>

#include <iostream>

#include "Player.h"
#include "score.h"
#include "healthUI.h"
#include "spawner.h"
#include "highscores.h"

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    HealthUI * health;
    Spawner * spawner;
	HighScores * highscores;
	bool onGoing;
	
public :
    void launch_game();
	void game_over();
	QGraphicsTextItem* add_menu(QString texte, int posX, int posY, int fontHeight);
	
	bool getOnGoing();

private:
    void mousePressEvent(QMouseEvent *event);

public slots:
    void restartMusic();

};

#endif // GAME_H
