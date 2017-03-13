#include "game.h"
#include <QApplication>
#include <QGraphicsScene>
#include "player.h"
#include "enemy.h"
#include "melee_enemy.h"
#include <QGraphicsView>
#include <QTimer>

Game::Game(QWidget *parent)
{
    Q_UNUSED(parent);


    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();
    // add a view
    QGraphicsView *view = new QGraphicsView(scene);
    // can also use view->setScene(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    view->setFixedSize(800 ,600);
    scene->setSceneRect(0, 0, 800, 600);

    //create the player
    Player *player = new Player();
    player->setRect(0, 0, 50, 50);
    scene->addItem(player);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    player->setPos(view->width() / 2 - (player->rect().width() / 2), view->height() - player->rect().height());


    //start spawning enemies
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn_melee()));
    timer->start(2000);

    show();
}
