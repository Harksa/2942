#ifndef SCORE_H
#define SCORE_H

#include <QObject>
#include <QGraphicsTextItem>
#include <QFontDatabase>
#include "struct.h"

class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem * parent=0);
    void increase(int number = 1);
    int getScore();
	void showHighScores();
	void checkHighScores(int score);
	
private :
    QString getPlayerName();
    void newHighScore(QString name, int score, int position);
	
private:
    int score;
	struct highScore highScores[10];
};

#endif // SCORE_H
