#ifndef SELECTSTUDY_H
#define SELECTSTUDY_H

#include <QDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QLabel>
#include<QDialog>
#include<QString>
#include<QDebug>
#include "helpmanual.h"
#include"createcardset.h"
#include"exportdia.h"
#include<QFileDialog>
#include"maingui.h"
#include"button.h"
#include"labels.h"
#include"card.h"
#include"decks.h"
#include"append.h"
#include<QTableView>
#include <QtSql/QSqlDatabase>
#include"global.h"
#include<QStandardItemModel>
namespace Ui {
class selectstudy;
}

class selectstudy : public QDialog
{
    Q_OBJECT

public:
    explicit selectstudy(QWidget *parent = 0);
    ~selectstudy();
    QStandardItemModel *model ;
    void showstage();
    void showselectedstage();
    QTableView *view;
    QString input;

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_textEdit_textChanged();

    void on_pushButton_clicked();

private:
    Ui::selectstudy *ui;
};

#endif // SELECTSTUDY_H
