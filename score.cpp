#include "score.h"

Score::Score(QGraphicsTextItem *parent) : QGraphicsTextItem(parent)
{
    score = 0;
    setPlainText("Score: " + QString::number(score));
    setDefaultTextColor(QColor(255,140,0));
    setFont(QFont("helvetica", 14));
}

//void Score::increase(int enemy_score_value)
void Score::increase(int points)
{
    score += points;
    setPlainText("Score: " + QString::number(score));
}
