#ifndef GLOBAL_H
#define GLOBAL_H
#include<vector>
#include<QString>
#include <QtSql/QSqlDatabase>
#include<QMainWindow>
#include"mainwindow.h"
#include"button.h"
#include"card.h"
#include"decks.h"
#include"mytableview.h"
using namespace std;
extern vector<button*>buttons;
extern vector<deck*>decks;
extern vector<label*>labels;
extern QString deckname;
extern MainWindow*point;
extern QStandardItemModel *model ;
extern mytableview*view;
extern deck*currentdeck;
extern int Stageid;
#endif // GLOBAL_H
