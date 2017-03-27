#ifndef GAME_H
#define GAME_H

#include <QApplication>
#include <QGraphicsWidget>
#include <QGraphicsScene>
#include "player.h"
#include "enemy.h"
#include "melee_enemy.h"
#include <QGraphicsView>
#include <QTimer>
#include "score.h"
#include "playerhp.h"
#include "menu.h"


class Game : public QGraphicsWidget
{
    Q_OBJECT
public:
    Game(QWidget *parent = 0);
    //~Game();
    QGraphicsScene *scene;
    Player *player;
    Score *score;
    PlayerHP *player_hp;
    Menu *menu;
public slots:
    void start();
    void end();
private:
    bool started = 0;
};

#endif // GAME_H
