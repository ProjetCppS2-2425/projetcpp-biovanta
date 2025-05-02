/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *sidebare;
    QPushButton *emp1;
    QPushButton *ChercheurButton;
    QPushButton *vac;
    QPushButton *EquipementButton;
    QPushButton *client;
    QPushButton *pushButton_8;
    QLabel *logout;
    QLabel *logout_3;
    QLabel *logo1;
    QPushButton *eq_2;
    QWidget *sidebare_2;
    QPushButton *emp1_2;
    QPushButton *ChercheurButton_2;
    QPushButton *vac_2;
    QPushButton *EquipementButton_2;
    QPushButton *client_2;
    QPushButton *pushButton_11;
    QLabel *logout_2;
    QLabel *label_4;
    QLabel *logo1_2;
    QPushButton *eq_3;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1458, 807);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        sidebare = new QWidget(centralwidget);
        sidebare->setObjectName("sidebare");
        sidebare->setGeometry(QRect(10, -10, 141, 651));
        sidebare->setStyleSheet(QString::fromUtf8("#sidebare {\n"
"    background-color: #2C3E50; /* Couleur bleu fonc\303\251 */\n"
"    border-right: 2px solid #1A252F;\n"
"}QPushButton:hover {\n"
"    background-color: #1ABC9C; /* Vert */\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    background-color: #16A085; /* Vert fonc\303\251 */\n"
"}\n"
"\n"
"/* Sp\303\251cifique au bouton \"\303\211quipement\" */\n"
"QPushButton#btnEquipement {\n"
"    background-color: white;  /* Couleur de fond blanche */\n"
"    color: #34495E;  /* Texte bleu fonc\303\251 */\n"
"}\n"
"\n"
"QPushButton#btnEquipement:hover {\n"
"    background-color: #1ABC9C; /* Vert */\n"
"    color: white;  /* Texte blanc */\n"
"}\n"
"\n"
"QPushButton#btnEquipement:checked {\n"
"    background-color: #16A085; /* Vert fonc\303\251 */\n"
"    color: white;  /* Texte blanc */\n"
"}\n"
""));
        emp1 = new QPushButton(sidebare);
        emp1->setObjectName("emp1");
        emp1->setGeometry(QRect(0, 150, 141, 41));
        emp1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #02767F;  /* Vert fonc\303\251 */\n"
"    color: white;               /* Texte en blanc */\n"
"    border-radius: 5px;         /* Bords arrondis */\n"
"    padding: 10px;              /* Espacement interne */\n"
"    font-weight: bold;          /* Texte en gras */\n"
"    border: none;               /* Supprimer la bordure */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #247361;  /* Vert plus fonc\303\251 au survol */\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../Documents/projet_c/projet_c/empe.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        emp1->setIcon(icon);
        ChercheurButton = new QPushButton(sidebare);
        ChercheurButton->setObjectName("ChercheurButton");
        ChercheurButton->setGeometry(QRect(0, 200, 141, 41));
        ChercheurButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #02767F;  /* Vert fonc\303\251 */\n"
"    color: white;               /* Texte en blanc */\n"
"    border-radius: 5px;         /* Bords arrondis */\n"
"    padding: 10px;              /* Espacement interne */\n"
"    font-weight: bold;          /* Texte en gras */\n"
"    border: none;               /* Supprimer la bordure */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #247361;  /* Vert plus fonc\303\251 au survol */\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../Documents/projet_c/projet_c/cher.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        ChercheurButton->setIcon(icon1);
        vac = new QPushButton(sidebare);
        vac->setObjectName("vac");
        vac->setGeometry(QRect(0, 250, 141, 41));
        vac->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #02767F;  /* Vert fonc\303\251 */\n"
"    color: white;               /* Texte en blanc */\n"
"    border-radius: 5px;         /* Bords arrondis */\n"
"    padding: 10px;              /* Espacement interne */\n"
"    font-weight: bold;          /* Texte en gras */\n"
"    border: none;               /* Supprimer la bordure */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #247361;  /* Vert plus fonc\303\251 au survol */\n"
"}\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../../../Documents/projet_c/projet_c/vaccin.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        vac->setIcon(icon2);
        vac->setIconSize(QSize(20, 20));
        EquipementButton = new QPushButton(sidebare);
        EquipementButton->setObjectName("EquipementButton");
        EquipementButton->setGeometry(QRect(0, 300, 141, 41));
        EquipementButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #02767F;  /* Vert fonc\303\251 */\n"
