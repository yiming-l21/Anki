#include "browse.h"
#include "ui_browse.h"
#include"global.h"
#include"card.h"
#include<QStandardItemModel>
#include<QTableView>
#include<QString>
#include<QDebug>
#include<QItemSelectionModel>
browse::browse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::browse)
{
    ui->setupUi(this);
    ui->widget->setStyleSheet("background-color:#FFFFFF");
    view=new QTableView(ui->widget);
    model=new QStandardItemModel(this);
    model->setColumnCount(4);
    view->setModel(model);
    view->setColumnWidth(0,200);
    view->setColumnWidth(1,200);
    view->setColumnWidth(2,200);
    view->setColumnWidth(3,200);
    view->horizontalHeader()->setHidden(true);
    view->verticalHeader()->setHidden(true);
    view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->hide();
    QStandardItemModel*model1=new QStandardItemModel(ui->treeView);
    //构建一级节点
    QStandardItem*item1=new QStandardItem(QStringLiteral("牌组"));
    QStandardItem*item2=new QStandardItem(QStringLiteral("旗标"));
    QStandardItem*item3=new QStandardItem(QStringLiteral("标记"));
    QStandardItem*item4=new QStandardItem(QStringLiteral("标签"));
    //牌组二级节点

 QStandardItem**item=(QStandardItem**)malloc(decks.size()*sizeof(QStandardItem*));
 for(int i=0;i<decks.size();i++)
 {
    item[i]=new QStandardItem(QString(decks[i]->name));
    item1->appendRow(item[i]);
 }

    //旗标二级节点
    QStandardItem*item21=new QStandardItem(QStringLiteral("蓝旗"));
    QStandardItem*item22=new QStandardItem(QStringLiteral("绿旗"));
    QStandardItem*item23=new QStandardItem(QStringLiteral("橙旗"));
    QStandardItem*item24=new QStandardItem(QStringLiteral("粉旗"));
    QStandardItem*item25=new QStandardItem(QStringLiteral("紫旗"));
    QStandardItem*item26=new QStandardItem(QStringLiteral("红旗"));
    item2->appendRow(item21);
    item2->appendRow(item22);
    item2->appendRow(item23);
    item2->appendRow(item24);
    item2->appendRow(item25);
    item2->appendRow(item26);
    //标记二级节点
    QStandardItem*item31=new QStandardItem(QStringLiteral("有标记"));
    QStandardItem*item32=new QStandardItem(QStringLiteral("无标记"));
    item3->appendRow(item31);
    item3->appendRow(item32);
    //标签二级节点
    QStandardItem*item41=new QStandardItem(QStringLiteral("有标签"));
    QStandardItem*item42=new QStandardItem(QStringLiteral("无标签"));
    item4->appendRow(item41);
    item4->appendRow(item42);
    ui->treeView->setHeaderHidden(true);
    model1->appendRow(item1);
    model1->appendRow(item2);
    model1->appendRow(item3);
    model1->appendRow(item4);
    ui->treeView->setModel(model1);
    ui->treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(ui->treeView,SIGNAL(clicked(QModelIndex)),this,SLOT(initdeck(QModelIndex)));
    connect(view,SIGNAL(clicked(QModelIndex)),this,SLOT(refreshtext(QModelIndex)));
}
void browse::refreshtext(QModelIndex index)
{
     QString positive=model->data(model->index(index.row(),1)).toString();
     QString negative=model->data(model->index(index.row(),2)).toString();
     QString label=model->data(model->index(index.row(),3)).toString();
     ui->textEdit_2->setText(positive);
     ui->textEdit_3->setText(negative);
     ui->textEdit_4->setText(label);
}
void browse::initdeck(QModelIndex index)
{
    QString string=index.data().toString();
    if(string=="牌组"||string=="旗标"||string=="标记"||string=="标签")
    {
        return;
    }
    else
    {
        if(string=="蓝旗")
        {
            int num=0;
            model->clear();
            model->setColumnCount(4);
            view->setModel(model);
            view->setColumnWidth(0,200);
            view->setColumnWidth(1,200);
            view->setColumnWidth(2,200);
            view->setColumnWidth(3,200);
            for(int i=0;i<decks.size();i++)
            {
                for(int j=0;j<decks[i]->cards.size();j++)
                {
                    if(decks[i]->cards[j]->markcolor==BLUE)
                    {
                        model->setItem(num,0,new QStandardItem(decks[i]->name));
                        model->setItem(num,1,new QStandardItem(decks[i]->cards[j]->positive));
                        model->setItem(num,2,new QStandardItem(decks[i]->cards[j]->negative));
                        model->setItem(num,3,new QStandardItem(decks[i]->cards[j]->label));
                        qDebug()<<decks[i]->name<<decks[i]->cards[j]->positive;
                        num+=1;
                    }
                }
            }
            if(40*num<=350)
            {
                view->resize(800,40*num);
            }
            else
            {
                view->resize(800,350);
            }
            view->show();
        }
        else if(string=="红旗")
        {
            int num=0;
            model->clear();
            model->setColumnCount(4);
            view->setModel(model);
            view->setColumnWidth(0,200);
            view->setColumnWidth(1,200);
            view->setColumnWidth(2,200);
            view->setColumnWidth(3,200);
            for(int i=0;i<decks.size();i++)
            {
                for(int j=0;j<decks[i]->cards.size();j++)
                {
                    if(decks[i]->cards[j]->markcolor==RED)
                    {
                        model->setItem(num,0,new QStandardItem(decks[i]->name));
                        model->setItem(num,1,new QStandardItem(decks[i]->cards[j]->positive));
                        model->setItem(num,2,new QStandardItem(decks[i]->cards[j]->negative));
                        model->setItem(num,3,new QStandardItem(decks[i]->cards[j]->label));
                        num+=1;
                    }
                }
            }
            if(40*num<=350)
            {
                view->resize(800,40*num);
            }
            else
            {
                view->resize(800,350);
            }
            view->show();
        }
        else if(string=="绿旗")
        {
            int num=0;
            model->clear();
            model->setColumnCount(4);
            view->setModel(model);
            view->setColumnWidth(0,200);
            view->setColumnWidth(1,200);
            view->setColumnWidth(2,200);
            view->setColumnWidth(3,200);
            for(int i=0;i<decks.size();i++)
            {
                for(int j=0;j<decks[i]->cards.size();j++)
                {
                    if(decks[i]->cards[j]->markcolor==GREEN)
                    {
                        model->setItem(num,0,new QStandardItem(decks[i]->name));
                        model->setItem(num,1,new QStandardItem(decks[i]->cards[j]->positive));
                        model->setItem(num,2,new QStandardItem(decks[i]->cards[j]->negative));
                        model->setItem(num,3,new QStandardItem(decks[i]->cards[j]->label));
                        num+=1;
                    }
                }
            }
            if(40*num<=350)
            {
                view->resize(800,40*num);
            }
            else
            {
                view->resize(800,350);
            }
            view->show();
        }
        else if(string=="橙旗")
        {
            int num=0;
            model->clear();
            model->setColumnCount(4);
            view->setModel(model);
            view->setColumnWidth(0,200);
            view->setColumnWidth(1,200);
            view->setColumnWidth(2,200);
            view->setColumnWidth(3,200);
            for(int i=0;i<decks.size();i++)
            {
                for(int j=0;j<decks[i]->cards.size();j++)
                {
                    if(decks[i]->cards[j]->markcolor==ORANGE)
                    {
                        model->setItem(num,0,new QStandardItem(decks[i]->name));
                        model->setItem(num,1,new QStandardItem(decks[i]->cards[j]->positive));
                        model->setItem(num,2,new QStandardItem(decks[i]->cards[j]->negative));
                        model->setItem(num,3,new QStandardItem(decks[i]->cards[j]->label));
                        num+=1;
                    }
                }
            }
            if(40*num<=350)
            {
                view->resize(800,40*num);
            }
            else
            {
                view->resize(800,350);
            }
            view->show();
        }
        else if(string=="粉旗")
        {
            int num=0;
            model->clear();
            model->setColumnCount(4);
            view->setModel(model);
            view->setColumnWidth(0,200);
            view->setColumnWidth(1,200);
            view->setColumnWidth(2,200);
            view->setColumnWidth(3,200);
            for(int i=0;i<decks.size();i++)
            {
                for(int j=0;j<decks[i]->cards.size();j++)
                {
                    if(decks[i]->cards[j]->markcolor==PINK)
                    {
                        model->setItem(num,0,new QStandardItem(decks[i]->name));
                        model->setItem(num,1,new QStandardItem(decks[i]->cards[j]->positive));
                        model->setItem(num,2,new QStandardItem(decks[i]->cards[j]->negative));
                        model->setItem(num,3,new QStandardItem(decks[i]->cards[j]->label));
                        num+=1;
                    }
                }
            }
            if(40*num<=350)
            {
                view->resize(800,40*num);
            }
            else
            {
                view->resize(800,350);
            }
            view->show();
        }
        else if(string=="紫旗")
        {
            int num=0;
            model->clear();
            model->setColumnCount(4);
            view->setModel(model);
            view->setColumnWidth(0,200);
            view->setColumnWidth(1,200);
            view->setColumnWidth(2,200);
            view->setColumnWidth(3,200);
            for(int i=0;i<decks.size();i++)
            {
                for(int j=0;j<decks[i]->cards.size();j++)
                {
                    if(decks[i]->cards[j]->markcolor==PURPLE)
                    {
                        model->setItem(num,0,new QStandardItem(decks[i]->name));
                        model->setItem(num,1,new QStandardItem(decks[i]->cards[j]->positive));
                        model->setItem(num,2,new QStandardItem(decks[i]->cards[j]->negative));
                        model->setItem(num,3,new QStandardItem(decks[i]->cards[j]->label));
                        num+=1;
                    }
                }
            }
            if(40*num<=350)
            {
                view->resize(800,40*num);
            }
            else
            {
                view->resize(800,350);
            }
            view->show();
        }
        else if(string=="有标记")
        {
              model->clear();
              model->setColumnCount(4);
              view->setModel(model);
              view->setColumnWidth(0,200);
              view->setColumnWidth(1,200);
              view->setColumnWidth(2,200);
              view->setColumnWidth(3,200);
            int num=0;
            for(int i=0;i<decks.size();i++)
            {
                for(int j=0;j<decks[i]->cards.size();j++)
                {
                    if(decks[i]->cards[j]->marked==true)
                    {
                        model->setItem(num,0,new QStandardItem(decks[i]->name));
                        model->setItem(num,1,new QStandardItem(decks[i]->cards[j]->positive));
                        model->setItem(num,2,new QStandardItem(decks[i]->cards[j]->negative));
                        model->setItem(num,3,new QStandardItem(decks[i]->cards[j]->label));
                        num+=1;
                    }
                }
            }
            if(40*num<=350)
            {
                view->resize(800,40*num);
            }
            else
            {
                view->resize(800,350);
            }
            view->show();
        }
        else if(string=="无标记")
        {
              model->clear();
              model->setColumnCount(4);
              view->setModel(model);
              view->setColumnWidth(0,200);
              view->setColumnWidth(1,200);
              view->setColumnWidth(2,200);
              view->setColumnWidth(3,200);
            int num=0;
            for(int i=0;i<decks.size();i++)
            {
                for(int j=0;j<decks[i]->cards.size();j++)
                {

                    if(decks[i]->cards[j]->marked==false)
                    {
                        model->setItem(num,0,new QStandardItem(decks[i]->name));
                        model->setItem(num,1,new QStandardItem(decks[i]->cards[j]->positive));
                        model->setItem(num,2,new QStandardItem(decks[i]->cards[j]->negative));
                        model->setItem(num,3,new QStandardItem(decks[i]->cards[j]->label));
                        num+=1;
                    }
                }
            }
            qDebug()<<num;
            if(40*num<=350)
            {
                view->resize(800,40*num);
            }
            else
            {
                view->resize(800,350);
            }
            view->show();
        }
        else if(string=="有标签")
        {
            model->clear();
            model->setColumnCount(4);
            view->setModel(model);
            view->setColumnWidth(0,200);
            view->setColumnWidth(1,200);
            view->setColumnWidth(2,200);
            view->setColumnWidth(3,200);
            int num=0;
            for(int i=0;i<decks.size();i++)
            {
                for(int j=0;j<decks[i]->cards.size();j++)
                {
                    if(decks[i]->cards[j]->label.isEmpty()==false)
                    {
                        model->setItem(num,0,new QStandardItem(decks[i]->name));
                        model->setItem(num,1,new QStandardItem(decks[i]->cards[j]->positive));
                        model->setItem(num,2,new QStandardItem(decks[i]->cards[j]->negative));
                        model->setItem(num,3,new QStandardItem(decks[i]->cards[j]->label));
                        num+=1;
                    }
                }
            }
            if(40*num<=350)
            {
                view->resize(800,40*num);
            }
            else
            {
                view->resize(800,350);
            }
            view->show();
        }
        else if(string=="无标签")
        {
            int num=0;
            model->clear();
            model->setColumnCount(4);
            view->setModel(model);
            view->setColumnWidth(0,200);
            view->setColumnWidth(1,200);
            view->setColumnWidth(2,200);
            view->setColumnWidth(3,200);
            for(int i=0;i<decks.size();i++)
            {
                for(int j=0;j<decks[i]->cards.size();j++)
                {
                    if(decks[i]->cards[j]->label.isEmpty()==true)
                    {
                        model->setItem(num,0,new QStandardItem(decks[i]->name));
                        model->setItem(num,1,new QStandardItem(decks[i]->cards[j]->positive));
                        model->setItem(num,2,new QStandardItem(decks[i]->cards[j]->negative));
                        model->setItem(num,3,new QStandardItem(""));
                        num+=1;
                    }
                }
            }
            if(40*num<=350)
            {
                view->resize(800,40*num);
            }
            else
            {
                view->resize(800,350);
            }

            view->show();
        }
        else
        {

            for(int i=0;i<decks.size();i++)
            {
                if(string==decks[i]->name)
                {
                    model->clear();
                    model->setColumnCount(4);
                    view->setModel(model);
                    view->setColumnWidth(0,200);
                    view->setColumnWidth(1,200);
                    view->setColumnWidth(2,200);
                    view->setColumnWidth(3,200);
                    for(int j=0;j<decks[i]->cards.size();j++)
                    {
                        model->setItem(j,0,new QStandardItem(decks[i]->name));
                        model->setItem(j,1,new QStandardItem(decks[i]->cards[j]->positive));
                        model->setItem(j,2,new QStandardItem(decks[i]->cards[j]->negative));
                        model->setItem(j,3,new QStandardItem(decks[i]->cards[j]->label));

                    }
                    if(40*decks[i]->cards.size()<=350)
                    {
                         view->resize(800,40*decks[i]->cards.size());
                    }
                    else
                    {
                        view->resize(800,350);
                    }

                    view->show();

                }
            }
        }
    }
}
browse::~browse()
{
    delete ui;
}

