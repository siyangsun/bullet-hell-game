#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QFont>

class Score : public QGraphicsTextItem
{
public:
    Score(QGraphicsTextItem *parent = 0);
    //void increase(int enemy_score_value);
    void increase();
    int getScore();
private:
    int score;
};

#endif // SCORE_H