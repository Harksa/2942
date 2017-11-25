#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsScene>

#include "Player.h"
#include "bullet.h"
#include "constants.h"
#include "enemy.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    bulletSound = new QMediaPlayer(this);
    bulletSound->setMedia(QUrl("qrc:/sounds/Sounds/laser.mp3"));

    setPixmap(QPixmap(":/pictures/Images/player.png"));
}

void Player::keyPressEvent(QKeyEvent *event){

    //Mouvements du joueur.
    if(event->key() == Qt::Key_Left) {
        if(pos().x() > 0)
            setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right) {
        if(pos().x() + pixmap().width() < width_scene)
            setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Up) {
        if(pos().y() > 0)
            setPos(x(),y()-10);
    }
    else if (event->key() == Qt::Key_Down) {
        if(pos().y() + pixmap().height() < height_scene)
            setPos(x(),y()+10);
    }

    //Projectile.
    if(event->key() == Qt::Key_Space) {
        Bullet * bullet = new Bullet();
        bullet->setPos(x() + pixmap().width() / 2 - 5, y() - pixmap().height() / 2);
        scene()->addItem(bullet);

        //Remettre le son à 0 s'il est joué.
        if(bulletSound->state() == QMediaPlayer::PlayingState) {
            bulletSound->setPosition(0);
        }
        else if (bulletSound->state() == QMediaPlayer::StoppedState) {
         bulletSound->play();
        }
    }
}

void Player::spawn() {
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
