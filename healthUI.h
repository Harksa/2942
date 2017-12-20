#ifndef HEALTH_H
#define HEALTH_H

#include <QObject>
#include <QGraphicsTextItem>

/**
 * @brief L'UI représentant la vie du joueur.
 */
class HealthUI: public QGraphicsTextItem{
    Q_OBJECT
public:
    /**
     * @brief HealthUI Constructeur de la classe HealthUI.
     */
    HealthUI(QGraphicsItem * parent = 0);
private:
    /**
     * @brief health La vie du joueur.
     */
    int health;

public slots:
    /**
     * @brief healthChanged Slot permettant le changement de la vie. Elle est incrémentée/décrementé en fonction de i.
     * @param i Incrémente/décremente la vie de i.
     */
    void healthChanged(int i = 1);
};

#endif // HEALTH_H
