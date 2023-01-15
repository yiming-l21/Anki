/********************************************************************************
** Form generated from reading UI file 'createcardset.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECARDSET_H
#define UI_CREATECARDSET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_createcardset
{
public:
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextEdit *textEdit;

    void setupUi(QDialog *createcardset)
    {
        if (createcardset->objectName().isEmpty())
            createcardset->setObjectName(QStringLiteral("createcardset"));
        createcardset->resize(625, 150);
        buttonBox = new QDialogButtonBox(createcardset);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        pushButton = new QPushButton(createcardset);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(480, 110, 120, 31));
        QFont font;
        font.setFamily(QStringLiteral("Adobe Arabic"));
        font.setPointSize(12);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(createcardset);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(340, 110, 120, 31));
        pushButton_2->setFont(font);
        textEdit = new QTextEdit(createcardset);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(30, 60, 570, 30));

        retranslateUi(createcardset);
        QObject::connect(buttonBox, SIGNAL(accepted()), createcardset, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), createcardset, SLOT(reject()));

        QMetaObject::connectSlotsByName(createcardset);
    } // setupUi

    void retranslateUi(QDialog *createcardset)
    {
        createcardset->setWindowTitle(QApplication::translate("createcardset", "anki_", 0));
        pushButton->setText(QApplication::translate("createcardset", "Cancel", 0));
        pushButton_2->setText(QApplication::translate("createcardset", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class createcardset: public Ui_createcardset {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECARDSET_H