"    color: white;               /* Texte en blanc */\n"
"    border-radius: 5px;         /* Bords arrondis */\n"
"    padding: 10px;              /* Espacement interne */\n"
"    font-weight: bold;          /* Texte en gras */\n"
"    border: none;               /* Supprimer la bordure */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #247361;  /* Vert plus fonc\303\251 au survol */\n"
"}\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../../../Documents/projet_c/projet_c/equipement.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        EquipementButton->setIcon(icon3);
        client = new QPushButton(sidebare);
        client->setObjectName("client");
        client->setGeometry(QRect(0, 400, 141, 41));
        client->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #02767F;  /* Vert fonc\303\251 */\n"
"    color: white;               /* Texte en blanc */\n"
"    border-radius: 5px;         /* Bords arrondis */\n"
"    padding: 10px;              /* Espacement interne */\n"
"    font-weight: bold;          /* Texte en gras */\n"
"    border: none;               /* Supprimer la bordure */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #247361;  /* Vert plus fonc\303\251 au survol */\n"
"}\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../../../Documents/projet_c/projet_c/client.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        client->setIcon(icon4);
        pushButton_8 = new QPushButton(sidebare);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(30, 550, 111, 31));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_8 {\n"
"    background-color: transparent;\n"
"    color: #E74C3C;  /* Rouge */\n"
"    font-size: 13px;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"    padding: 8px 15px;\n"
"    text-align: left;\n"
"}\n"
"\n"
"QPushButton#pushButton_8:hover {\n"
"    color: #C0392B;  /* Rouge fonc\303\251 au survol */\n"
"}\n"
"\n"
"QPushButton#pushButton_8:pressed {\n"
"    color: #A93226;  /* Encore plus fonc\303\251 au clic */\n"
"}\n"
"\n"
"/* Ajouter une ic\303\264ne \303\240 gauche du texte */\n"
"QPushButton#pushButton_8::before {\n"
"    content: \"\342\217\273 \";  /* Ic\303\264ne de mise hors tension */\n"
"    font-size: 18px;\n"
"    margin-right: 8px;\n"
"}\n"
""));
        logout = new QLabel(sidebare);
        logout->setObjectName("logout");
        logout->setGeometry(QRect(10, 560, 31, 31));
        logout->setStyleSheet(QString::fromUtf8("background-color: #2C3E50;"));
        logout->setPixmap(QPixmap(QString::fromUtf8("../../../Documents/projet_c/application/logout.png")));
        logout_3 = new QLabel(sidebare);
        logout_3->setObjectName("logout_3");
        logout_3->setGeometry(QRect(10, 549, 31, 41));
        logout_3->setStyleSheet(QString::fromUtf8("background-color: #2C3E50;"));
        logout_3->setPixmap(QPixmap(QString::fromUtf8("../../../Documents/projet_c/projet_c/logout.png")));
        logo1 = new QLabel(sidebare);
        logo1->setObjectName("logo1");
        logo1->setGeometry(QRect(20, 50, 111, 91));
        logo1->setStyleSheet(QString::fromUtf8("background-color: #2C3E50;"));
        logo1->setPixmap(QPixmap(QString::fromUtf8("../../../Documents/projet_c/projet_c/logo1.png")));
        eq_2 = new QPushButton(sidebare);
        eq_2->setObjectName("eq_2");
        eq_2->setGeometry(QRect(0, 350, 141, 41));
        eq_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #02767F;  /* Vert fonc\303\251 */\n"
