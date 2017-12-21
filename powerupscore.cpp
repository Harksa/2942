#include "powerupscore.h"
#include "game.h"

extern Game * game;

ScorePowerUp::ScorePowerUp(QString path, int frameRate, int value_given, QGraphicsItem *parent) : PowerUp(path, frameRate, value_given, parent) {

}

void ScorePowerUp::applyPowerUp() {
    game->score->increase(value);
}
