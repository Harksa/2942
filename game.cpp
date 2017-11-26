#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QMediaPlayer>
#include <QImage>
#include <QBrush>

#include "Enemy.h"
#include "constants.h"

Game::Game(QWidget *parent){
    //Création de la scène.
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,width_scene,height_scene);

    //Background.
    scene->setBackgroundBrush(QBrush(QImage(":/pictures/Images/Background/starBackground.png")));

    //Rajout de la scène et paramétrages.
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(width_scene,height_scene);

    //Création du joueur.
    player = new Player();
    player->setPos(width_scene / 2 ,height_scene - 200);
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
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    //Musique de background.
    QMediaPlayer * music = new QMediaPlayer(this);
    music->setMedia(QUrl("qrc:/musics/Musics/level1.mp3"));
    music->play();

    show();
}
