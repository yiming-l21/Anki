#include "createcardset.h"
#include "ui_createcardset.h"
#include"decks.h"
#include"button.h"
#include"global.h"
#include<QDebug>
createcardset::createcardset(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createcardset)
{
    ui->setupUi(this);
}

createcardset::~createcardset()
{
    delete ui;
}


void createcardset::on_pushButton_2_clicked()
{
    bool flag=true;
    QString name=ui->textEdit->toPlainText();
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
            if(decks[i]->name=="系统预设")
            {
                if(decks[i]->cards.size()==0)
                {
                     decks.erase(decks.begin()+i);
                }
            }

        }
        deck* newdeck=new deck(name);
        decks.push_back(newdeck);
        for(int i=0;i<decks.size();i++)
        {
            for(int j=0;j<decks.size()-i-1;j++)
            {
                if(QString::compare(decks[j+1]->name,decks[j]->name)<0)
                {
                  swap(decks[j+1],decks[j]);
                }
            }
        }
    }
    close();
}

void createcardset::on_pushButton_clicked()
{
    close();
}