"    color: white;               /* Texte en blanc */\n"
"    border-radius: 5px;         /* Bords arrondis */\n"
"    padding: 10px;              /* Espacement interne */\n"
"    font-weight: bold;          /* Texte en gras */\n"
"    border: none;               /* Supprimer la bordure */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #247361;  /* Vert plus fonc\303\251 au survol */\n"
"}\n"
""));
        eq_2->setIcon(icon3);
        sidebare_2 = new QWidget(sidebare);
        sidebare_2->setObjectName("sidebare_2");
        sidebare_2->setGeometry(QRect(140, 360, 141, 651));
        sidebare_2->setStyleSheet(QString::fromUtf8("#sidebare {\n"
"    background-color: #2C3E50; /* Couleur bleu fonc\303\251 */\n"
"    border-right: 2px solid #1A252F;\n"
"}QPushButton:hover {\n"
"    background-color: #1ABC9C; /* Vert */\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    background-color: #16A085; /* Vert fonc\303\251 */\n"
"}\n"
"\n"
"/* Sp\303\251cifique au bouton \"\303\211quipement\" */\n"
"QPushButton#btnEquipement {\n"
"    background-color: white;  /* Couleur de fond blanche */\n"
"    color: #34495E;  /* Texte bleu fonc\303\251 */\n"
"}\n"
"\n"
"QPushButton#btnEquipement:hover {\n"
"    background-color: #1ABC9C; /* Vert */\n"
"    color: white;  /* Texte blanc */\n"
"}\n"
"\n"
"QPushButton#btnEquipement:checked {\n"
"    background-color: #16A085; /* Vert fonc\303\251 */\n"
"    color: white;  /* Texte blanc */\n"
"}\n"
""));
        emp1_2 = new QPushButton(sidebare_2);
        emp1_2->setObjectName("emp1_2");
        emp1_2->setGeometry(QRect(0, 150, 141, 41));
        emp1_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #02767F;  /* Vert fonc\303\251 */\n"
"    color: white;               /* Texte en blanc */\n"
"    border-radius: 5px;         /* Bords arrondis */\n"
"    padding: 10px;              /* Espacement interne */\n"
"    font-weight: bold;          /* Texte en gras */\n"
"    border: none;               /* Supprimer la bordure */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #247361;  /* Vert plus fonc\303\251 au survol */\n"
"}\n"
""));
        emp1_2->setIcon(icon);
        ChercheurButton_2 = new QPushButton(sidebare_2);
        ChercheurButton_2->setObjectName("ChercheurButton_2");
        ChercheurButton_2->setGeometry(QRect(0, 200, 141, 41));
        ChercheurButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #02767F;  /* Vert fonc\303\251 */\n"
"    color: white;               /* Texte en blanc */\n"
"    border-radius: 5px;         /* Bords arrondis */\n"
"    padding: 10px;              /* Espacement interne */\n"
"    font-weight: bold;          /* Texte en gras */\n"
"    border: none;               /* Supprimer la bordure */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #247361;  /* Vert plus fonc\303\251 au survol */\n"
"}\n"
""));
        ChercheurButton_2->setIcon(icon1);
        vac_2 = new QPushButton(sidebare_2);
        vac_2->setObjectName("vac_2");
        vac_2->setGeometry(QRect(0, 250, 141, 41));
        vac_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #02767F;  /* Vert fonc\303\251 */\n"
"    color: white;               /* Texte en blanc */\n"
"    border-radius: 5px;         /* Bords arrondis */\n"
"    padding: 10px;              /* Espacement interne */\n"
"    font-weight: bold;          /* Texte en gras */\n"
"    border: none;               /* Supprimer la bordure */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #247361;  /* Vert plus fonc\303\251 au survol */\n"
"}\n"
""));
        vac_2->setIcon(icon2);
        vac_2->setIconSize(QSize(20, 20));
        EquipementButton_2 = new QPushButton(sidebare_2);
        EquipementButton_2->setObjectName("EquipementButton_2");
        EquipementButton_2->setGeometry(QRect(0, 300, 141, 41));
        EquipementButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #02767F;  /* Vert fonc\303\251 */\n"
"    color: white;               /* Texte en blanc */\n"
"    border-radius: 5px;         /* Bords arrondis */\n"
"    padding: 10px;              /* Espacement interne */\n"
"    font-weight: bold;          /* Texte en gras */\n"
"    border: none;               /* Supprimer la bordure */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #247361;  /* Vert plus fonc\303\251 au survol */\n"
"}\n"
""));
        EquipementButton_2->setIcon(icon3);
        client_2 = new QPushButton(sidebare_2);
        client_2->setObjectName("client_2");
        client_2->setGeometry(QRect(0, 400, 141, 41));
        client_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #02767F;  /* Vert fonc\303\251 */\n"
