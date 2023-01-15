#include "createaccount.h"
#include "ui_createaccount.h"
#include"myaccount.h"
#include"global.h"
#include<QString>
#include <QSqlQuery>
#include <QtSql/QSqlDatabase>
createaccount::createaccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createaccount)
{
    ui->setupUi(this);
}

createaccount::~createaccount()
{
    delete ui;
}

void createaccount::on_pushButton_2_clicked()
{
    close();
}

void createaccount::on_pushButton_clicked()
{
    QString name=ui->textEdit->toPlainText();
    QString accnum=ui->textEdit_2->toPlainText();
    QString password=ui->textEdit_3->toPlainText();
    myaccount*w=new myaccount(name,accnum,password);
    acc->accounts.push_back(w);
    acc->showstage();
    close();
}
