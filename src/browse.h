#ifndef BROWSE_H
#define BROWSE_H

#include <QDialog>
#include<QTableView>
#include<QStandardItemModel>
namespace Ui {
class browse;
}

class browse : public QDialog
{
    Q_OBJECT

public:
    explicit browse(QWidget *parent = 0);
    ~browse();
    QTableView* view;
    QStandardItemModel*model;
    void refresh();
private slots:
    void initdeck(QModelIndex index);
    void refreshtext(QModelIndex index);
    void on_textEdit_2_textChanged();


    void on_textEdit_3_textChanged();


    void on_textEdit_4_textChanged();

private:
    Ui::browse *ui;
};

#endif // BROWSE_H
