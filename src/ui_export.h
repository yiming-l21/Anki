/********************************************************************************
** Form generated from reading UI file 'export.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORT_H
#define UI_EXPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Export
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QComboBox *comboBox;

    void setupUi(QDialog *Export)
    {
        if (Export->objectName().isEmpty())
            Export->setObjectName(QStringLiteral("export"));
        Export->resize(469, 406);
        pushButton = new QPushButton(Export);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(290, 360, 156, 31));
        QFont font;
        font.setFamily(QStringLiteral("Adobe Arabic"));
        font.setPointSize(11);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(Export);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(100, 360, 156, 31));
        pushButton_2->setFont(font);
        comboBox = new QComboBox(Export);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(180, 15, 281, 25));

        retranslateUi(Export);

        QMetaObject::connectSlotsByName(Export);
    } // setupUi

    void retranslateUi(QDialog *Export)
    {
        Export->setWindowTitle(QApplication::translate("export", "Export", 0));
        pushButton->setText(QApplication::translate("export", "Cancel", 0));
        pushButton_2->setText(QApplication::translate("export", "export", 0));
    } // retranslateUi

};

namespace Ui {
    class Export: public Ui_export {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORT_H
