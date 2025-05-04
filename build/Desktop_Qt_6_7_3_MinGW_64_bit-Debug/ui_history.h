/********************************************************************************
** Form generated from reading UI file 'history.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORY_H
#define UI_HISTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_History
{
public:
    QListWidget *ajout;
    QListWidget *modifier;
    QListWidget *supp;
    QLabel *bg;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *logo;

    void setupUi(QDialog *History)
    {
        if (History->objectName().isEmpty())
            History->setObjectName("History");
        History->resize(1403, 638);
        ajout = new QListWidget(History);
        ajout->setObjectName("ajout");
        ajout->setGeometry(QRect(10, 150, 441, 431));
        modifier = new QListWidget(History);
        modifier->setObjectName("modifier");
        modifier->setGeometry(QRect(470, 150, 441, 431));
        supp = new QListWidget(History);
        supp->setObjectName("supp");
        supp->setGeometry(QRect(930, 150, 461, 431));
        bg = new QLabel(History);
        bg->setObjectName("bg");
        bg->setGeometry(QRect(0, 0, 1401, 641));
        bg->setPixmap(QPixmap(QString::fromUtf8("bgbg.jpg")));
        label = new QLabel(History);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 80, 241, 61));
        label->setStyleSheet(QString::fromUtf8("QLabel#label\n"
"{\n"
"color: #000000;\n"
"font-size: 25px;\n"
"}"));
        label_2 = new QLabel(History);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(550, 100, 321, 31));
        label_2->setStyleSheet(QString::fromUtf8("QLabel#label_2{\n"
"color: #000000;\n"
"font-size: 25px;\n"
"}"));
        label_4 = new QLabel(History);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(1020, 100, 321, 31));
        label_4->setStyleSheet(QString::fromUtf8("QLabel#label_4{\n"
"color: #000000;\n"
"font-size: 25px;\n"
"}"));
        logo = new QLabel(History);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(10, 0, 101, 91));
        logo->setPixmap(QPixmap(QString::fromUtf8("logo1.png")));
        bg->raise();
        ajout->raise();
        modifier->raise();
        supp->raise();
        label->raise();
        label_2->raise();
        label_4->raise();
        logo->raise();

        retranslateUi(History);

        QMetaObject::connectSlotsByName(History);
    } // setupUi

    void retranslateUi(QDialog *History)
    {
        History->setWindowTitle(QCoreApplication::translate("History", "Dialog", nullptr));
        bg->setText(QString());
        label->setText(QCoreApplication::translate("History", "Historique des ajouts", nullptr));
        label_2->setText(QCoreApplication::translate("History", "Historique des modifications", nullptr));
        label_4->setText(QCoreApplication::translate("History", "Historique des suppressions", nullptr));
        logo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class History: public Ui_History {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORY_H
