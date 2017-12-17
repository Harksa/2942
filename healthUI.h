#ifndef HEALTH_H
#define HEALTH_H

#include <QObject>
#include <QGraphicsTextItem>

class HealthUI: public QGraphicsTextItem{
    Q_OBJECT
public:
    HealthUI(QGraphicsItem * parent = 0);
    //void decrease();
    int getHealth();
private:
    int health;

public slots:
    void healthChanged(int i = 1);
};

#endif // HEALTH_H
