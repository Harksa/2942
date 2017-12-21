#include "poweruphealth.h"
#include "powerup.h"
#include "game.h"

extern Game * game;

HealthPowerUp::HealthPowerUp(QString path, int frameRate, int value_given, QGraphicsItem *parent) : PowerUp(path, frameRate, value_given, parent) {

}

void HealthPowerUp::applyPowerUp() {
    game->player->increaseHealth(value);
}
