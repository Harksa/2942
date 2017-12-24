#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QFont>
#include <QFontDatabase>
#include <QTimer>
#include <QImage>
#include <QMouseEvent>
#include <QApplication>
#include <QDesktopWidget>
#include <iostream>

#include "Player.h"
#include "score.h"
#include "healthUI.h"
#include "spawner.h"
#include "highscores.h"

/**
 * @brief Classe contenant la scène de jeu.
 */
class Game: public QGraphicsView {
    Q_OBJECT
public:
    /**
     * @brief Game Le constructeur de la classe Game.
     */
    Game(QWidget * parent=0);

    /**
     * @brief scene La scene dans lequel le jeu se déroule.
     */
    QGraphicsScene * scene;

    /**
     * @brief player Notre joueur.
     */
    Player * player;

    /**
     * @brief score Le score affiché à l'écran.
     */
    Score * score;

    /**
     * @brief health La vie affiché à l'écran.
     */
    HealthUI * health;

    /**
     * @brief spawner Le spawner d'ennemis.
     */
    Spawner * spawner;

    /**
     * @brief highscores Les highscores.
     */
	HighScores * highscores;

    /**
     * @brief endLevel Timer vérifiant la fin du niveau.
     */
    QTimer * endLevel;

    /**
     * @brief onGoing Permet de vérifier si le jeu est en cours ou non.
     */
	bool onGoing;
	
public :
    /**
     * @brief show_start_menu Permet d'afficher le menu du jeu.
     */
	void show_start_menu();

    /**
     * @brief launch_game Lance le jeu.
     */
    void launch_game();

    /**
     * @brief game_over Gère la fin du jeu.
     */
	void game_over();

    /**
     * @brief add_menu Rajoute un item avec le texte et l'emplacement désiré.
     * @param texte Le texte du bouton
     * @param posX L'emplacement X sur la scène.
     * @param posY L'emplacement Y sur la scène.
     * @param fontHeight La taille de la police de caractère.
     */
	void add_menu(QString texte, int posX, int posY, int fontHeight);

	bool getOnGoing();

private:
    /**
     * @brief mousePressEvent Gére la gestion du clique de la souris.
     * @param event Le clique de la souris.
     */
    void mousePressEvent(QMouseEvent *event);

    /**
     * @brief keyPressEvent Gére l'appuie des touches du clavier.
     * @param event La touche appuyé par le joueur.
     */
    void keyPressEvent(QKeyEvent *event);

    /**
     * @brief checkTypeId Permet de vérifier le typeId d'un graphic item.
     * @param item Vrai si c'est un enemi, faux sinon.
     */
    bool checkTypeId(const QGraphicsItem &item);

private slots:
    /**
     * @brief checkEndLevel Vérifie que le joueur est bien gagné le jeu.
     */
    void checkEndLevel();

};

#endif // GAME_H
