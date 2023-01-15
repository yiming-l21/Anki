#include "mainwindow.h"
#include"functions.h"
#include <QApplication>
#include<QLabel>
#include<QMainWindow>
#include"maingui.h"
#include"global.h"
#include<QWidget>
#include<QObject>
#include<QTreeView>
#include <QtSql/QSqlDatabase>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    point=new MainWindow();
    point->Initestage(STAGE_START);
    point->show();
    return a.exec();  
}
