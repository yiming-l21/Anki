/********************************************************************************
** Form generated from reading UI file 'selectstudy.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTSTUDY_H
#define UI_SELECTSTUDY_H

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

class Ui_selectstudy
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QTextEdit *textEdit;
    QLabel *label;

    void setupUi(QDialog *selectstudy)
    {
        if (selectstudy->objectName().isEmpty())
            selectstudy->setObjectName(QStringLiteral("selectstudy"));
        selectstudy->resize(590, 480);
        QFont font;
        font.setFamily(QStringLiteral("Adobe Arabic"));
        font.setPointSize(10);
        selectstudy->setFont(font);
        pushButton = new QPushButton(selectstudy);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(210, 420, 93, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Adobe Arabic"));
        font1.setPointSize(11);
        pushButton->setFont(font1);
        pushButton_2 = new QPushButton(selectstudy);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(330, 420, 93, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Adobe Arabic"));
        font2.setPointSize(12);
        pushButton_2->setFont(font2);
        pushButton_3 = new QPushButton(selectstudy);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(450, 420, 93, 31));
        pushButton_3->setFont(font1);
        textEdit = new QTextEdit(selectstudy);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(130, 20, 421, 30));
        label = new QLabel(selectstudy);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 20, 50, 31));
        QFont font3;
        font3.setFamily(QStringLiteral("Adobe Arabic"));
        font3.setPointSize(9);
        label->setFont(font3);

        retranslateUi(selectstudy);

        QMetaObject::connectSlotsByName(selectstudy);
    } // setupUi

    void retranslateUi(QDialog *selectstudy)
    {
        selectstudy->setWindowTitle(QApplication::translate("selectstudy", "Dialog", 0));
        pushButton->setText(QApplication::translate("selectstudy", "\351\200\211\346\213\251", 0));
        pushButton_2->setText(QApplication::translate("selectstudy", "\346\267\273\345\212\240", 0));
        pushButton_3->setText(QApplication::translate("selectstudy", "cancel", 0));
        label->setText(QApplication::translate("selectstudy", "\347\255\233\351\200\211\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class selectstudy: public Ui_selectstudy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTSTUDY_H
