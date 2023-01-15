#ifndef STATICS_H
#define STATICS_H

#include <QDialog>
#include<QComboBox>
#include<QTableView>
#include<QStandardItemModel>
#include"decks.h"
namespace Ui {
class statics;
}

class statics : public QDialog
{
    Q_OBJECT

public:
    explicit statics(QWidget *parent = 0);
    ~statics();
    QComboBox*comb;
    QComboBox*comb1;
    QTableView* view;
    QStandardItemModel*model;

    deck* sorting(deck*a,int type);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::statics *ui;
};

#endif // STATICS_H
