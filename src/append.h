#ifndef APPEND_H
#define APPEND_H
#include"button.h"
#include <QDialog>
#include<QCloseEvent>
#include<QMouseEvent>
namespace Ui {
class append;
}

class append : public QDialog
{
    Q_OBJECT

public:
    button *cardbutton;
    explicit append(QWidget *parent = 0);
    ~append();

private slots:
    void on_pushButton_4_clicked();
    void on_cardbutton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();


private:
    Ui::append *ui;
};

#endif // APPEND_H
