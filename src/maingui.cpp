#include "maingui.h"
#include "ui_maingui.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QLabel>
#include<QDialog>
#include "helpmanual.h"
#include"createcardset.h"
#include"exportdia.h"
#include<QFileDialog>
maingui::maingui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::maingui)
{
    ui->setupUi(this);
}

maingui::~maingui()
{
    delete ui;
}

void maingui::on_pushButton_clicked()
{

}
void maingui::showmainwindow( )
{
      move(20,60);
      show();
}
void maingui::on_pushButton_2_clicked()
{
    QString fileName=QFileDialog::getOpenFileName(this,tr("导入"),"D:",tr("按制表符或分号分隔的文本（*txt）"));
}
