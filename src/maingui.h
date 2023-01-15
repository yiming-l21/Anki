#ifndef MAINGUI_H
#define MAINGUI_H

#include <QWidget>

namespace Ui {
class maingui;
}

class maingui : public QWidget
{
    Q_OBJECT

public:
    explicit maingui(QWidget *parent = 0);
    ~maingui();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

public slots:
    void showmainwindow( );

private:
    Ui::maingui *ui;
};

#endif // MAINGUI_H
