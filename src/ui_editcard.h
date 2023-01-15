/********************************************************************************
** Form generated from reading UI file 'editcard.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITCARD_H
#define UI_EDITCARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_editcard
{
public:
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QFrame *line;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_2;

    void setupUi(QDialog *editcard)
    {
        if (editcard->objectName().isEmpty())
            editcard->setObjectName(QStringLiteral("editcard"));
        editcard->resize(590, 630);
        pushButton = new QPushButton(editcard);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(470, 580, 93, 31));
        QFont font;
        font.setFamily(QStringLiteral("Adobe Arabic"));
        font.setPointSize(11);
        pushButton->setFont(font);
        textEdit = new QTextEdit(editcard);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(100, 520, 461, 31));
        line = new QFrame(editcard);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(20, 100, 531, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(editcard);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 120, 50, 30));
        label->setFont(font);
        label_2 = new QLabel(editcard);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 520, 50, 30));
        label_2->setFont(font);
        label_3 = new QLabel(editcard);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 320, 50, 30));
        label_3->setFont(font);
        pushButton_2 = new QPushButton(editcard);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(40, 40, 500, 30));
        pushButton_2->setFont(font);

        retranslateUi(editcard);

        QMetaObject::connectSlotsByName(editcard);
    } // setupUi

    void retranslateUi(QDialog *editcard)
    {
        editcard->setWindowTitle(QApplication::translate("editcard", "Dialog", 0));
        pushButton->setText(QApplication::translate("editcard", "close", 0));
        label->setText(QApplication::translate("editcard", "\346\255\243\351\235\242", 0));
        label_2->setText(QApplication::translate("editcard", "\346\240\207\347\255\276\357\274\232", 0));
        label_3->setText(QApplication::translate("editcard", "\345\217\215\351\235\242", 0));
        pushButton_2->setText(QApplication::translate("editcard", "\345\255\227\344\275\223", 0));
    } // retranslateUi

};

namespace Ui {
    class editcard: public Ui_editcard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITCARD_H
