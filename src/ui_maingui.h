/********************************************************************************
** Form generated from reading UI file 'maingui.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINGUI_H
#define UI_MAINGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_maingui
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *maingui)
    {
        if (maingui->objectName().isEmpty())
            maingui->setObjectName(QStringLiteral("maingui"));
        maingui->resize(961, 791);
        pushButton = new QPushButton(maingui);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(350, 720, 93, 31));
        QFont font;
        font.setFamily(QStringLiteral("Adobe Arabic"));
        font.setPointSize(11);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(maingui);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(510, 720, 93, 31));
        pushButton_2->setFont(font);

        retranslateUi(maingui);

        QMetaObject::connectSlotsByName(maingui);
    } // setupUi

    void retranslateUi(QWidget *maingui)
    {
        maingui->setWindowTitle(QApplication::translate("maingui", "Form", 0));
        pushButton->setText(QApplication::translate("maingui", "\345\210\233\345\273\272\347\211\214\347\273\204", 0));
        pushButton_2->setText(QApplication::translate("maingui", "\345\257\274\345\205\245\347\211\214\347\273\204", 0));
    } // retranslateUi

};

namespace Ui {
    class maingui: public Ui_maingui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINGUI_H
