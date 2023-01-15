#ifndef RENAMEDECK_H
#define RENAMEDECK_H

#include <QDialog>
#include<QTextEdit>
namespace Ui {
class renamedeck;
}

class renamedeck : public QDialog
{
    Q_OBJECT

public:
    QTextEdit*b;
    explicit renamedeck(QWidget *parent = 0);
    ~renamedeck();
private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();
private:
    Ui::renamedeck *ui;
};

#endif // RENAMEDECK_H
