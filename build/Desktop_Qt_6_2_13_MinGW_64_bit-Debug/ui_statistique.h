/********************************************************************************
** Form generated from reading UI file 'statistique.ui'
**
** Created by: Qt User Interface Compiler version 6.2.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTIQUE_H
#define UI_STATISTIQUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_statistique
{
public:
    QPushButton *pushButton_11;
    QLabel *label;

    void setupUi(QDialog *statistique)
    {
        if (statistique->objectName().isEmpty())
            statistique->setObjectName(QString::fromUtf8("statistique"));
        statistique->resize(895, 700);
        pushButton_11 = new QPushButton(statistique);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(782, 660, 101, 31));
        pushButton_11->setStyleSheet(QString::fromUtf8("QPushButton {\n"
" 	font: 14pt \"Sitka Text\";\n"
"   	background-color: transparent;\n"
"    border: 1px solid  #000000;\n"
"    color: #000000;\n"
"    padding: 5px 5px;\n"
"    border-radius: 5px;\n"
"    transition: background-color 0.3s ease;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	\n"
"	font: 75 italic 14pt \"Sitka Text\";\n"
"    background-color: #transparent;\n"
"	color: #000000;\n"
" 	border: 1px solid  #FFFFFF;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    color: black;\n"
"}"));
        label = new QLabel(statistique);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 850, 600));

        retranslateUi(statistique);

        QMetaObject::connectSlotsByName(statistique);
    } // setupUi

    void retranslateUi(QDialog *statistique)
    {
        statistique->setWindowTitle(QCoreApplication::translate("statistique", "Dialog", nullptr));
        pushButton_11->setText(QCoreApplication::translate("statistique", "Fermer", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class statistique: public Ui_statistique {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTIQUE_H
