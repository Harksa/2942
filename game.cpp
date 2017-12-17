#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QImage>
#include <QBrush>
#include <QFileDialog>
#include <QMouseEvent>
#include <iostream>
#include <QApplication>
#include <QDesktopWidget>

#include "enemy.h"
#include "constants.h"
#include "spawner.h"

Game::Game(QWidget *parent){
    //Création de la scène.
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,width_scene,height_scene);

    //Background.
    QBrush background(QImage(":/pictures/Images/Background/starBackground.png"));
    scene->setBackgroundBrush(background);

    //Rajout de la scène et paramétrages.
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(width_scene,height_scene);

    //Rajouter les polices à la base de fonts.
    QFontDatabase::addApplicationFont(":/fonts/Fonts/venus rising rg.ttf"); // ID : 0

    //Création du joueur.
    player = new Player();
    scene->addItem(player);

    //Focus sur le joueur.
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //Création du score.
    score = new Score();
    scene->addItem(score);

    //Création de la vie.
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    //Spawner d'ennemis.
    spawner = new Spawner();

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),spawner,SLOT(spawn()));
    timer->start(2000);

    //Musique de background.
    QUrl path("qrc:/musics/Musics/level1.mp3");

    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(path);
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer * music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();

    //Placer le jeu au milieu de l'écran.
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width() - this->width()) / 2;
    int y = (screenGeometry.height() - this->height()) / 2;
    this->move(x, y);

    show();

    Q_UNUSED(parent)
}

void Game::mousePressEvent(QMouseEvent *event) {
    player->setFocus();

    Q_UNUSED(event);
}

