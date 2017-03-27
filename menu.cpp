#include "menu.h"
#include "game.h"
#include <QDebug>
#include <QKeyEvent>

extern Game *game;

Menu::Menu(QWidget *parent)
{
    Q_UNUSED(parent);

    // create a scene
    QGraphicsScene *scene = new QGraphicsScene();

    // add a view
    QGraphicsView *view = new QGraphicsView(scene);
    // can also use view->setScene(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    view->setFixedSize(800 ,600);
    scene->setSceneRect(0, 0, 800, 600);

    //make the background
    view->setBackgroundBrush(QBrush(QImage(":/sprites/menu.png")));

    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
}

void Menu::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return) {
        qDebug() << "Successfully exited the menu";
        //Game = new game();
        delete this;
    }
    qDebug() << "Failed to exit the menu";
}
