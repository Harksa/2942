#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QMediaPlayer>
#include <QTimer>
#include <QMovie>

#include "playerstats.h"
#include "sprite.h"

class Player : public Sprite {
    Q_OBJECT
public:
    Player(QGraphicsItem *parent = 0);
    void fire();
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    float posX, posY;               //Position du joueur.
    PlayerStats playerStats;        //Stats du vaisseau du joueur.
    QMediaPlayer * bulletSound;     //Le mediaplayer du tir.
    QSet<int> keysPressed;          //Tableau de clé qui sera utilisé pour la gestion des touches pressées par le joueur.
    QTimer * movements;

    bool canFire;                   //Sert à savoir si le joueur peut tirer ou non.
    bool TurnDone;                  //Bool pour empêcher le changement du sprite en boucle.

    void changeAnimation();

public slots:
    void KeysProcessing();
    void makeFirePossible();
};

#endif // MYRECT_H
