#ifndef PLAYERBULLET_H
#define PLAYERBULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

#include "bullet.h"

/**
 * @brief Balle du joueur.
 */
class PlayerBullet : public Bullet {
        Q_OBJECT
public:
    /**
     * @brief Bullet Constructeur de la classe PlayerBullet.
     * @param speed La vitesse à laquelle ira la balle.
     * @param damage Les dommages que causeront la balle.
     */
    PlayerBullet(float speed, int damages, QGraphicsItem *parent = 0);

    /**
     * @brief CheckCollision Permet de vérifier les collisions entre la balle et une des type d'ennemie.
     * @param item L'objet rentré collision avec.
     * @return true si collision, faux sinon.
     */
	bool CheckCollision(const QGraphicsItem &item);
	
private slots:
    /**
     * @brief move Fonction permettant à la balle d'avancer.
     */
    void move();
};

#endif // PLAYERBULLET_H
