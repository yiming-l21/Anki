/********************************************************************************
** Form generated from reading UI file 'exportdia.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORTDIA_H
#define UI_EXPORTDIA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EXPORTDIA
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QComboBox *comboBox;

    void setupUi(QDialog *EXPORTDIA)
    {
        if (EXPORTDIA->objectName().isEmpty())
            EXPORTDIA->setObjectName(QStringLiteral("EXPORTDIA"));
        EXPORTDIA->resize(469, 260);
        pushButton = new QPushButton(EXPORTDIA);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(300, 210, 156, 31));
        QFont font;
        font.setFamily(QStringLiteral("Adobe Arabic"));
        font.setPointSize(11);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(EXPORTDIA);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(130, 210, 156, 31));
        pushButton_2->setFont(font);
        comboBox = new QComboBox(EXPORTDIA);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(180, 15, 281, 25));

        retranslateUi(EXPORTDIA);

        QMetaObject::connectSlotsByName(EXPORTDIA);
    } // setupUi

    void retranslateUi(QDialog *EXPORTDIA)
    {
        EXPORTDIA->setWindowTitle(QApplication::translate("EXPORTDIA", "export", 0));
        pushButton->setText(QApplication::translate("EXPORTDIA", "Cancel", 0));
        pushButton_2->setText(QApplication::translate("EXPORTDIA", "export", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("EXPORTDIA", "\347\272\257\346\226\207\346\234\254\346\240\274\345\274\217\347\232\204\345\215\241\347\211\207(*txt)", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class EXPORTDIA: public Ui_EXPORTDIA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTDIA_H
