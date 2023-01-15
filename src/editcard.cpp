#include "editcard.h"
#include "ui_editcard.h"
#include"global.h"
#include<QTextEdit>
#include<QObject>
#include<QFontDialog>
editcard::editcard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editcard)
{
    ui->setupUi(this);
    this->setWindowTitle("编辑");
    pos=new QTextEdit(this);
    pos->move(40,150);
    pos->setText(currentdeck->currentcard->positive);
    pos->resize(520,160);
    pos->show();
    neg=new QTextEdit(this);
    neg->move(40,350);
    neg->setText(currentdeck->currentcard->negative);
    neg->resize(520,160);
    neg->show();
    ui->textEdit->setText(currentdeck->currentcard->label);
    QObject::connect(pos,SIGNAL(textChanged()),this,SLOT(on_pos_changed()));
    QObject::connect(neg,SIGNAL(textChanged()),this,SLOT(on_neg_changed()));

}

editcard::~editcard()
{
    delete ui;
}
void editcard::on_neg_changed()
{
    nega=neg->toPlainText();
    currentdeck->currentcard->negative=nega;
    point->Initestage(STAGE_STUDYING);
}
void editcard::on_pos_changed()
{
    posi=pos->toPlainText();
    currentdeck->currentcard->positive=posi;
    point->Initestage(STAGE_STUDYING);
}

void editcard::on_textEdit_textChanged()
{
    currentdeck->currentcard->label=ui->textEdit->toPlainText();
    point->Initestage(STAGE_STUDYING);
}

void editcard::on_pushButton_clicked()
{
    close();
}

void editcard::on_pushButton_2_clicked()
{
    bool ok;
   QFont font=QFontDialog::getFont(&ok);
    ui->textEdit->setFont(font);
    pos->setFont(font);
    neg->setFont(font);
}
