#include "account.h"
#include "ui_account.h"
#include<QTableView>
#include <QtSql/QSqlDatabase>
#include<QSqlQuery>
#include<QDebug>
#include"global.h"
#include<QMainWindow>
#include"mainwindow.h"
#include"renameacc.h"
#include"createaccount.h"
account::account(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::account)
{
    model=NULL;
    ui->setupUi(this);
    a1=new QTableView(this);
    a1->move(30,30);
    a1->resize(360,560);
    a1->setStyleSheet("background-color:#FFFFFF");

    showstage();
}
void account::showstage()
{
    if(model==NULL)
    {
        model = new QStandardItemModel(this);
    }
    a1->setModel(model);
    model->setColumnCount(1);
    a1->setColumnWidth(0,560);
    a1->horizontalHeader()->setHidden(true);
    a1->verticalHeader()->setHidden(true);
    a1->setEditTriggers(QAbstractItemView::NoEditTriggers);
    a1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    model->setRowCount(accounts.size());
    for(unsigned int i=0;i<accounts.size();i++)
    {
        a1->setRowHeight(i,30);
        model->setItem(i,0,new QStandardItem(accounts[i]->name));

    }
    a1->show();
}
account::~account()
{
    delete ui;
}

void account::on_pushButton_5_clicked()
{
    close();
}

void account::on_pushButton_clicked()
{
    if(accounts.size()!=0)
    {

        currentaccount=accounts[a1->currentIndex().row()];
        point=new MainWindow;
        point->Initestage(Stageid);
        point->show();
        close();
    }
}

void account::on_pushButton_2_clicked()
{
    createaccount*w=new createaccount(this);
    w->show();
}

void account::on_pushButton_4_clicked()
{
    int row=a1->currentIndex().row();
    QModelIndex indextemp=model->index(row,0);
    QVariant datatemp=model->data(indextemp);
    QString accountname=datatemp.toString();
    for(int i=0;i<accounts.size();i++)
    {
        if(accounts[i]->name==accountname)
        {
            accounts.erase(accounts.begin()+i);
        }
    }
    showstage();
}

void account::on_pushButton_3_clicked()
{
if(a1->currentIndex().isValid()==true)
{
    renameacc*b=new renameacc(this);
    b->show();
}

}
