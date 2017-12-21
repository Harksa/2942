#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

/**
 * @brief Classe abstraite Enemy qui permettra de créer plusieurs type d'ennemis différents.
 */
class Enemy : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    /**
     * @brief Enemy Constructeur de la classe Enemy.
     * @param pos_x Position de départ de l'ennemi (lorsqu'il apparait en haut de l'écran). -1 pour un positionnement aléatoire.
     */
    Enemy(int pos_x = -1);

    /**
     * @brief decrementeLife Diminue la vie du vaisseau en fonction des dommages reçus.
     * @param damage Les dommages reçus.
     */
    void decrementeLife(int damage);

    /**
     * @brief getScore Donne le score que procure la destruction de cet ennemi.
     * @return Le score du vaisseau.
     */
    int getScore() const {return scoreGiven;}
private:
    /**
     * @brief TimerAvancer Fonction permettant de mettre à jour la position du vaisseau.
     */
    void TimerAvancer();

protected:
    /**
     * @brief life La quantité de vie que ce vaisseau posséde.
     */
    int life;
    /**
     * @brief moveSpeed La vitesse à laquelle ce vaisseau ce déplace.
     */
    float moveSpeed;

    /**
     * @brief scoreGiven Le score donné à la destruction de ce vaisseau.
     */
    int scoreGiven;

    /**
     * @brief spawn Fait apparaitre le vaisseau dans la scène.
     * @param i La position d'origine du vaisseau en X. A -1 par défaut pour un positionnement aléatoire.
     */
    void spawn(int i = -1);

    /**
     * @brief destroyWhenOutsideMap Détruit le vaisseau lorsqu'il est en dehors de la carte.
     */
    void destroyWhenOutsideMap();

    /**
     * @brief DestroyWhenContactWithPlayer Detruit le vaisseau lorsqu'il rentre en contact avec le joueur.
     */
    void DestroyWhenContactWithPlayer();

    /**
     * @brief checkCollisionWithPlayer regarde les collisions entre le vaisseau et celui du joueur.
     * @param item L'objet rentré en collision avec.
     * @return Vrai si collision, faux sinon.
     */
    bool checkCollisionWithPlayer(const QGraphicsItem &item);

    /**
     * @brief explode Détruit le vaisseau et fait apparaitre l'animation d'explosion.
     */
    void explode();
public slots:

    /**
     * @brief move Gére le mouvement du vaisseau.
     */
    virtual void move() = 0;
};

#endif // ENEMY_H
