#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>
#include <QTimer>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <QMovie>

#include "Player.h"
#include "bullet.h"
#include "constants.h"
#include "enemy.h"


Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    bulletSound = new QMediaPlayer(this);
    bulletSound->setMedia(QUrl("qrc:/sounds/Sounds/laser.mp3"));

    movie = new QMovie(":/pictures/Images/ship.gif");
    setPixmap(movie->currentPixmap());

    posX = width_scene / 2 - pixmap().width() / 2, posY = height_scene - 200;

    setPos(posX, posY);

    QTimer * movements = new QTimer;
    connect(movements, SIGNAL(timeout()), this, SLOT(KeysProcessing()));
    movements->start(1);

    QTimer * fire = new QTimer;
    connect(fire, SIGNAL(timeout()), this, SLOT(makeFirePossible()));
    fire->start(playerStats.fireDelay);


    QTimer * animation = new QTimer;
    connect(animation, SIGNAL(timeout()), this, SLOT(changeAnimation()));
    animation->start(100);

    canFire = true;
}


void Player::fire(){
    canFire = false;
    Bullet * bullet = new Bullet();
    bullet->setPos(x() + pixmap().width() / 2 - bullet->pixmap().width() / 2, y() - pixmap().height() / 2);
    scene()->addItem(bullet);

    //Remettre le son à 0 s'il est joué.
    if(bulletSound->state() == QMediaPlayer::PlayingState) {
        bulletSound->setPosition(0);
    }
    else if (bulletSound->state() == QMediaPlayer::StoppedState) {
        bulletSound->play();
    }
}

void Player::keyPressEvent(QKeyEvent *event){
    keysPressed.insert(event->key());
}

void Player::keyReleaseEvent(QKeyEvent *event){
    keysPressed.remove(event->key());
}

void Player::KeysProcessing(){

    //Mouvements.
    if(keysPressed.contains(Qt::Key_Left)) {
        if(pos().x() > 0) {
            setPixmap(movie->currentPixmap());
            posX -= playerStats.playerSpeed;
        }
    }
    if (keysPressed.contains(Qt::Key_Right)) {
        if(pos().x() + pixmap().width() < width_scene) {
            setPixmap(movie->currentPixmap());
            posX += playerStats.playerSpeed;
        }
    }
    if (keysPressed.contains(Qt::Key_Up)) {
        if(pos().y() > 0)
            posY -= playerStats.playerSpeed;
    }
    if (keysPressed.contains(Qt::Key_Down)) {
        if(pos().y() + pixmap().height() < height_scene)
            posY += playerStats.playerSpeed;
    }

    //Si le joueur ne bouge pas à gauche ou droite, remettre l'image d'origine.
    if(!keysPressed.contains(Qt::Key_Left) && !keysPressed.contains(Qt::Key_Right)) {
        setPixmap(movie->currentPixmap());
    }

    //Projectiles.
    if(keysPressed.contains(Qt::Key_Space)) {
        if(canFire)
            fire();
    }

    setPos(posX, posY);
}

void Player::makeFirePossible() {
    canFire = true;
}

void Player::changeAnimation(){
    movie->jumpToNextFrame();
    setPixmap(movie->currentPixmap());
}
