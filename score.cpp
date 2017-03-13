#include "score.h"

Score::Score(QGraphicsTextItem *parent) : QGraphicsTextItem(parent)
{
    score = 0;
    setPlainText("Score: " + QString::number(score));
    setDefaultTextColor(Qt::red);
    setFont(QFont("helvetica", 14));
}

void Score::increase()
{
    score++;
}

int Score::getScore()
{
    return score;
}
