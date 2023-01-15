#include "helpmanual.h"
#include "ui_helpmanual.h"

helpmanual::helpmanual(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::helpmanual)
{
    ui->setupUi(this);
}

helpmanual::~helpmanual()
{
    delete ui;
}

void helpmanual::on_pushButton_clicked()
{
    close();
}
