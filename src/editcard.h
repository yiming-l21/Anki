#ifndef EDITCARD_H
#define EDITCARD_H

#include <QDialog>
#include<QString>
#include<QTextEdit>
namespace Ui {
class editcard;
}

class editcard : public QDialog
{
    Q_OBJECT

public:
    explicit editcard(QWidget *parent = 0);
    ~editcard();
    QTextEdit* pos;
    QTextEdit*neg;
    QString posi;
    QString nega;
private slots:
    void on_pos_changed();
    void on_neg_changed();
    void on_textEdit_textChanged();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::editcard *ui;
};

#endif // EDITCARD_H
