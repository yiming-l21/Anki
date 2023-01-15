#ifndef CREATEACCOUNT_H
#define CREATEACCOUNT_H

#include <QDialog>

namespace Ui {
class createaccount;
}

class createaccount : public QDialog
{
    Q_OBJECT

public:
    explicit createaccount(QWidget *parent = 0);
    ~createaccount();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::createaccount *ui;
};

#endif // CREATEACCOUNT_H
