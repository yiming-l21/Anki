#include "statics.h"
#include "ui_statics.h"
#include"global.h"
#include"card.h"
#include<QComboBox>
#include<QDebug>
#include<QTableView>
#include<QStandardItemModel>
#include"decks.h"
#define FOR 0
#define FORPLUSDIF 1
#define AVERAGE 2

statics::statics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statics)
{
    ui->setupUi(this);
    ui->widget->setStyleSheet("background-color:#FFFFFF");
    comb=new QComboBox(this);
    comb->move(20,60);
    comb->resize(180,50);
    QStringList list;
    for(int i=0;i<decks.size();i++)
    {
        list<<decks[i]->name;
    }
    comb->addItems(list);
    comb1=new QComboBox(this);
    comb1->move(20,170);
    comb1->resize(180,50);
    QStringList list1;
    list1<<"点击忘记比例"<<"点击忘记或困难比例"<<"平均得分";
    comb1->addItems(list1);
    view=new QTableView(ui->widget);
    model=new QStandardItemModel(this);
    model->setColumnCount(4);
    view->setModel(model);
    view->setColumnWidth(0,140);
    view->setColumnWidth(1,140);
    view->setColumnWidth(2,140);
    view->setColumnWidth(3,120);
    view->horizontalHeader()->setHidden(true);
    view->verticalHeader()->setHidden(true);
    view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->hide();
}

statics::~statics()
{
    delete ui;
}

void statics::on_pushButton_clicked()
{
    close();
}
deck*statics::sorting(deck*a,int type)
{
    deck*b=a;

    if(type==FOR)
    {
        if(b->cards.size()>0)
        {
            for(int i=0;i<b->cards.size()-1;i++)
            {
                for(int j=0;j<b->cards.size()-1;j++)
                {
                    if(b->cards[j]->returnfor(b->cards[j]->studytimes)<b->cards[j+1]->returnfor(b->cards[j+1]->studytimes))
                    {
                        card* temp=b->cards[j];
                        b->cards[j]=b->cards[j+1];
                        b->cards[j+1]=temp;
                    }
                }
            }
        }
    }
    else if(type==FORPLUSDIF)
    {
        if(b->cards.size()>0)
        {
            for(int i=0;i<b->cards.size()-1;i++)
            {
                for(int j=0;j<b->cards.size()-1;j++)
                {
                    if((b->cards[j]->returnfor(b->cards[j]->studytimes)+b->cards[j]->returndif(b->cards[j]->studytimes))<(b->cards[j+1]->returnfor(b->cards[j+1]->studytimes)+b->cards[j+1]->returndif(b->cards[j+1]->studytimes)))
                    {
                        card* temp=b->cards[j];
                        b->cards[j]=b->cards[j+1];
                        b->cards[j+1]=temp;
                    }
                }
            }
         }
    }
    else if(type==AVERAGE)
    {
        if(b->cards.size()>0)
        {
            for(int i=0;i<b->cards.size()-1;i++)
            {
                for(int j=0;j<b->cards.size()-1;j++)
                {
                    qDebug()<<b->cards[j]->returntype(b->cards[j]->studytimes)<<b->cards[j+1]->returntype(b->cards[j+1]->studytimes);
                    if(b->cards[j]->returntype(b->cards[j]->studytimes)<b->cards[j+1]->returntype(b->cards[j+1]->studytimes))
                    {
                        card* temp=b->cards[j];
                        b->cards[j]=b->cards[j+1];
                        b->cards[j+1]=temp;
                    }
                }
            }
        }
    }

    return b;
}
void statics::on_pushButton_2_clicked()
{
    deck*b;
    QString deckname=comb->currentText();
    QString type=comb1->currentText();
    for(int i=0;i<decks.size();i++)
    {
        if(decks[i]->name==deckname)
        {
            if(type=="点击忘记比例")
            {
                b=sorting(decks[i],FOR);
            }
            else if(type=="点击忘记或困难比例")
            {
                b=sorting(decks[i],FORPLUSDIF);
            }
            else if(type=="平均得分")
            {
                b=sorting(decks[i],AVERAGE);
            }

        }
    }
    for(int j=0;j<b->cards.size();j++)
   {
            model->setItem(j,0,new QStandardItem(b->cards[j]->positive));
            model->setItem(j,1,new QStandardItem(b->cards[j]->negative));
            model->setItem(j,2,new QStandardItem(b->cards[j]->label));

            if(type=="点击忘记比例")
            {
                model->setItem(j,3,new QStandardItem(QString::number(b->cards[j]->returnfor(b->cards[j]->studytimes))+"%"));
            }
            else if(type=="点击忘记或困难比例")
            {
                model->setItem(j,3,new QStandardItem(QString::number(b->cards[j]->returnfor(b->cards[j]->studytimes)+b->cards[j]->returndif(b->cards[j]->studytimes))+"%"));
            }
            else if(type=="平均得分")
            {
                model->setItem(j,3,new QStandardItem(QString::number(b->cards[j]->returntype(b->cards[j]->studytimes))));
            }


    }
    view->resize(541,b->cards.size()*40);
    view->show();


}
