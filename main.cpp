#include "mainwindow.h"
#include "dbconnect.h"

#include <QApplication>
#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase org;
    mydbconnect(org);

    MainWindow w(nullptr,&org);





    w.show();
    return a.exec();
}
