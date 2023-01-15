#ifndef SELECTDECK_H
#define SELECTDECK_H

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
class selectdeck;
}

class selectdeck : public QDialog
{
    Q_OBJECT

public:
    explicit selectdeck(QWidget *parent = 0);
    void showstage();
    void showselectedstage();
    QStandardItemModel *model ;
    QTableView *view;
    QString input;
    ~selectdeck();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_textEdit_textChanged();

private:
    Ui::selectdeck *ui;
};

#endif // SELECTDECK_H
