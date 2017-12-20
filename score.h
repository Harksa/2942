#ifndef SCORE_H
#define SCORE_H

#include <QObject>
#include <QGraphicsTextItem>

/**
 * @brief Permet de gérer le score du joueur et de l'afficher.
 */
class Score: public QGraphicsTextItem{
public:
    /**
     * @brief Score Constructeur pour la classe score.
     */
    Score(QGraphicsItem * parent=0);

    /**
     * @brief increase Permet d'augmenter le score du joueur en fonction de number.
     * @param number le nombre auxquel le score va s'incrémenter.
     */
    void increase(int number = 1);

    /**
     * @brief getScore Retourne le score du joueur.
     * @return Le score du joueur.
     */
    int getScore();
	
private:
    /**
     * @brief score Le score du joueur.
     */
    int score;
	
};

#endif // SCORE_H
