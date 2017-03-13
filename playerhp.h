#ifndef PLAYERHP_H
#define PLAYERHP_H

#include <QGraphicsTextItem>
#include <QFont>

class PlayerHP : public QGraphicsTextItem
{
public:
    PlayerHP(QGraphicsTextItem *parent = 0);
    //void increase(int enemy_score_value);
    void take_damage();
    int getHP();
private:
    int hp;
};

#endif // PLAYERHP_H
