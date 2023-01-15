#ifndef STUDYPLAN_H
#define STUDYPLAN_H

#include <QDialog>
#include<QComboBox>

namespace Ui {
class studyplan;
}

class studyplan : public QDialog
{
    Q_OBJECT

public:
    explicit studyplan(QWidget *parent = 0);
    ~studyplan();
    QComboBox*comb;

private slots:
    void on_pushButton_2_clicked();
    void on_change(QString);
    void on_pushButton_clicked();

private:
    Ui::studyplan *ui;
};

#endif // STUDYPLAN_H
