#include "healthUI.h"

#include <QFont>
#include <QFontDatabase>

#include "game.h"

extern Game * game;

HealthUI::HealthUI(QGraphicsItem *parent){
    setZValue(1);

    health = 3;

    setPlainText("Health : " + QString::number(health));
    setDefaultTextColor(Qt::red);

    QString font = QFontDatabase::applicationFontFamilies(0).at(0);

    setFont(QFont(font));

    Q_UNUSED(parent);
}

void HealthUI::healthChanged(int i){
    if(health > 0)
    health -= i;
    setPlainText("Health : " + QString::number(health));

    if(health <= 0) {
        health = 0;
        if(game->getOnGoing())
		{
			game->game_over();
		}
    }
}
