#ifndef SCORE_H
#define SCORE_H

#include <QObject>
#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem * parent=0);
    void increase(int number = 1);
    int getScore();
	
private:
    int score;
	
};

#endif // SCORE_H
