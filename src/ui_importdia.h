/********************************************************************************
** Form generated from reading UI file 'importdia.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPORTDIA_H
#define UI_IMPORTDIA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_importdia
{
public:
    QPushButton *pushButton;

    void setupUi(QDialog *importdia)
    {
        if (importdia->objectName().isEmpty())
            importdia->setObjectName(QStringLiteral("importdia"));
        importdia->resize(750, 625);
        pushButton = new QPushButton(importdia);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(590, 580, 120, 31));
        QFont font;
        font.setFamily(QStringLiteral("Adobe Arabic"));
        font.setPointSize(11);
        pushButton->setFont(font);

        retranslateUi(importdia);

        QMetaObject::connectSlotsByName(importdia);
    } // setupUi

    void retranslateUi(QDialog *importdia)
    {
        importdia->setWindowTitle(QApplication::translate("importdia", "Dialog", 0));
        pushButton->setText(QApplication::translate("importdia", "close", 0));
    } // retranslateUi

};

namespace Ui {
    class importdia: public Ui_importdia {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPORTDIA_H
