#ifndef ENEMY_FIRING_H
#define ENEMY_FIRING_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

#include "enemy.h"

/**
 * @brief Un ennemi qui peut tirer.
 */
class EnemyFiring : public Enemy {
    Q_OBJECT
public:
    /**
     * @brief EnemyFiring Constructeur de la classe.
     * @param pos_x Position initiale du vaisseau. (-1 pour un positionnement aléatoire).
     */
    EnemyFiring(int pos_x = -1);

protected:
    /**
     * @brief fireRate Vitesse d'attaque du vaisseau.
     */
    int fireRate;

    /**
     * @brief bulletSpeed La vitesse à laquelle les balles du vaisseau vont.
     */
    float bulletSpeed;

    /**
     * @brief bulletDamage Les damages causés par le vaisseau.
     */
    int bulletDamage;

    /**
     * @brief startFiring Fonction qui permet commencer à tirer le vaisseau.
     */
    void startFiring();

    /**
     * @brief move
     */
    virtual void move() = 0;

protected slots:

    /**
     * @brief fire Fonction permettant de faire feu.
     */
    virtual void fire() = 0;
};

#endif // ENEMY_FIRING_H