"    color: white;               /* Texte en blanc */\n"
"    border-radius: 5px;         /* Bords arrondis */\n"
"    padding: 10px;              /* Espacement interne */\n"
"    font-weight: bold;          /* Texte en gras */\n"
"    border: none;               /* Supprimer la bordure */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #247361;  /* Vert plus fonc\303\251 au survol */\n"
"}\n"
""));
        client_2->setIcon(icon4);
        pushButton_11 = new QPushButton(sidebare_2);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(30, 550, 111, 31));
        pushButton_11->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_8 {\n"
"    background-color: transparent;\n"
"    color: #E74C3C;  /* Rouge */\n"
"    font-size: 13px;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"    padding: 8px 15px;\n"
"    text-align: left;\n"
"}\n"
"\n"
"QPushButton#pushButton_8:hover {\n"
"    color: #C0392B;  /* Rouge fonc\303\251 au survol */\n"
"}\n"
"\n"
"QPushButton#pushButton_8:pressed {\n"
"    color: #A93226;  /* Encore plus fonc\303\251 au clic */\n"
"}\n"
"\n"
"/* Ajouter une ic\303\264ne \303\240 gauche du texte */\n"
"QPushButton#pushButton_8::before {\n"
"    content: \"\342\217\273 \";  /* Ic\303\264ne de mise hors tension */\n"
"    font-size: 18px;\n"
"    margin-right: 8px;\n"
"}\n"
""));
        logout_2 = new QLabel(sidebare_2);
        logout_2->setObjectName("logout_2");
        logout_2->setGeometry(QRect(10, 560, 31, 31));
        logout_2->setStyleSheet(QString::fromUtf8("background-color: #2C3E50;"));
        logout_2->setPixmap(QPixmap(QString::fromUtf8("../../../Documents/projet_c/application/logout.png")));
        label_4 = new QLabel(sidebare_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 549, 31, 41));
        label_4->setStyleSheet(QString::fromUtf8("background-color: #2C3E50;"));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../../../Documents/projet_c/projet_c/logout.png")));
        logo1_2 = new QLabel(sidebare_2);
        logo1_2->setObjectName("logo1_2");
        logo1_2->setGeometry(QRect(20, 50, 111, 91));
        logo1_2->setStyleSheet(QString::fromUtf8("background-color: #2C3E50;"));
        logo1_2->setPixmap(QPixmap(QString::fromUtf8("../../../Documents/projet_c/projet_c/logo1.png")));
        eq_3 = new QPushButton(sidebare_2);
        eq_3->setObjectName("eq_3");
        eq_3->setGeometry(QRect(0, 350, 141, 41));
        eq_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #02767F;  /* Vert fonc\303\251 */\n"
"    color: white;               /* Texte en blanc */\n"
"    border-radius: 5px;         /* Bords arrondis */\n"
"    padding: 10px;              /* Espacement interne */\n"
"    font-weight: bold;          /* Texte en gras */\n"
"    border: none;               /* Supprimer la bordure */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #247361;  /* Vert plus fonc\303\251 au survol */\n"
"}\n"
""));
        eq_3->setIcon(icon3);
        emp1->raise();
        ChercheurButton->raise();
        vac->raise();
        EquipementButton->raise();
        client->raise();
        pushButton_8->raise();
        logout->raise();
        eq_2->raise();
        logo1->raise();
        sidebare_2->raise();
        logout_3->raise();
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(9, -1, 1401, 631));
        page = new QWidget();
        page->setObjectName("page");
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);
        MainWindow->setCentralWidget(centralwidget);
        stackedWidget->raise();
        sidebare->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1458, 26));
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
        emp1->setText(QCoreApplication::translate("MainWindow", "employ\303\251es", nullptr));
        ChercheurButton->setText(QCoreApplication::translate("MainWindow", "chercheurs", nullptr));
        vac->setText(QCoreApplication::translate("MainWindow", "vaccins", nullptr));
        EquipementButton->setText(QCoreApplication::translate("MainWindow", "\303\251quipements", nullptr));
        client->setText(QCoreApplication::translate("MainWindow", "clients", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "D\303\251connexion", nullptr));
        logout->setText(QString());
        logout_3->setText(QString());
        logo1->setText(QString());
        eq_2->setText(QCoreApplication::translate("MainWindow", "test biologique", nullptr));
        emp1_2->setText(QCoreApplication::translate("MainWindow", "employ\303\251es", nullptr));
        ChercheurButton_2->setText(QCoreApplication::translate("MainWindow", "chercheurs", nullptr));
        vac_2->setText(QCoreApplication::translate("MainWindow", "vaccins", nullptr));
        EquipementButton_2->setText(QCoreApplication::translate("MainWindow", "\303\251quipements", nullptr));
        client_2->setText(QCoreApplication::translate("MainWindow", "clients", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "D\303\251connexion", nullptr));
        logout_2->setText(QString());
        label_4->setText(QString());
        logo1_2->setText(QString());
        eq_3->setText(QCoreApplication::translate("MainWindow", "test biologique", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
