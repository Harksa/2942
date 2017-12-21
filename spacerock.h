#ifndef SPACEROCKS_H
#define SPACEROCKS_H

#include <QObject>
#include "enemy.h"

class SpaceRock : public Enemy{
    Q_OBJECT
public:
    /**
     * @brief SpaceRocks Constructeur de la classe EnemyGreen.
     * @param pos_x Position de départ de l'ennemi (lorsqu'il apparait en haut de l'écran). -1 pour un positionnement aléatoire.
     */
    SpaceRock(int pos_x = -1);

public slots:
    /**
     * @brief move Fonction gérant le mouvement de ce type d'ennemi.
     */
    void move();
};

#endif // SPACEROCKS_H
