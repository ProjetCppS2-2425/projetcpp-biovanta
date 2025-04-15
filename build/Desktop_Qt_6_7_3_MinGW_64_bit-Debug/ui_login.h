/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame_2;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QPushButton *connectionButton;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label;
    QFrame *frame;
    QLabel *logo1;
    QLabel *label_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1477, 657);
        MainWindow->setStyleSheet(QString::fromUtf8("#lineEdit{color: white;}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(0, 0, 741, 621));
        frame_2->setMinimumSize(QSize(741, 0));
        frame_2->setStyleSheet(QString::fromUtf8("QFrame#frame_2{\n"
"    background-color: white;\n"
"    border-radius: 10px;\n"
"    padding: 20px;\n"
"}\n"
""));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 169, 331, 51));
        label_2->setStyleSheet(QString::fromUtf8("QLabel#label_2 {\n"
"    font-size: 30px;\n"
"    font-weight: bold;\n"
"    color: #333;\n"
"}\n"
""));
        label_3 = new QLabel(frame_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(90, 210, 591, 51));
        label_3->setStyleSheet(QString::fromUtf8("QLabel#label_3 {\n"
"    font-size: 20px;\n"
"    font-weight: bold;\n"
"    color: #2C8D7A;\n"
"}\n"
""));
        lineEdit = new QLineEdit(frame_2);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(100, 300, 371, 51));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"}"));
        connectionButton = new QPushButton(frame_2);
        connectionButton->setObjectName("connectionButton");
        connectionButton->setGeometry(QRect(100, 500, 371, 41));
        connectionButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C8D7A;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 10px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #247361;\n"
"}\n"
""));
        label_4 = new QLabel(frame_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(140, 570, 321, 20));
        label_4->setStyleSheet(QString::fromUtf8("color: black;"));
        lineEdit_2 = new QLineEdit(frame_2);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(100, 400, 371, 51));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"}"));
        lineEdit_2->setEchoMode(QLineEdit::EchoMode::Password);
        label_9 = new QLabel(frame_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(100, 270, 191, 20));
        label_9->setStyleSheet(QString::fromUtf8("color: black;"));
        label_10 = new QLabel(frame_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(100, 370, 191, 20));
        label_10->setStyleSheet(QString::fromUtf8("color: black;"));
        label = new QLabel(frame_2);
        label->setObjectName("label");
        label->setGeometry(QRect(340, 460, 171, 20));
        label->setStyleSheet(QString::fromUtf8("QLabel#label {\n"
"    \n"
"    color: #d70303;\n"
"}\n"
""));
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(720, 0, 751, 621));
        frame->setStyleSheet(QString::fromUtf8("QFrame#frame {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #0E3A47, stop:1 #104F52);\n"
"    border-radius: 10px;\n"
"    padding: 40px;\n"
"    color: white;\n"
"}\n"
""));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        logo1 = new QLabel(frame);
        logo1->setObjectName("logo1");
        logo1->setGeometry(QRect(170, 70, 461, 461));
        logo1->setStyleSheet(QString::fromUtf8("QLabel#label_2 {\n"
"    font-size: 30px;\n"
"    font-weight: bold;\n"
"    color: #333;\n"
"}\n"
""));
        logo1->setPixmap(QPixmap(QString::fromUtf8("assets/logo2.png")));
        label_6 = new QLabel(frame);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(230, 480, 421, 51));
        label_6->setSizeIncrement(QSize(10, 0));
        QFont font;
        font.setBold(true);
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("QLabel#label_2 {\n"
"    font-size: 30px;\n"
"    font-weight: bold;\n"
"    color: #333;\n"
"}\n"
""));
        label_6->setTextFormat(Qt::TextFormat::RichText);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1477, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", " Bienvenue !", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Connectez-vous \303\240 votre compte Biovanta", nullptr));
        connectionButton->setText(QCoreApplication::translate("MainWindow", "connection", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", " \302\251 2025 Biovanta ,Tous droits r\303\251serv\303\251s.", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Entrer votre identifiant ", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Entrer votre mot de passe ", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "mot de passe oubli\303\251 ?", nullptr));
        logo1->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "Biovanta \342\200\223 R\303\251volutionnez la Recherche, Simplifiez la Science.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
