/********************************************************************************
** Form generated from reading UI file 'selectdeck.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTDECK_H
#define UI_SELECTDECK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_selectdeck
{
public:
    QTextEdit *textEdit;
    QWidget *widget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *selectdeck)
    {
        if (selectdeck->objectName().isEmpty())
            selectdeck->setObjectName(QStringLiteral("selectdeck"));
        selectdeck->resize(590, 480);
        textEdit = new QTextEdit(selectdeck);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(130, 20, 421, 31));
        widget = new QWidget(selectdeck);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(29, 69, 521, 321));
        pushButton = new QPushButton(selectdeck);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(210, 420, 93, 31));
        QFont font;
        font.setFamily(QStringLiteral("Adobe Arabic"));
        font.setPointSize(11);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(selectdeck);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(330, 420, 93, 31));
        pushButton_2->setFont(font);
        pushButton_3 = new QPushButton(selectdeck);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(450, 420, 93, 31));
        pushButton_3->setFont(font);

        retranslateUi(selectdeck);

        QMetaObject::connectSlotsByName(selectdeck);
    } // setupUi

    void retranslateUi(QDialog *selectdeck)
    {
        selectdeck->setWindowTitle(QApplication::translate("selectdeck", "\351\200\211\346\213\251\347\211\214\347\273\204", 0));
        pushButton->setText(QApplication::translate("selectdeck", "\351\200\211\346\213\251", 0));
        pushButton_2->setText(QApplication::translate("selectdeck", "\346\267\273\345\212\240", 0));
        pushButton_3->setText(QApplication::translate("selectdeck", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class selectdeck: public Ui_selectdeck {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTDECK_H
