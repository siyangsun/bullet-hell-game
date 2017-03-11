#include "myrect.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyRect w;
    w.show();

    return a.exec();
}
