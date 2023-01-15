#include<vector>
#include<QString>
#include<QMainWindow>
#include"mainwindow.h"
#include"button.h"
#include"card.h"
#include"decks.h"
#include"mytableview.h"
using namespace std;
vector<button*>buttons;
vector<deck*>decks;
vector<label*>labels;
MainWindow*point;
QString deckname;
deck*currentdeck;
QStandardItemModel *model ;
mytableview*view;
int Stageid=STAGE_START;


