#ifndef MYACCOUNT_H
#define MYACCOUNT_H

#include <QtSql/QSqlDatabase>
#include"decks.h"
#include<QString>
#include<vector>
using namespace std;
class myaccount
{
public:
    myaccount(){}
    myaccount(QString name,QString accnum,QString password):name(name),accnum(accnum),password(password){}
    ~myaccount();
     vector<deck*>decks;
     QString name;
     QString accnum;
     QString password;
};

#endif // MYACCOUNT_H
