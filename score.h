#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QFont>
#include <QColor>

class Score : public QGraphicsTextItem
{
public:
    Score(QGraphicsTextItem *parent = 0);
    //void increase(int enemy_score_value);
    void increase(int points);
    int getScore();
private:
    int score;
};

#endif // SCORE_H
