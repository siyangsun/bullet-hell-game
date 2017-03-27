#ifndef MENU_H
#define MENU_H

#include <QGraphicsWidget>
#include <QGraphicsScene>
#include <QGraphicsView>

class Menu : public QGraphicsWidget
{
    Q_OBJECT
public:
    Menu(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *event);
};

#endif // MENU_H
