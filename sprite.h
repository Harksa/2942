#ifndef SPRITE_H
#define SPRITE_H

#include <QObject>
#include <QMovie>
#include <QGraphicsPixmapItem>
#include <QPixmap>

/**
 * @brief Permet d'afficher des images animées en jeu.
 */
class Sprite : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    /**
     * @brief Sprite Constructeur permettant de créer un sprite animé en fonction d'un chemin et d'une vitesse d'animation.
     * @param path Le chemin du gif.
     * @param frameRate La vitesse de défillement du gif.
     */
    Sprite(QString path, int frameRate, QGraphicsItem *parent = 0);

    /**
     * @brief Sprite Constructeur permettant de créer un sprite animé en fonction d'un chemin
     * @param path Le chemin du gif.
     */
    Sprite(QString path, QGraphicsItem *parent = 0);

protected:
    /**
     * @brief animation Le QMovie contenant l'animation du sprite.
     */
    QMovie * animation;

protected slots:
    /**
    * @brief loopAnimation Permet de lire le gif.
    */
   void loopAnimation();
};

#endif // SPRITE_H
