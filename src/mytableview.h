#ifndef MYTABLEVIEW_H
#define MYTABLEVIEW_H
#include<QToolButton>
#include<QTableView>
#include<vector>
using namespace std;
class mytableview : public QTableView
{
     Q_OBJECT
public:
    mytableview(QWidget *parent = 0);
   vector<QToolButton*>tools;

};

#endif // MYTABLEVIEW_H
