/********************************************************************************
** Form generated from reading UI file 'statics.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATICS_H
#define UI_STATICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_statics
{
public:
    QFrame *line;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *widget;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *statics)
    {
        if (statics->objectName().isEmpty())
            statics->setObjectName(QStringLiteral("statics"));
        statics->resize(800, 500);
        line = new QFrame(statics);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(220, 0, 20, 501));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        pushButton = new QPushButton(statics);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 380, 93, 31));
        QFont font;
        font.setFamily(QStringLiteral("Adobe Arabic"));
        font.setPointSize(11);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(statics);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(60, 290, 93, 31));
        pushButton_2->setFont(font);
        widget = new QWidget(statics);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(240, 10, 541, 471));
        label = new QLabel(statics);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 200, 30));
        QFont font1;
        font1.setFamily(QStringLiteral("Adobe Arabic"));
        font1.setPointSize(9);
        label->setFont(font1);
        label_2 = new QLabel(statics);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 130, 200, 30));
        label_2->setFont(font1);

        retranslateUi(statics);

        QMetaObject::connectSlotsByName(statics);
    } // setupUi

    void retranslateUi(QDialog *statics)
    {
        statics->setWindowTitle(QApplication::translate("statics", "Statistics", 0));
        pushButton->setText(QApplication::translate("statics", "\351\200\200\345\207\272", 0));
        pushButton_2->setText(QApplication::translate("statics", "\347\241\256\345\256\232", 0));
        label->setText(QApplication::translate("statics", "\351\200\211\346\213\251\347\211\214\347\273\204\357\274\232", 0));
        label_2->setText(QApplication::translate("statics", "\351\200\211\346\213\251\346\216\222\345\272\217\346\226\271\345\274\217\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class statics: public Ui_statics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATICS_H
