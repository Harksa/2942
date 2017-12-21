#ifndef ENEMYBLUE_H
#define ENEMYBLUE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include "enemy_firing.h"

/**
 * @brief Classe de l'ennemi bleu.
 */
class EnemyBlue : public EnemyFiring {
    Q_OBJECT
public:

    /**
     * @brief EnemyBlue Constructeur pour la classe EnemyBlue.
     * @param pos_x Position de départ de l'ennemi (lorsqu'il apparait en haut de l'écran). -1 pour un positionnement aléatoire.
     */
    EnemyBlue(int pos_x = -1);

private slots:
    /**
     * @brief fire Fonction permettant de faire feu.
     */
    void fire();

    /**
     * @brief move Gére le mouvement du vaisseau.
     */
    void move();
};

#endif // ENEMYBLUE_H
