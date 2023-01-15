#include "renamedeck.h"
#include "ui_renamedeck.h"
#include"global.h"
#include<QMessageBox>
renamedeck::renamedeck(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::renamedeck)
{
    ui->setupUi(this);
}

renamedeck::~renamedeck()
{
    delete ui;
}
void renamedeck::on_pushButton_2_clicked()
{

    close();
}

void renamedeck::on_pushButton_clicked()
{
    bool flag=true;
    QString name=this->b->toPlainText();
    for(int i=0;i<decks.size();i++)
    {
        if(decks[i]->name==name)
        {
            flag=false;
        }

    }
    if(flag==true)
    {
    for(int i=0;i<decks.size();i++)
    {
        if(decks[i]->name==point->currentbutton->name)
        {
           decks[i]->name=name;
        }
    }
    }
    else
    {
        QMessageBox*info=new QMessageBox(this);
        info->setText(tr("你的牌库中已经拥有名为")+name+tr("的牌组，请重新输入"));
        info->setModal(true);
        info->setWindowTitle(tr("提示"));
        info->show();
        info->exec();

    }
    point->Initestage(STAGE_START);
    close();
}
