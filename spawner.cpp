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
    /*
    QFile file(":/spawners/vagues.spwn");

    if(!file.exists()) {
        QMessageBox::information(0,"SPAWNER::ERROR::", file.errorString());
    }

    QString line;
    QTextStream stream(&file);

    while(!stream.atEnd()) {
        line = stream.readLine();
        QStringList list = line.split(","); // 3 élements.

        Enemy * enemy;
        if(list[0] == "Red")
            enemy = new EnemyRed();
        else if(list[0] == "Green")
            enemy = new EnemyGreen();

        int number_to_spawn = list[1].toInt();
        int pos_x = list[2].toInt();

        Vague v(enemy, number_to_spawn, pos_x);

        vagues.push_back(v);
    }

    foreach (Vague v, vagues) {
        qDebug() << "loul";
    }
    */

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()), this,SLOT(spawn()));
    timer->start(delayBeforeNewVague);

}

void Spawner::spawn() {
    if(game->getOnGoing()) {
        Enemy * enemy = new EnemyGreen();
        game->scene->addItem(enemy);
    }
}
