#include "mainwindow.h"
#include <QApplication>
#include "indx.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qRegisterMetaType<Indx>();
    MainWindow w;
    w.show();

    return a.exec();
}
