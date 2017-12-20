#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

/**
 * @brief Classe abstraite qui regroupe les fonctions permettant aux entités de tirer.
 */
class Bullet : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    /**
     * @brief Bullet Constructeur de la classe Bullet.
     * @param speed La vitesse à laquelle ira la balle.
     * @param damage Les dommages que causeront la balle.
     */
    Bullet(float speed, int damage, QGraphicsItem *parent = 0);

    /**
     * @brief CheckCollision Permet de vérifier les collisions la balle est une autre entitée.
     * @param item L'objet rentré collision avec.
     * @return true si collision, faux sinon.
     */
    virtual bool CheckCollision(const QGraphicsItem &item) = 0;
	
protected:
    /**
     * @brief bulletSpeed Vitesse de la balle.
     */
    float bulletSpeed;

    /**
     * @brief bulletDamage Dommages causées par la balle.
     */
    int bulletDamage;
	
protected slots:
    /**
     * @brief move Fonction permettant à la balle d'avancer.
     */
    virtual void move() = 0;
};

#endif // BULLET_H
