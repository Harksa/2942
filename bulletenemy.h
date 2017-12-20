#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

#include "bullet.h"

/**
 * @brief Balle ennemie.
 */
class EnemyBullet : public Bullet {
        Q_OBJECT
public:
    /**
     * @brief Bullet Constructeur de la classe EnemyBullet.
     * @param speed La vitesse à laquelle ira la balle.
     * @param damage Les dommages que causeront la balle.
     */
    EnemyBullet(float speed, int damages, QGraphicsItem *parent = 0);

    /**
     * @brief CheckCollision Permet de vérifier les collisions entre la balle et le joueur.
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

#endif // ENEMYBULLET_H

