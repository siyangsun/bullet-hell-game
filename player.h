#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent *event);
public slots:
    void spawn_melee();
    void spawn_obstacle();
    void spawn_powerup();
    void spawn_biker();
    void spawn();
};

#endif // PLAYER_H
