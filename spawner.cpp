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
        QMessageBox::information(0,"SPAWNER::ERROR::", file.errorString());
    }

    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QString line;
    QTextStream stream(&file);

    while(!stream.atEnd()) {
        line = stream.readLine();
        QStringList list = line.split(","); // 3 élements.

        TypeEnemy type;
        if(list[0] == "Red")
            type = RED;
        else if(list[0] == "Green")
            type = GREEN;

        int number_to_spawn = list[1].toInt();
        int pos_x = list[2].toInt();

        Wave w(type, number_to_spawn, pos_x);

        waves.push_back(w);
    }

   file.close();
}

void Spawner::startSpawning() {
    if(game->getOnGoing()) {
        Enemy * enemy = new EnemyGreen();
        game->scene->addItem(enemy);
    }
}

