#include "mainwindow.h"
#include <QApplication>

double shittier;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
