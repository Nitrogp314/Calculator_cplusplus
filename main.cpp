#include "testandoQt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    testandoQt w;
    w.show();
    return a.exec();
}
