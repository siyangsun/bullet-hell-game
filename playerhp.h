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
    int getHP();
signals:
    void dead();
private:
    int hp;
};

#endif // PLAYERHP_H
