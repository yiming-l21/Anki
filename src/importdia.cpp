#include "importdia.h"
#include "ui_importdia.h"

importdia::importdia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::importdia)
{
    ui->setupUi(this);
    this->textEdit=new QTextEdit(this);
    this->textEdit->resize(671,521);
    this->textEdit->move(40,30);
    this->textEdit->setReadOnly(true);
    this->textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    this->textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    this->textEdit->show();
}

importdia::~importdia()
{
    delete ui;
}

void importdia::on_pushButton_clicked()
{
    close();
}
