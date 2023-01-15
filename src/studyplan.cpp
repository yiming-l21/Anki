#include "studyplan.h"
#include "ui_studyplan.h"
#include"global.h"
#include<QDebug>
studyplan::studyplan(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studyplan)
{
    ui->setupUi(this);
    comb=new QComboBox(this);
    comb->move(50,10);
    comb->resize(500,50);
    QStringList list;
    for(int i=0;i<decks.size();i++)
    {
        list<<decks[i]->name;
    }
    comb->addItems(list);
    ui->textEdit->setText(QString::number(decks[0]->studylen,10));
    ui->textEdit_2->setText(QString::number(decks[0]->minpasstime,10));
    ui->textEdit_3->setText("60");
    ui->textEdit_4->setText("300");
    ui->textEdit_5->setText("600");
    connect(comb,SIGNAL(currentTextChanged(QString)),this,SLOT(on_change(QString)));
}

studyplan::~studyplan()
{
    delete ui;
}

void studyplan::on_pushButton_2_clicked()
{
    close();
}
void studyplan::on_change(QString)
{
    QString string=comb->currentText();
    for(int i=0;i<decks.size();i++)
    {
        if(string==decks[i]->name)
        {
            ui->textEdit->clear();
            ui->textEdit->setText(QString::number(decks[i]->studylen,10));
            ui->textEdit_2->clear();
            ui->textEdit_2->setText(QString::number(decks[i]->minpasstime,10));
        }
    }

}
void studyplan::on_pushButton_clicked()
{
    QString string=this->comb->currentText();
    int studylen=ui->textEdit->toPlainText().toInt();
    int passtimes=ui->textEdit_2->toPlainText().toInt();
    int dif=ui->textEdit_3->toPlainText().toInt();
    int com=ui->textEdit_4->toPlainText().toInt();
    int ea=ui->textEdit_5->toPlainText().toInt();

        for(int i=0;i<decks.size();i++)
        {
            if(string==decks[i]->name)
            {
                decks[i]->studylen=studylen;
                decks[i]->minpasstime=passtimes;
                for(int j=0;j<decks[i]->cards.size();j++)
                {
                    decks[i]->cards[j]->diftime=dif;
                    decks[i]->cards[j]->comtime=com;
                    decks[i]->cards[j]->easytime=ea;
                }
               decks[i]->unstudys.clear();
                decks[i]->unstudy=0;
                for(int j=0;j<decks[i]->studylen;j++)
                {
                    if(decks[i]->cards.size()>j)
                    {
                        decks[i]->unstudys.push_back(decks[i]->cards[j]);

                        decks[i]->unstudy+=1;
                    }
                }
            }
        }


    point->Initestage(Stageid);
    close();
}
