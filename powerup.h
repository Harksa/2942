#ifndef POWERUP_H
#define POWERUP_H

#include <QObject>

#include "sprite.h"

/**
 * @brief Classe abstraite pour le powerUp
 */
class PowerUp : public Sprite {
    Q_OBJECT
public:
    /**
     * @brief PowerUp Constructeur pour la classe PowerUp.
     * @param path Le chemin vers le sprite.
     * @param frameRate Le framerate du sprite.
     * @param value_given Le nombre de points/vie/dégats sup/etc donnée par le powerup.
     */
    PowerUp(QString path, int frameRate, int value_given, QGraphicsItem *parent = 0);

protected:

    /**
     * @brief value La valeur donnée par le powerup.
     */
    int value;

    /**
     * @brief moveSpeed La vitesse de déplacement du powerup.
     */
    int moveSpeed = 0.5f;

    /**
     * @brief timeBeforeDestruction Temps avant que le powerup ne disparaisse.
     */
    int timeBeforeDestruction = 2500;

    /**
     * @brief applyPowerUp Applique le powerUp au joueur.
     */
    virtual void applyPowerUp() = 0;

    /**
     * @brief destroyWhenOutsideMap Détruit le powerup lorsqu'il est en dehors de l'aire de jeu.
     */
    void destroyWhenOutsideMap();

    /**
     * @brief checkIfCollisionWithPlayer regarde les collisions entre le vaisseau et celui du joueur.
     * @param item L'objet rentré en collision avec.
     * @return Vrai si collision, faux sinon.
     */
    bool checkIfCollisionWithPlayer(const QGraphicsItem &item);

protected slots:

    /**
     * @brief deleteAfterTime Détruit le powerUp après un certain temps.
     */
    void deleteAfterTime();

    /**
     * @brief checkCollisions Regarde les collisions entre le powerup et les autres objets.
     */
    void checkCollisions();

};

#endif // POWERUP_H
