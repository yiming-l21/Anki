/********************************************************************************
** Form generated from reading UI file 'append.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPEND_H
#define UI_APPEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_append
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;

    void setupUi(QDialog *append)
    {
        if (append->objectName().isEmpty())
            append->setObjectName(QStringLiteral("append"));
        append->resize(680, 550);
        QFont font;
        font.setFamily(QStringLiteral("Adobe Arabic"));
        font.setPointSize(10);
        append->setFont(font);
        pushButton = new QPushButton(append);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(410, 500, 93, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Adobe Arabic"));
        font1.setPointSize(11);
        pushButton->setFont(font1);
        pushButton_2 = new QPushButton(append);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(560, 500, 93, 31));
        pushButton_2->setFont(font1);
        pushButton_4 = new QPushButton(append);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(400, 15, 250, 31));
        pushButton_4->setFont(font);
        textEdit = new QTextEdit(append);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(33, 90, 611, 64));
        textEdit_2 = new QTextEdit(append);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(33, 200, 611, 64));
        textEdit_3 = new QTextEdit(append);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(80, 403, 571, 31));

        retranslateUi(append);

        QMetaObject::connectSlotsByName(append);
    } // setupUi

    void retranslateUi(QDialog *append)
    {
        append->setWindowTitle(QApplication::translate("append", "\346\267\273\345\212\240", 0));
        pushButton->setText(QApplication::translate("append", "\346\267\273\345\212\240", 0));
        pushButton_2->setText(QApplication::translate("append", "\345\205\263\351\227\255", 0));
        pushButton_4->setText(QApplication::translate("append", "\351\200\211\346\213\251\345\255\227\344\275\223", 0));
    } // retranslateUi

};

namespace Ui {
    class append: public Ui_append {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPEND_H
