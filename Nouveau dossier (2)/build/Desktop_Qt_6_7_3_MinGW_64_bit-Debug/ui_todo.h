/********************************************************************************
** Form generated from reading UI file 'todo.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TODO_H
#define UI_TODO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Todo
{
public:
    QPushButton *btnAdd;
    QListWidget *listWidget;
    QLineEdit *txtTask;
    QListWidget *listWidget_2;
    QLabel *bg;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *logo;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *Todo)
    {
        if (Todo->objectName().isEmpty())
            Todo->setObjectName("Todo");
        Todo->resize(1092, 611);
        btnAdd = new QPushButton(Todo);
        btnAdd->setObjectName("btnAdd");
        btnAdd->setGeometry(QRect(100, 160, 83, 29));
        listWidget = new QListWidget(Todo);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(30, 210, 521, 361));
        txtTask = new QLineEdit(Todo);
        txtTask->setObjectName("txtTask");
        txtTask->setGeometry(QRect(350, 40, 431, 41));
        listWidget_2 = new QListWidget(Todo);
        listWidget_2->setObjectName("listWidget_2");
        listWidget_2->setGeometry(QRect(590, 210, 481, 361));
        bg = new QLabel(Todo);
        bg->setObjectName("bg");
        bg->setGeometry(QRect(0, 0, 1091, 611));
        label_2 = new QLabel(Todo);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(730, 120, 251, 31));
        label_2->setStyleSheet(QString::fromUtf8("QLabel#label_2{\n"
"color: #000000;\n"
"font-size: 25px;\n"
"}"));
        label = new QLabel(Todo);
        label->setObjectName("label");
        label->setGeometry(QRect(190, 110, 181, 41));
        label->setStyleSheet(QString::fromUtf8("QLabel#label{\n"
"color: #000000;\n"
"font-size: 25px;\n"
"}"));
        label_3 = new QLabel(Todo);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(220, 50, 121, 20));
        label_3->setStyleSheet(QString::fromUtf8("QLabel#label_3{\n"
"color: #000000;\n"
"font-size: 17px;\n"
"}"));
        logo = new QLabel(Todo);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(20, 9, 91, 81));
        pushButton = new QPushButton(Todo);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(240, 160, 83, 29));
        pushButton_2 = new QPushButton(Todo);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(360, 160, 83, 29));
        pushButton_3 = new QPushButton(Todo);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(610, 160, 83, 29));
        pushButton_4 = new QPushButton(Todo);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(720, 160, 83, 29));
        bg->raise();
        btnAdd->raise();
        listWidget->raise();
        txtTask->raise();
        listWidget_2->raise();
        label_2->raise();
        label->raise();
        label_3->raise();
        logo->raise();
        pushButton->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_4->raise();

        retranslateUi(Todo);

        QMetaObject::connectSlotsByName(Todo);
    } // setupUi

    void retranslateUi(QDialog *Todo)
    {
        Todo->setWindowTitle(QCoreApplication::translate("Todo", "Dialog", nullptr));
        btnAdd->setText(QCoreApplication::translate("Todo", "Add", nullptr));
        bg->setText(QString());
        label_2->setText(QCoreApplication::translate("Todo", "T\303\202CHES COMPL\303\211T\303\211ES", nullptr));
        label->setText(QCoreApplication::translate("Todo", "T\303\202CHES \303\200 FAIRE", nullptr));
        label_3->setText(QCoreApplication::translate("Todo", "Nouvelle t\303\242che:", nullptr));
        logo->setText(QString());
        pushButton->setText(QCoreApplication::translate("Todo", "delete", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Todo", "Delete All", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Todo", "Delete", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Todo", "Delete All", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Todo: public Ui_Todo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TODO_H
