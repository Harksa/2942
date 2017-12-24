#include <QDebug>
#include <QKeyEvent>
#include <QTimer>

#include "Player.h"
#include "bulletplayer.h"
#include "constants.h"
#include "game.h"

extern Game * game;

Player::Player(QGraphicsItem *parent): Sprite(":/pictures/Images/ship.gif", 10, parent){
    //Son du canon
    bulletSound = new QMediaPlayer(this);
    bulletSound->setMedia(QUrl("qrc:/sounds/Sounds/laser.mp3"));

    //Attribution des animations
    normal = animation;
    left = new QMovie(":/pictures/Images/shipLeft.gif");
    right = new QMovie(":/pictures/Images/shipRight.gif");
    blinking = new QMovie(":/pictures/Images/ship_blink.gif");

    //Spawn
    setPixmap(animation->currentPixmap());
    posX = width_scene / 2 - 20, posY = height_scene - 200;
    setPos(posX, posY);

    QTimer * movements = new QTimer;
    connect(movements, SIGNAL(timeout()), this, SLOT(KeysProcessing()));
    movements->start(1);

    QTimer * fire = new QTimer;
    connect(fire, SIGNAL(timeout()), this, SLOT(makeFirePossible()));
    fire->start(playerStats.fireDelay);

    bulletSpeed = 0.8f;
    bulletDamages = 1;

    canFire = true;
    isInvulnerable = false;
}


void Player::fire(){
    canFire = false;
    PlayerBullet * bullet = new PlayerBullet(bulletSpeed, bulletDamages);
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
    if(playerStats.health > 0) {
        changeAnimation();

        //Mouvements.
        if(keysPressed.contains(Qt::Key_Left)) {
            if(pos().x() > 0) {
                posX -= playerStats.playerSpeed;
            }
        }
        if (keysPressed.contains(Qt::Key_Right)) {
            if(pos().x() + pixmap().width() < width_scene) {
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

        //Projectiles.
        if(keysPressed.contains(Qt::Key_Space)) {
            if(canFire)
                fire();
        }

        setPos(posX, posY);
    }
}

void Player::decreaseHealth(int i) {
    if(!isInvulnerable) {
        isInvulnerable = true;
        playerStats.health -= i;
        startBlink();
        emit healthChanged(-i);
    }
}

void Player::increaseHealth(int i){
    playerStats.health += i;
    emit healthChanged(i);
}

void Player::startBlink(){
    animation = blinking;
    QTimer::singleShot(1000, this, SLOT(stopBlink()));
}

void Player::changeAnimation(){
    if(keysPressed.contains(Qt::Key_Left)) {
        if(!TurnDone) {
            animation = left;
            TurnDone = true;
        }
    }

    if (keysPressed.contains(Qt::Key_Right)) {
        if(!TurnDone) {
            animation = right;
            TurnDone = true;
        }
    }

    if(!keysPressed.contains(Qt::Key_Left) && !keysPressed.contains(Qt::Key_Right)) {
        if(TurnDone) {
            animation = normal;
            TurnDone = false;
        }
    }

    setPixmap(animation->currentPixmap());
}

void Player::makeFirePossible() {
    canFire = true;
}

void Player::stopBlink(){
    animation = normal;
    isInvulnerable = false;
}
