#include "renameacc.h"
#include "ui_renameacc.h"
#include"account.h"
#include"global.h"
#include<QString>
renameacc::renameacc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::renameacc)
{
    ui->setupUi(this);
}

renameacc::~renameacc()
{
    delete ui;
}

void renameacc::on_pushButton_2_clicked()
{
    close();
}

void renameacc::on_pushButton_clicked()
{
    QString newname=ui->textEdit->toPlainText();
    int row=acc->a1->currentIndex().row();
    acc->accounts[row]->name=newname;
    acc->showstage();
    close();
}
