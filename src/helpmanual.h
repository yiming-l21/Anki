#ifndef HELPMANUAL_H
#define HELPMANUAL_H

#include <QDialog>

namespace Ui {
class helpmanual;
}

class helpmanual : public QDialog
{
    Q_OBJECT

public:
    explicit helpmanual(QWidget *parent = 0);
    ~helpmanual();

private slots:
    void on_pushButton_clicked();

private:
    Ui::helpmanual *ui;
};

#endif // HELPMANUAL_H
