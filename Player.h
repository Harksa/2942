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

/**
 * @brief La classe permettant de gérer le joueur.
 */
class Player : public Sprite {
    Q_OBJECT
public:
    /**
     * @brief Player Constructeur pour le joueur.
     */
    Player(QGraphicsItem *parent = 0);

    /**
     * @brief fire Permet de faire tirer le vaisseau du joueur.
     */
    void fire();

    /**
     * @brief keyPressEvent Gére les entrées de clavier.
     * @param event L'entrée du clavier.
     */
    void keyPressEvent(QKeyEvent * event);

    /**
     * @brief keyReleaseEvent Gére les relachements des touches du clavier.
     * @param event La touche relachée.
     */
    void keyReleaseEvent(QKeyEvent *event);

    /**
     * @brief decreaseHealth Diminue la vie du joueur.
     * @param i La vie perdue.
     */
    void decreaseHealth(int i = 1);

    /**
     * @brief increaseHealth Augmente la vie du joueur.
     * @param i La vie gagné.
     */
    void increaseHealth(int i = 1);

    /**
     * @brief startBlink Fait clignoter le joueur lorsqu'il se fait toucher.
     */
    void startBlink();

signals:
    /**
     * @brief healthDecreased Signal permettant de mettre à jour la vie du joueur sur l'UI.
     * @param i la quantité de vie perdue.
     */
    void healthChanged(int i = 1);

private:

    /**
     * @brief normal Animation du joueur lorsqu'il ne change pas de direction.
     * @brief left Animation lorsqu'il se dirige vers la gauche.
     * @brief right Animation lorsqu'il se dirige vers la droite.
     * @brief blinking Animation lorsque le joueur se fait toucher.
     * @brief blinking_left Animation lorsque le joueur se fait toucher et se déplace vers la gauche.
     * @brief blinking_right Animation lorsque le joueur se fait toucheret se déplace vers la droite.
     */
    QMovie *normal, *left, *right, *blinking, *blinking_left, * blinking_right;

    /**
     * @brief posX La position X du joueur.
     * @brief posY La position Y du joueur.
     */
    float posX, posY;

    /**
     * @brief playerStats Les statistiques du vaisseau du joueur.
     */
    PlayerStats playerStats;

    /**
     * @brief isInvulnerable Est-ce que le joueur est invulnérable.
     */
    bool isInvulnerable;

    /**
     * @brief bulletSound Le son du bullet du joueur.
     */
    QMediaPlayer * bulletSound;

    /**
     * @brief keysPressed Tableau de clé qui sera utilisé pour la gestion des touches pressées par le joueur.
     */
    QSet<int> keysPressed;

    /**
     * @brief bulletSpeed La vitesse des des balles.
     */
    float bulletSpeed = 0.8f;

    /**
     * @brief bulletDamages Les dégats causés par les balles.
     */
    int bulletDamages = 1;

    /**
     * @brief canFire Sert à savoir si le joueur peut tirer ou non.
     */
    bool canFire;

    /**
     * @brief TurnDone Bool pour empêcher le changement du sprite en boucle lorsqu'il se déplace.
     */
    bool TurnDone;

    /**
     * @brief changeAnimation Permet de changer l'animation du vaisseau en fonction de la direction que le joueur prend.
     */
    void changeAnimation();

private slots:
    /**
     * @brief KeysProcessing Gére les entrées clavier du joueur en fonction du tableau de touches pressées.
     */
    void KeysProcessing();

    /**
     * @brief makeFirePossible Permet au joueur de tirer à nouveau en changeant le boolean canFire à true.
     */
    void makeFirePossible();

    /**
     * @brief stopBlink Fait arrêter de clignoter le joueur.
     */
    void stopBlink();
};

#endif // MYRECT_H
