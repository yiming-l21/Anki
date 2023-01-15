/********************************************************************************
** Form generated from reading UI file 'browse.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BROWSE_H
#define UI_BROWSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_browse
{
public:
    QFrame *line;
    QWidget *widget;
    QLabel *label;
    QTextEdit *textEdit_2;
    QLabel *label_2;
    QTextEdit *textEdit_3;
    QLabel *label_3;
    QTextEdit *textEdit_4;
    QTreeView *treeView;

    void setupUi(QDialog *browse)
    {
        if (browse->objectName().isEmpty())
            browse->setObjectName(QStringLiteral("browse"));
        browse->resize(1200, 700);
        line = new QFrame(browse);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(343, 50, 20, 651));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        widget = new QWidget(browse);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(370, 20, 801, 350));
        label = new QLabel(browse);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(380, 390, 80, 30));
        QFont font;
        font.setFamily(QStringLiteral("Adobe Arabic"));
        font.setPointSize(11);
        label->setFont(font);
        textEdit_2 = new QTextEdit(browse);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(370, 420, 801, 40));
        label_2 = new QLabel(browse);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(380, 490, 80, 30));
        label_2->setFont(font);
        textEdit_3 = new QTextEdit(browse);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(370, 520, 801, 40));
        label_3 = new QLabel(browse);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(380, 570, 80, 30));
        label_3->setFont(font);
        textEdit_4 = new QTextEdit(browse);
        textEdit_4->setObjectName(QStringLiteral("textEdit_4"));
        textEdit_4->setGeometry(QRect(370, 610, 801, 40));
        treeView = new QTreeView(browse);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setGeometry(QRect(10, 20, 331, 671));

        retranslateUi(browse);

        QMetaObject::connectSlotsByName(browse);
    } // setupUi

    void retranslateUi(QDialog *browse)
    {
        browse->setWindowTitle(QApplication::translate("browse", "browse", 0));
        label->setText(QApplication::translate("browse", "\346\255\243\351\235\242\357\274\232", 0));
        label_2->setText(QApplication::translate("browse", "\345\217\215\351\235\242\357\274\232", 0));
        label_3->setText(QApplication::translate("browse", "\346\240\207\347\255\276\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class browse: public Ui_browse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BROWSE_H
