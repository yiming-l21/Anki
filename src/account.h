#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "myaccount.h"
#include <QtSql/QSqlDatabase>
#include <QDialog>
#include<QTableView>
#include <QItemSelectionModel>
#include<vector>
#include<QStandardItemModel>
using namespace std;
namespace Ui {
class account;
}

class account : public QDialog
{
    Q_OBJECT

public:
    explicit account(QWidget *parent = 0);
    ~account();
    void showstage();
    QTableView*a1;
    QStandardItemModel *model ;
    vector<myaccount*>accounts;

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::account *ui;
};

#endif // ACCOUNT_H
