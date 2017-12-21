#ifndef POWERUPSCORE_H
#define POWERUPSCORE_H

#include "powerup.h"

/**
 * @brief PowerUp qui permettra d'augmenter le score du joueur.
 */
class ScorePowerUp : public PowerUp {
    Q_OBJECT
public:
    ScorePowerUp(QString path, int frameRate, int value_given, QGraphicsItem *parent = 0);

private:
    void applyPowerUp();
};

#endif // POWERUPSCORE_H
