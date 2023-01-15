#ifndef EXPORTDIA_H
#define EXPORTDIA_H

#include <QDialog>
#include<QComboBox>
namespace Ui {
class EXPORTDIA;
}

class EXPORTDIA : public QDialog
{
    Q_OBJECT

public:
    QComboBox*combobox;
    explicit EXPORTDIA(QWidget *parent = 0);
    ~EXPORTDIA();

private:
    Ui::EXPORTDIA *ui;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // EXPORTDIA_H
