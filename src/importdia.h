#ifndef IMPORTDIA_H
#define IMPORTDIA_H

#include <QDialog>
#include<QTextEdit>
namespace Ui {
class importdia;
}

class importdia : public QDialog
{
    Q_OBJECT

public:
    QTextEdit*textEdit;
    explicit importdia(QWidget *parent = 0);
    ~importdia();

private slots:
    void on_pushButton_clicked();

private:
    Ui::importdia *ui;
};

#endif // IMPORTDIA_H
