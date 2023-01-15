/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_I;
    QAction *action_E;
    QAction *action_X;
    QAction *action_Z;
    QAction *action;
    QAction *action_3;
    QAction *action_P;
    QAction *action_G;
    QAction *action_4;
    QWidget *centralWidget;
    QFrame *line;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu_F;
    QMenu *menu_T;
    QMenu *menu_H;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 850);
        MainWindow->setAnimated(true);
        MainWindow->setTabShape(QTabWidget::Rounded);
        action_I = new QAction(MainWindow);
        action_I->setObjectName(QStringLiteral("action_I"));
        action_E = new QAction(MainWindow);
        action_E->setObjectName(QStringLiteral("action_E"));
        action_X = new QAction(MainWindow);
        action_X->setObjectName(QStringLiteral("action_X"));
        action_Z = new QAction(MainWindow);
        action_Z->setObjectName(QStringLiteral("action_Z"));
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QStringLiteral("action_3"));
        action_P = new QAction(MainWindow);
        action_P->setObjectName(QStringLiteral("action_P"));
        action_G = new QAction(MainWindow);
        action_G->setObjectName(QStringLiteral("action_G"));
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QStringLiteral("action_4"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(-10, 37, 1031, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        toolButton = new QToolButton(centralWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(410, 10, 62, 25));
        toolButton_2 = new QToolButton(centralWidget);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setGeometry(QRect(290, 10, 62, 25));
        toolButton_3 = new QToolButton(centralWidget);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setGeometry(QRect(530, 10, 62, 25));
        toolButton_4 = new QToolButton(centralWidget);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setGeometry(QRect(650, 10, 62, 25));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 17));
        menu_F = new QMenu(menuBar);
        menu_F->setObjectName(QStringLiteral("menu_F"));
        menu_T = new QMenu(menuBar);
        menu_T->setObjectName(QStringLiteral("menu_T"));
        menu_H = new QMenu(menuBar);
        menu_H->setObjectName(QStringLiteral("menu_H"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu_F->menuAction());
        menuBar->addAction(menu_T->menuAction());
        menuBar->addAction(menu_H->menuAction());
        menu_F->addAction(action_I);
        menu_F->addAction(action_E);
        menu_F->addAction(action_X);
        menu_T->addAction(action);
        menu_T->addAction(action_4);
        menu_H->addAction(action_G);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "anki_", 0));
        action_I->setText(QApplication::translate("MainWindow", "\345\257\274\345\205\245(&I)", 0));
        action_E->setText(QApplication::translate("MainWindow", "\345\257\274\345\207\272(&E)", 0));
        action_X->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272(&X)            ", 0));
        action_Z->setText(QApplication::translate("MainWindow", "\346\222\244\351\224\200(&Z)", 0));
        action->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\344\270\200\344\270\252\347\211\214\347\273\204\345\255\246\344\271\240", 0));
        action_3->setText(QApplication::translate("MainWindow", "\347\256\241\347\220\206\347\254\224\350\256\260\346\250\241\346\235\277", 0));
        action_P->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256(&P)", 0));
        action_G->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\346\211\213\345\206\214(&G)", 0));
        action_4->setText(QApplication::translate("MainWindow", "\345\255\246\344\271\240\350\256\241\345\210\222", 0));
        toolButton->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240", 0));
        toolButton_2->setText(QApplication::translate("MainWindow", "\347\211\214\347\273\204", 0));
        toolButton_3->setText(QApplication::translate("MainWindow", "\346\265\217\350\247\210", 0));
        toolButton_4->setText(QApplication::translate("MainWindow", "\347\273\237\350\256\241", 0));
        menu_F->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", 0));
        menu_T->setTitle(QApplication::translate("MainWindow", "\345\267\245\345\205\267(&T)", 0));
        menu_H->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
