#include "spawner.h"

#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QStringList>
#include <QTimer>
#include <QDebug>

#include "enemy.h"
#include "enemygreen.h"
#include "enemyred.h"
#include "game.h"

extern Game * game;

Spawner::Spawner(QObject *parent) : QObject(parent){

    QFile file(":/spawners/vagues.spwn");

    if(!file.exists()) {
        QMessageBox::information(0,"SPAWNER ERROR", file.errorString());
    }

    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QString line;
    QTextStream stream(&file);

    int i = 1;
    while(!stream.atEnd()) {
        line = stream.readLine();
        QStringList list = line.split(","); // 3 élements.

        TypeEnemy type;
        if(list[0] == "Red")
            type = RED;
        else if(list[0] == "Green")
            type = GREEN;
        else
            QMessageBox::information(0, "SPAWNER ERROR", "Type not recognized : " + list[0] + " at line " + QString::number(i));

        int number_to_spawn = list[1].toInt();
        int pos_x = list[2].toInt();

        Wave w(type, number_to_spawn, pos_x);

        waves.push_back(w);
        i++;
    }

   file.close();
}

void Spawner::startSpawning() {
    currentWave = -1;
    timerSpawnWave = new QTimer();
    connect(timerSpawnWave,SIGNAL(timeout()),this,SLOT(spawnWave()));
    timerSpawnWave->start(delayBeforeNewVague);
}


void Spawner::spawnWave() {
    currentWave++;
    if(currentWave < waves.size()) {
        enemy_count  = -1;
        timerSpawnEnemies = new QTimer();
        connect(timerSpawnEnemies,SIGNAL(timeout()),this,SLOT(spawnEnemy()));
        timerSpawnEnemies->start(delayBeforeSpawn);
    } else {
        timerSpawnWave->stop();
    }
}

void Spawner::spawnEnemy(){
    enemy_count++;
    if(enemy_count < waves[currentWave].quantity) {
        Enemy * enemy = chooseEnemyFromType(waves[currentWave].type);
        game->scene->addItem(enemy);
    } else {
        timerSpawnEnemies->stop();
    }
}

Enemy * Spawner::chooseEnemyFromType(TypeEnemy type){
    int pos = waves[currentWave].position;
    switch (type) {
    case RED:
        return new EnemyRed(pos);
        break;
    case GREEN:
        return new EnemyGreen(pos);
    default:
        break;
    }

    return nullptr;
}



