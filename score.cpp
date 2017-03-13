#include "score.h"

Score::Score(QGraphicsTextItem *parent) : QGraphicsTextItem(parent)
{
    score = 0;
    setPlainText("Score: " + QString::number(score));
    setDefaultTextColor(Qt::red);
    setFont(QFont("helvetica", 14));
}

//void Score::increase(int enemy_score_value)
void Score::increase()
{
    score += 10;
    setPlainText("Score: " + QString::number(score));
}

int Score::getScore()
{
    return score;
}
