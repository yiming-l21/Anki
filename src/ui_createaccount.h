/********************************************************************************
** Form generated from reading UI file 'createaccount.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEACCOUNT_H
#define UI_CREATEACCOUNT_H

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

class Ui_createaccount
{
public:
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QTextEdit *textEdit_2;
    QLabel *label_3;
    QTextEdit *textEdit_3;

    void setupUi(QDialog *createaccount)
    {
        if (createaccount->objectName().isEmpty())
            createaccount->setObjectName(QStringLiteral("createaccount"));
        createaccount->resize(625, 400);
        textEdit = new QTextEdit(createaccount);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(30, 60, 570, 30));
        pushButton = new QPushButton(createaccount);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(340, 350, 120, 31));
        QFont font;
        font.setFamily(QStringLiteral("Adobe Arabic"));
        font.setPointSize(11);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(createaccount);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(480, 350, 120, 31));
        pushButton_2->setFont(font);
        label = new QLabel(createaccount);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 60, 30));
        label->setFont(font);
        label_2 = new QLabel(createaccount);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 120, 60, 30));
        label_2->setFont(font);
        textEdit_2 = new QTextEdit(createaccount);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(30, 150, 570, 30));
        label_3 = new QLabel(createaccount);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 210, 60, 30));
        label_3->setFont(font);
        textEdit_3 = new QTextEdit(createaccount);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(30, 250, 570, 30));

        retranslateUi(createaccount);

        QMetaObject::connectSlotsByName(createaccount);
    } // setupUi

    void retranslateUi(QDialog *createaccount)
    {
        createaccount->setWindowTitle(QApplication::translate("createaccount", "\346\267\273\345\212\240\350\264\246\346\210\267", 0));
        pushButton->setText(QApplication::translate("createaccount", "\346\267\273\345\212\240", 0));
        pushButton_2->setText(QApplication::translate("createaccount", "cancel", 0));
        label->setText(QApplication::translate("createaccount", "\345\220\215\347\247\260\357\274\232", 0));
        label_2->setText(QApplication::translate("createaccount", "\350\264\246\345\217\267\357\274\232", 0));
        label_3->setText(QApplication::translate("createaccount", "\345\257\206\347\240\201\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class createaccount: public Ui_createaccount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEACCOUNT_H
