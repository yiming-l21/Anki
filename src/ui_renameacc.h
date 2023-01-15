/********************************************************************************
** Form generated from reading UI file 'renameacc.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENAMEACC_H
#define UI_RENAMEACC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_renameacc
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextEdit *textEdit;
    QLabel *label;

    void setupUi(QDialog *renameacc)
    {
        if (renameacc->objectName().isEmpty())
            renameacc->setObjectName(QStringLiteral("renameacc"));
        renameacc->resize(625, 150);
        pushButton = new QPushButton(renameacc);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(340, 110, 120, 31));
        QFont font;
        font.setFamily(QStringLiteral("Adobe Arabic"));
        font.setPointSize(11);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(renameacc);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(480, 110, 120, 31));
        pushButton_2->setFont(font);
        textEdit = new QTextEdit(renameacc);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(30, 60, 570, 30));
        label = new QLabel(renameacc);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 80, 30));
        label->setFont(font);

        retranslateUi(renameacc);

        QMetaObject::connectSlotsByName(renameacc);
    } // setupUi

    void retranslateUi(QDialog *renameacc)
    {
        renameacc->setWindowTitle(QApplication::translate("renameacc", "Dialog", 0));
        pushButton->setText(QApplication::translate("renameacc", "ok", 0));
        pushButton_2->setText(QApplication::translate("renameacc", "cancel", 0));
        label->setText(QApplication::translate("renameacc", "\346\226\260\345\220\215\347\247\260\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class renameacc: public Ui_renameacc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENAMEACC_H
