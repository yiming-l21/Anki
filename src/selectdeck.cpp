#include "selectdeck.h"
#include "ui_selectdeck.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QLabel>
#include<QDialog>
#include<QString>
#include<QDebug>
#include "helpmanual.h"
#include"createcardset.h"
#include"exportdia.h"
#include<QFileDialog>
#include"maingui.h"
#include"button.h"
#include"labels.h"
#include"card.h"
#include"decks.h"
#include"append.h"
#include<QTableView>
#include <QtSql/QSqlDatabase>
#include"global.h"
#include<QStandardItemModel>
selectdeck::selectdeck(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selectdeck)
{
    ui->setupUi(this);
}

selectdeck::~selectdeck()
{
    delete ui;
}
void selectdeck::showselectedstage()
{
    int num=0;
    model->clear();
    model->setColumnCount(1);
    view->setColumnWidth(0,530);
    for(unsigned int i=0;i<decks.size();i++)
    {
        if(decks[i]->name.contains(input,Qt::CaseInsensitive))
        {
            decks[i]->visible=true;
            num++;
        }
        else
        {
            decks[i]->visible=false;

        }
    }
    if(num!=0)
    {
            model->setRowCount(num);
            for(unsigned int i=0,j=0;i<decks.size();i++)
            {
                if(decks[i]->visible)
                {
                    view->setRowHeight(j,30);
                    model->setItem(j,0,new QStandardItem(decks[i]->name));
                    j++;
                }

            }
               view->show();
     }
    else
    {
        model->clear();
    }


}
void selectdeck::showstage()
{
    model = new QStandardItemModel(this);
    view=new QTableView(this);
    view->setModel(model);
    view->move(30,60);
    view->resize(530,30*decks.size());
    model->setColumnCount(1);
    view->setColumnWidth(0,530);
    view->horizontalHeader()->setHidden(true);
    view->verticalHeader()->setHidden(true);
    view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    model->setRowCount(decks.size());
    for(unsigned int i=0;i<decks.size();i++)
    {
        view->setRowHeight(i,30);
        model->setItem(i,0,new QStandardItem(decks[i]->name));

    }
    view->show();
}
void selectdeck::on_pushButton_3_clicked()
{
    close();
}

void selectdeck::on_pushButton_2_clicked()
{

        createcardset create(this);
        QLabel label(&create);
        label.setText(QObject::tr("新牌组名称:"));
        label.move(15,15);
        create.setModal(true);
        create.show();
        create.exec();
        point->Initestage(STAGE_START);
        this->showstage();

}

void selectdeck::on_pushButton_clicked()
{

    int row=this->view->currentIndex().row();
    QModelIndex indextemp=model->index(row,0);
    QVariant datatemp=model->data(indextemp);
    deckname=datatemp.toString();
    if(deckname!="")
    {
        close();
    }

}

void selectdeck::on_textEdit_textChanged()
{
   input=ui->textEdit->toPlainText();
   showselectedstage();
}
