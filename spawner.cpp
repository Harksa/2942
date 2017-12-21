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

    int line_number = 1;
    while(!stream.atEnd()) {
        line = stream.readLine();
        QStringList list = line.split(",");

        if(list.size() < 3) {
            QMessageBox::information(0, "SPAWNER ERROR", "Wrong number of element in line " + QString::number(line_number) + ". Must be at least 3");
        } else if (list.size() > 4)
             QMessageBox::information(0, "SPAWNER ERROR", "Wrong number of element in line " + QString::number(line_number) + ". Must be less than 4");
        else {

            TypeEnemy type = chooseTypeFromString(list[0]);
            if(type == ERROR)
                QMessageBox::information(0, "SPAWNER ERROR", "Type not recognized : " + list[0] + " at line " + QString::number(line_number));

            int number_to_spawn = list[1].toInt();
            int pos_x = list[2].toInt();
            int delay;

            if(list.size() > 3) {
                delay = list[3].toInt();
            } else {
                delay = defaultDelayBeforeNewWave;
            }

            if((number_to_spawn + 1) * delayBeforeSpawn > delay) {
                 QMessageBox::information(0, "SPAWNER ERROR", "Quantity of ennemy exceeded for this current wave at line " + QString::number(line_number) + ". Must be less than " + QString::number(delay / delayBeforeSpawn) + ".");
            }

            if(list.size() < 3) {
                Wave w(type, number_to_spawn, pos_x);
                w.delayBeforeNextWave = delay;
                waves.push_back(w);
            } else {
                Wave w(type, number_to_spawn, pos_x, delay);
                waves.push_back(w);
            }

        }

        line_number++;
    }

    file.close();
}

void Spawner::startSpawning() {
    currentWave = -1;
    timerSpawnWave = new QTimer();
    connect(timerSpawnWave,SIGNAL(timeout()),this,SLOT(spawnWave()));
    timerSpawnWave->start(defaultDelayBeforeNewWave);
}

void Spawner::spawnWave() {
    currentWave++;
    qDebug() << "Spawnwave : " + QString::number(currentWave);

    if(currentWave < waves.size())
        timerSpawnWave->setInterval(waves[currentWave].delayBeforeNextWave);

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
    qDebug() << "Spawnenemy : " + QString::number(enemy_count);
    if(enemy_count < waves[currentWave].quantity) {
        Enemy * enemy = chooseEnemyFromType(waves[currentWave].type);
        game->scene->addItem(enemy);
    } else {
        timerSpawnEnemies->stop();
    }
}

TypeEnemy Spawner::chooseTypeFromString(QString string) {
    TypeEnemy type;
    if(string == "Red")
        type = RED;
    else if(string == "Green")
        type = GREEN;
    else
        type = ERROR;

    return type;
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



