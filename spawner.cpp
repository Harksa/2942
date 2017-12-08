#include "spawner.h"

#include "enemy.h"
#include "game.h"

extern Game * game;

Spawner::Spawner(QObject *parent) : QObject(parent)
{

}

void Spawner::spawn() {
    Enemy * enemy = new Enemy();
    game->scene->addItem(enemy);
}
