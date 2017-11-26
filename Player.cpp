#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsScene>
#include <QDebug>

#include "Player.h"
#include "bullet.h"
#include "constants.h"
#include "enemy.h"


Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    this->installEventFilter(this);

    bulletSound = new QMediaPlayer(this);
    bulletSound->setMedia(QUrl("qrc:/sounds/Sounds/laser.mp3"));

    setPixmap(QPixmap(":/pictures/Images/player.png"));
}


void Player::fire(){
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

void Player::keyPressEvent(QKeyEvent *event){

    m_bFirstrealase = true;
    keysPressed.insert(event->key());

    /*
    //Mouvements du joueur.
    if(event->key() == Qt::Key_Left) {
        qDebug() << "loul left";
        if(pos().x() > 0)
            setPos(x()- playerStats.playerSpeed,y());
    }
    if (event->key() == Qt::Key_Right) {
        if(pos().x() + pixmap().width() < width_scene)
            setPos(x()+ playerStats.playerSpeed,y());
    }
    if (event->key() == Qt::Key_Up) {
        qDebug() << "loul haut";
        if(pos().y() > 0)
            setPos(x(),y()- playerStats.playerSpeed);
    }
    if (event->key() == Qt::Key_Down) {
        qDebug() << "loul bas";
        if(pos().y() + pixmap().height() < height_scene)
            setPos(x(),y()+ playerStats.playerSpeed);
    }

    //Projectile.
    if(event->key() == Qt::Key_Space) {
        fire();
    }
    */
}

void Player::keyReleaseEvent(QKeyEvent *event){
    if(m_bFirstrealase){
        KeysProcessing(keysPressed);
    }

    m_bFirstrealase = false;
    keysPressed.remove(event->key());
}

void Player::KeysProcessing(QSet<int> keys){

    if(keys.contains(Qt::Key_Left)) {
        if(pos().x() > 0)
            setPos(x()- playerStats.playerSpeed,y());
    }
    if (keys.contains(Qt::Key_Right)) {
        if(pos().x() + pixmap().width() < width_scene)
            setPos(x()+ playerStats.playerSpeed,y());
    }
    if (keys.contains(Qt::Key_Up)) {
        if(pos().y() > 0)
            setPos(x(),y()- playerStats.playerSpeed);
    }
    if (keys.contains(Qt::Key_Down)) {
        if(pos().y() + pixmap().height() < height_scene)
            setPos(x(),y()+ playerStats.playerSpeed);
    }

    //Projectile.
    if(keys.contains(Qt::Key_Space)) {
        fire();
    }
}

void Player::spawn() {
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
