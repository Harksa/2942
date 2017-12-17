#include "health.h"

#include <QFont>
#include <QFontDatabase>

Health::Health(QGraphicsItem *parent){
    setZValue(1);

    health = 3;

    setPlainText("Health : " + QString::number(health));
    setDefaultTextColor(Qt::red);

    QString font = QFontDatabase::applicationFontFamilies(0).at(0);

    setFont(QFont(font));

    Q_UNUSED(parent);
}

void Health::decrease(){
    health--;
    setPlainText("Health : " + QString::number(health));
}

int Health::getHealth(){
    return health;
}