void browse::on_textEdit_2_textChanged()
{
    QString deckname=model->data(model->index(view->currentIndex().row(),0)).toString();
    QString positive=model->data(model->index(view->currentIndex().row(),1)).toString();
    QString negative=model->data(model->index(view->currentIndex().row(),2)).toString();
    for(int i=0;i<decks.size();i++)
    {
        if(decks[i]->name==deckname)
        {
            for(int j=0;j<decks[i]->cards.size();j++)
            {
                if(decks[i]->cards[j]->positive==positive&&decks[i]->cards[j]->negative==negative)
                {
                    decks[i]->cards[j]->positive=ui->textEdit_2->toPlainText();
                }
            }
        }
    }
    model->setData(model->index(view->currentIndex().row(),1),ui->textEdit_2->toPlainText());
    view->show();
}


void browse::on_textEdit_3_textChanged()
{

    QString deckname=model->data(model->index(view->currentIndex().row(),0)).toString();
    QString positive=model->data(model->index(view->currentIndex().row(),1)).toString();
    QString negative=model->data(model->index(view->currentIndex().row(),2)).toString();
    for(int i=0;i<decks.size();i++)
    {
        if(decks[i]->name==deckname)
        {
            for(int j=0;j<decks[i]->cards.size();j++)
            {
                if(decks[i]->cards[j]->positive==positive&&decks[i]->cards[j]->negative==negative)
                {
                    decks[i]->cards[j]->negative=ui->textEdit_3->toPlainText();
                }
            }
        }
    }
    model->setData(model->index(view->currentIndex().row(),2),ui->textEdit_3->toPlainText());
    view->show();
}



void browse::on_textEdit_4_textChanged()
{
    QString deckname=model->data(model->index(view->currentIndex().row(),0)).toString();
    QString positive=model->data(model->index(view->currentIndex().row(),1)).toString();
    QString negative=model->data(model->index(view->currentIndex().row(),2)).toString();
    for(int i=0;i<decks.size();i++)
    {
        if(decks[i]->name==deckname)
        {
            for(int j=0;j<decks[i]->cards.size();j++)
            {
                if(decks[i]->cards[j]->positive==positive&&decks[i]->cards[j]->negative==negative)
                {
                    decks[i]->cards[j]->label=ui->textEdit_4->toPlainText();
                }
            }
        }
    }
    model->setData(model->index(view->currentIndex().row(),3),ui->textEdit_4->toPlainText());
    view->show();
}
