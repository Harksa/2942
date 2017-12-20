#ifndef PLAYERSTATS_H
#define PLAYERSTATS_H

/**
 * Ce header regroupe les attributs du joueur. (vitesse de mouvement, d'attaque, etc)
 */
class PlayerStats {
public:
    /**
     * @brief playerSpeed Vitesse de deplacement.
     */
    float playerSpeed = 0.45f;

    /**
     * @brief fireDelay Vitesse d'attaque.
     */
    float fireDelay = 320;

    /**
     * @brief health Vie de départ.
     */
    float health = 3;
};

#endif // PLAYERSTATS_H
