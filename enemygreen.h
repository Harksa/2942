#ifndef ENEMYGREEN_H
#define ENEMYGREEN_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

#include "enemy.h"

/**
 * @brief Ennemi Vert : Le plus basique de tous les ennemis.
 */
class EnemyGreen : public Enemy {
        Q_OBJECT
public:
    /**
     * @brief EnemyGreen Constructeur de la classe EnemyGreen.
     * @param pos_x Position de départ de l'ennemi (lorsqu'il apparait en haut de l'écran). -1 pour un positionnement aléatoire.
     */
    EnemyGreen(int pos_x = -1);

public slots:
    /**
     * @brief move Fonction gérant le mouvement de ce type d'ennemi.
     */
    void move();
};

#endif // ENEMYGREEN_H
