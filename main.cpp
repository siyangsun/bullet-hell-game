#include <QApplication>
#include <QGraphicsScene>
#include "MyRect.h"
#include "enemy.h"
#include "melee_enemy.h"
#include <QGraphicsView>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // create an item put into the scene that can respond to key events
    MyRect *player = new MyRect();
    player->setRect(0, 0, 50, 50);

    // add the item to the scene
    scene->addItem(player);

    // make the rect focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // add a view
    QGraphicsView *view = new QGraphicsView(scene);
    // can also use view->setScene(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
    view->setFixedSize(800 ,600);
    scene->setSceneRect(0, 0, 800, 600);

    player->setPos(view->width() / 2 - (player->rect().width() / 2), view->height() - player->rect().height());

    //start spawning enemies
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn_melee()));
    timer->start(2000);

    return a.exec();
}
