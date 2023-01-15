#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define STAGE_START 0
#define STAGE_STUDY1 1
#define STAGE_STUDY2 2
#define STAGE_STUDY 3
#define STAGE_STUDYING 4
#define STAGE_STUDYING2 5
#define MARK 7
#define STAGE_STUDYING1 6
#include <QMainWindow>
#include<QStandardItemModel>
#include<QTableView>
#include<QMenu>
#include<QCloseEvent>
#include<QPoint>
#include<QPushButton>
#include<QCursor>
#include<QToolButton>
#include"labels.h"
#include"decks.h"
#include"button.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int stageid;
    explicit MainWindow(QWidget *parent = 0);
    void Initestage(int stageid);
    void updatedeck0();

    void selectedcard(deck*currentdeck);
public:
    button* button_create;
    button* button_import;
    button* button_study;
    QFont font;
    label* label_cardset;
    label* label_unstudy;
    label* label_ontime;
    label* label_studying;
    label*positive;
    label*negative;
    label* Label;
    label*markimg;
    label*blue;
    label*green;
    label*pink;
    label*orange;
    label*red;
    label*purple;
    QWidget*studytable;
    button*currentbutton;
    QPoint p;
     QMenu *menu;
     QMenu*moremenu;
     QMenu*flagmenu;
    ~MainWindow();
public slots:
    void onhover(const QModelIndex & index);
    void onclicked(const QModelIndex & index);
private slots:
    void on_action_X_triggered();

    void on_action_G_triggered();

    void on_action_I_triggered();

    void on_action_E_triggered();
    void on_button_create_triggerd();
    void on_toolButton_clicked();
    void mouseMoveEvent(QMouseEvent*E);
    void on_edit();
    void on_butonstudy_clicked();
    void on_ans_clicked();
    void on_toolButton_2_clicked();
    void updatedeck1();
    void updatedeck2();
    void updatedeck3();
    void updatedeck4();
    void initmenu();
    void initmore();
    void mark();
    void blue1();
    void green1();
    void orange1();
    void pink1();
    void purple1();
    void red1();
    void unmark();
    void flags();
    void unflag();
    void pause();
    void deletedeck();
    void deletecard();
    void renamedecks();
    void on_action_triggered();
    void on_action_4_triggered();
    void studyplans();
    void on_toolButton_3_clicked();

    void on_toolButton_4_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
