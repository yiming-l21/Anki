/********************************************************************************
** Form generated from reading UI file 'studyplan.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDYPLAN_H
#define UI_STUDYPLAN_H

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

class Ui_studyplan
{
public:
    QFrame *line;
    QLabel *label;
    QTextEdit *textEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit_4;
    QTextEdit *textEdit_5;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *studyplan)
    {
        if (studyplan->objectName().isEmpty())
            studyplan->setObjectName(QStringLiteral("studyplan"));
        studyplan->resize(600, 500);
        QFont font;
        font.setFamily(QStringLiteral("Adobe Arabic"));
        font.setPointSize(11);
        studyplan->setFont(font);
        line = new QFrame(studyplan);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(1, 70, 601, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(studyplan);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 90, 130, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("Adobe Arabic"));
        font1.setPointSize(9);
        label->setFont(font1);
        textEdit = new QTextEdit(studyplan);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(200, 90, 300, 35));
        label_2 = new QLabel(studyplan);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 160, 130, 40));
        label_2->setFont(font1);
        label_3 = new QLabel(studyplan);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 230, 150, 40));
        label_3->setFont(font1);
        label_4 = new QLabel(studyplan);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 300, 150, 40));
        label_4->setFont(font1);
        label_5 = new QLabel(studyplan);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 370, 150, 40));
        label_5->setFont(font1);
        textEdit_2 = new QTextEdit(studyplan);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(200, 160, 300, 35));
        textEdit_3 = new QTextEdit(studyplan);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(200, 230, 300, 35));
        textEdit_4 = new QTextEdit(studyplan);
        textEdit_4->setObjectName(QStringLiteral("textEdit_4"));
        textEdit_4->setGeometry(QRect(200, 300, 300, 35));
        textEdit_5 = new QTextEdit(studyplan);
        textEdit_5->setObjectName(QStringLiteral("textEdit_5"));
        textEdit_5->setGeometry(QRect(200, 370, 300, 35));
        pushButton = new QPushButton(studyplan);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(370, 450, 93, 31));
        pushButton_2 = new QPushButton(studyplan);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(490, 450, 93, 31));

        retranslateUi(studyplan);

        QMetaObject::connectSlotsByName(studyplan);
    } // setupUi

    void retranslateUi(QDialog *studyplan)
    {
        studyplan->setWindowTitle(QApplication::translate("studyplan", "StudyPlan", 0));
        label->setText(QApplication::translate("studyplan", "\346\257\217\346\227\245\345\215\241\347\211\207\344\270\212\351\231\220\357\274\232", 0));
        label_2->setText(QApplication::translate("studyplan", "\351\200\232\350\277\207\351\230\210\345\200\274\357\274\232", 0));
        label_3->setText(QApplication::translate("studyplan", "\345\233\260\351\232\276\345\215\241\347\211\207\351\227\264\351\232\224\346\227\266\351\227\264\357\274\232", 0));
        label_4->setText(QApplication::translate("studyplan", "\344\270\200\350\210\254\345\215\241\347\211\207\351\227\264\351\232\224\346\227\266\351\227\264\357\274\232", 0));
        label_5->setText(QApplication::translate("studyplan", "\347\256\200\345\215\225\345\215\241\347\211\207\351\227\264\351\232\224\346\227\266\351\227\264\357\274\232", 0));
        pushButton->setText(QApplication::translate("studyplan", "OK", 0));
        pushButton_2->setText(QApplication::translate("studyplan", "cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class studyplan: public Ui_studyplan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDYPLAN_H
