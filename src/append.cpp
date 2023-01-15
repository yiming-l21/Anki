#include "append.h"
#include "ui_append.h"
#include"selectdeck.h"
#include<QLabel>
#include<QDialog>
#include<QString>
#include<QRect>
#include<QDebug>
#include"createcardset.h"
#include<QFileDialog>
#include<QFontMetrics>
#include"button.h"
#include"labels.h"
#include"card.h"
#include"decks.h"
#include"append.h"
#include<QTableView>
#include<QMouseEvent>
#include<QTextCharFormat>
#include <QtSql/QSqlDatabase>
#include<QColorDialog>
#include<QColor>
#include<QFont>
#include<QFontDialog>
#include"global.h"
#include<QStandardItemModel>
append::append(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::append)
{
    cardbutton=new button(this);
    cardbutton->resize(250,31);
    cardbutton->move(100,15);
    QString string=decks[0]->name;
    cardbutton->name=string;
    cardbutton->setText(string);
    cardbutton->show();
    ui->setupUi(this);
    connect(cardbutton,SIGNAL(clicked()),this,SLOT(on_cardbutton_clicked()));




}

append::~append()
{
    delete ui;
}
void append::on_cardbutton_clicked()
{

        selectdeck a(this);
        a.setModal(true);
        if(a.input=="")
        {
            a.showstage();
        }

        a.show();
        a.exec();
        this->cardbutton->setText(deckname);

}
void append::on_pushButton_4_clicked()
{
    bool ok;
   QFont font=QFontDialog::getFont(&ok);
    ui->textEdit->setFont(font);
    ui->textEdit_2->setFont(font);
}







void append::on_pushButton_2_clicked()
{
    close();
}

void append::on_pushButton_clicked()
{
    QString positive=ui->textEdit->toPlainText();
    QString negative=ui->textEdit_2->toPlainText();
    QString note=ui->textEdit_3->toPlainText();
    for(unsigned int i=0;i<decks.size();i++)
    {
        if(decks[i]->name==deckname)
        {
            if(positive!=""||negative!="")
            {
               card* newcard=new card(positive,negative,note,true,UNSTUDY);
               decks[i]->cards.push_back(newcard);
               if(decks[i]->unstudys.size()<decks[i]->studylen)
               {
                    decks[i]->unstudys.push_back(newcard);
                    newcard->state=UNSTUDY;
                    newcard->lastindex=decks[i]->unstudys.size()-1;
                    decks[i]->unstudy+=1;
               }

            }

        }

    }
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    ui->textEdit_3->clear();
    point->Initestage(Stageid);
}

