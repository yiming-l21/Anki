/********************************************************************************
** Form generated from reading UI file 'account.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNT_H
#define UI_ACCOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_account
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;

    void setupUi(QDialog *account)
    {
        if (account->objectName().isEmpty())
            account->setObjectName(QStringLiteral("account"));
        account->resize(600, 625);
        QFont font;
        font.setFamily(QStringLiteral("Adobe Arabic"));
        font.setPointSize(11);
        account->setFont(font);
        pushButton = new QPushButton(account);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(420, 30, 151, 31));
        pushButton_2 = new QPushButton(account);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(420, 90, 151, 31));
        pushButton_3 = new QPushButton(account);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(420, 150, 151, 31));
        pushButton_4 = new QPushButton(account);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(420, 210, 151, 31));
        pushButton_5 = new QPushButton(account);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(420, 270, 151, 31));

        retranslateUi(account);

        QMetaObject::connectSlotsByName(account);
    } // setupUi

    void retranslateUi(QDialog *account)
    {
        account->setWindowTitle(QApplication::translate("account", "\350\264\246\346\210\267", 0));
        pushButton->setText(QApplication::translate("account", "\346\211\223\345\274\200", 0));
        pushButton_2->setText(QApplication::translate("account", "\346\267\273\345\212\240", 0));
        pushButton_3->setText(QApplication::translate("account", "\351\207\215\345\221\275\345\220\215", 0));
        pushButton_4->setText(QApplication::translate("account", "\345\210\240\351\231\244", 0));
        pushButton_5->setText(QApplication::translate("account", "\351\200\200\345\207\272", 0));
    } // retranslateUi

};

namespace Ui {
    class account: public Ui_account {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNT_H
