#ifndef HIGHSCORES_H
#define HIGHSCORES_H

#include <QObject>
#include <QGraphicsTextItem>
#include <QFontDatabase>
#include <QString>

struct highScore{
	QString playerName;
	int playerScore;
}; 

class HighScores :  public QGraphicsTextItem{
public:
    HighScores(QGraphicsItem * parent = 0);
	void showHighScores();
	void checkHighScores(int score);
	
private :
    QString getPlayerName();
    void newHighScore(QString name, int score, int position);
	
private:
	struct highScore highScores[10];
};

#endif // HIGHSCORES_H
