#ifndef ENEMYRED_H
#define ENEMYRED_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

#include "enemy.h"

/**
 * @brief Ennemi Rouge : Un peu plus coriace que l'ennemi vert.
 */
class EnemyRed : public Enemy {
        Q_OBJECT
public:
    /**
     * @brief EnemyRed Constructeur de la classe EnemyRed.
     * @param pos_x Position de départ de l'ennemi (lorsqu'il apparait en haut de l'écran). -1 pour un positionnement aléatoire.
     */
    EnemyRed(int pos_x = - 1);
    bool isMoveSin;
private:
    /**
     * @brief time paramètre permettant de faire un mouvement sinusoidale.
     */
    int time = 0;
public slots:
    /**
     * @brief move Fonction gérant le mouvement de ce type d'ennemi.
     */
    void move();
};

#endif // ENEMYRED_H
