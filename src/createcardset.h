#ifndef CREATECARDSET_H
#define CREATECARDSET_H

#include <QDialog>

namespace Ui {
class createcardset;
}

class createcardset : public QDialog
{
    Q_OBJECT

public:
    explicit createcardset(QWidget *parent = 0);
    ~createcardset();

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::createcardset *ui;
};

#endif // CREATECARDSET_H
