#include "playerhp.h"


PlayerHP::PlayerHP(QGraphicsTextItem *parent) : QGraphicsTextItem(parent)
{
    hp = 100;
    setPlainText("Hitpoints: " + QString::number(hp));
    setDefaultTextColor(Qt::green);
    setFont(QFont("helvetica", 14));
}

//void PlayerHP::take_damage()
void PlayerHP::take_damage(int damage)
{
    hp -= 40;
    setPlainText("Hitpoints: " + QString::number(hp));
}

int PlayerHP::getHP()
{
    return hp;
}
