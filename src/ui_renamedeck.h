/********************************************************************************
** Form generated from reading UI file 'renamedeck.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENAMEDECK_H
#define UI_RENAMEDECK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_renamedeck
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *renamedeck)
    {
        if (renamedeck->objectName().isEmpty())
            renamedeck->setObjectName(QStringLiteral("renamedeck"));
        renamedeck->resize(625, 150);
        pushButton = new QPushButton(renamedeck);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(340, 110, 120, 31));
        QFont font;
        font.setFamily(QStringLiteral("Adobe Arabic"));
        font.setPointSize(11);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(renamedeck);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(480, 110, 120, 31));
        pushButton_2->setFont(font);

        retranslateUi(renamedeck);

        QMetaObject::connectSlotsByName(renamedeck);
    } // setupUi

    void retranslateUi(QDialog *renamedeck)
    {
        renamedeck->setWindowTitle(QApplication::translate("renamedeck", "Dialog", 0));
        pushButton->setText(QApplication::translate("renamedeck", "ok", 0));
        pushButton_2->setText(QApplication::translate("renamedeck", "cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class renamedeck: public Ui_renamedeck {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENAMEDECK_H
