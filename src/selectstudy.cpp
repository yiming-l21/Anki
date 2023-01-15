#include "selectstudy.h"
#include "ui_selectstudy.h"
#include<QModelIndex>
#include<QVariant>
#include<QDebug>
#include<QModelIndex>
#include"mainwindow.h"
selectstudy::selectstudy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selectstudy)
{
    ui->setupUi(this);
}

selectstudy::~selectstudy()
{
    delete ui;
}

void selectstudy::on_pushButton_3_clicked()
{
    close();
}
void selectstudy::showstage()
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
void selectstudy::showselectedstage()
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
    //view->resize(530,30*num);
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
void selectstudy::on_pushButton_2_clicked()
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


void selectstudy::on_textEdit_textChanged()
{
    input=ui->textEdit->toPlainText();
    showselectedstage();
}

void selectstudy::on_pushButton_clicked()
{
   QModelIndex index=view->selectionModel()->currentIndex();
   int ind=index.row();
   currentdeck=decks[ind];
   point->Initestage(STAGE_STUDY);
   close();
}
