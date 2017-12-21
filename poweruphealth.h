#ifndef POWERUPHEALTH_H
#define POWERUPHEALTH_H

#include "powerup.h"

/**
 * @brief PowerUp qui permettra d'augmenter la vie du joueur.
 */
class HealthPowerUp : public PowerUp {
    Q_OBJECT
public:
    HealthPowerUp(QString path, int frameRate, int value_given, QGraphicsItem *parent = 0);

private:
    void applyPowerUp();
};

#endif // POWERUPHEALTH_H
