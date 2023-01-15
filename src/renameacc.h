#ifndef RENAMEACC_H
#define RENAMEACC_H

#include <QDialog>

namespace Ui {
class renameacc;
}

class renameacc : public QDialog
{
    Q_OBJECT

public:
    explicit renameacc(QWidget *parent = 0);
    ~renameacc();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::renameacc *ui;
};

#endif // RENAMEACC_H
