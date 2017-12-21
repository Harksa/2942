#ifndef PARTICLEEFFECT_H
#define PARTICLEEFFECT_H

#include <QObject>
#include <QGraphicsPixmapItem>

#include "sprite.h"

/**
 * @brief Permet d'afficher un sprite qui sera tué à la fin de l'animation.
 */
class ParticleEffect : public Sprite {
    Q_OBJECT
public:
    /**
     * @brief ParticleEffect Constructeur pour la classe.
     * @param path Le chemin du sprite.
     * @param frameRate Le framerate du sprite.
     */
    ParticleEffect(QString path, int frameRate, QGraphicsItem *parent = 0);

private:
    /**
     * @brief timer Timer pour pouvoir gérer le changement de framerate.
     */
    QTimer * timer;

private slots:
    /**
     * @brief animateThenDie Permet de jouer le sprite et de le détruire à la fin de l'animation.
     */
    void animateThenDie();
};

#endif // PARTICLEEFFECT_H
