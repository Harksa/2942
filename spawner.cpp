#include "spawner.h"

#include "enemy.h"
#include "enemygreen.h"
#include "game.h"

extern Game * game;

Spawner::Spawner(QObject *parent) : QObject(parent)
{

}

void Spawner::spawn() {
    Enemy * enemy = new EnemyGreen();
    game->scene->addItem(enemy);
}
