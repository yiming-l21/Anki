#include "Export.h"
#include "ui_export.h"

Export::Export(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Export)
{
    ui->setupUi(this);
}
void Export::on_pushButton_clicked()
{
    close();
}
Export::~Export()
{
delete ui;
}
