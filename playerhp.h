#ifndef PLAYERHP_H
#define PLAYERHP_H

#include <QGraphicsTextItem>
#include <QFont>

class PlayerHP : public QGraphicsTextItem
{
    Q_OBJECT
public:
    PlayerHP(QGraphicsTextItem *parent = 0);
    void take_damage(int damage);
    int hp;
signals:
    void dead();  
};

#endif // PLAYERHP_H
