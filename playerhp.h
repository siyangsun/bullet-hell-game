#ifndef PLAYERHP_H
#define PLAYERHP_H

#include <QGraphicsTextItem>
#include <QFont>

class PlayerHP : public QGraphicsTextItem
{
public:
    PlayerHP(QGraphicsTextItem *parent = 0);
    void take_damage(int damage);
    int getHP();
private:
    int hp;
};

#endif // PLAYERHP_H
