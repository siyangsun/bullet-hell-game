#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>

class Player: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent *event);
public slots:
    void spawn_melee();
    void spawn_bullet();
    void spawn();
};

#endif // PLAYER_H
