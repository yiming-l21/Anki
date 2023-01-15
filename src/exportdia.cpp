#include "exportdia.h"
#include "ui_exportdia.h"
#include<QFileDialog>
#include<QTextStream>
#include"global.h"
EXPORTDIA::EXPORTDIA(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EXPORTDIA)
{
    ui->setupUi(this);
    this->combobox=new QComboBox(this);
    this->combobox->resize(281,25);
    this->combobox->move(180,60);
    QStringList list;
    list<<tr("全部牌组");
    for(int i=0;i<decks.size();i++)
    {
        list<<decks[i]->name;
    }
    this->combobox->addItems(list);
}
void EXPORTDIA::on_pushButton_clicked()
{
    close();
}
EXPORTDIA::~EXPORTDIA()
{
    delete ui;
}

void EXPORTDIA::on_pushButton_2_clicked()
{
    QString string=this->combobox->currentText();
    if(string=="全部牌组")
    {
        QString destFileName = QFileDialog::getSaveFileName(this,QString::fromLocal8Bit("另存为"), QDir::currentPath(),"*.txt");
        if(!destFileName.isEmpty())
        {
            QFile file(destFileName);
            QTextStream stream(&file);
            file.open(QIODevice::ReadWrite|QIODevice::Text);
            for(int i=0;i<decks.size();i++)
            {
                    stream<<QString::number(i+1,10)<<":";
                    stream<<decks[i]->name<<endl;
                    for(int j=0;j<decks[i]->cards.size();j++)
                    {
                        stream<<decks[i]->cards[j]->positive<<" "<<decks[i]->cards[j]->negative<<endl;
                    }
           }
         }



    }
    else
    {
        for(int i=0;i<decks.size();i++)
        {
            if(decks[i]->name==string)
            {
                QString destFileName = QFileDialog::getSaveFileName(this,QString::fromLocal8Bit("另存为"), QDir::currentPath(),"*.txt");
                if(!destFileName.isEmpty())
                {
                    QFile file(destFileName);
                    file.open(QIODevice::ReadWrite|QIODevice::Text);
                    QTextStream stream(&file);
                    stream<<decks[i]->name<<endl;
                    for(int j=0;j<decks[i]->cards.size();j++)
                    {
                        stream<<decks[i]->cards[j]->positive<<" "<<decks[i]->cards[j]->negative<<endl;
                    }

                }
            }
        }
    }
    close();
}
