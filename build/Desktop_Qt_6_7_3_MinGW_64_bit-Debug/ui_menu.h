/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menu
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *pageEquipement;
    QWidget *pageChercheur;
    QWidget *pageMenu;
    QLabel *label;
    QPushButton *equip;
    QPushButton *cherch;
    QLabel *bg_2;
    QLabel *logo;
    QPushButton *equip_2;
    QPushButton *equip_3;
    QPushButton *equip_4;
    QPushButton *equip_5;
    QLabel *leqq;
    QLabel *tes;
    QLabel *vv;
    QLabel *ee;
    QLabel *cc;
    QLabel *hh;
    QWidget *page_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *menu)
    {
        if (menu->objectName().isEmpty())
            menu->setObjectName("menu");
        menu->resize(1545, 678);
        centralwidget = new QWidget(menu);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(9, 9, 1411, 621));
        pageEquipement = new QWidget();
        pageEquipement->setObjectName("pageEquipement");
        stackedWidget->addWidget(pageEquipement);
        pageChercheur = new QWidget();
        pageChercheur->setObjectName("pageChercheur");
        stackedWidget->addWidget(pageChercheur);
        pageMenu = new QWidget();
        pageMenu->setObjectName("pageMenu");
        label = new QLabel(pageMenu);
        label->setObjectName("label");
        label->setGeometry(QRect(560, 10, 221, 81));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #2C3E50;             /* Couleur bleue \303\251l\303\251gante */\n"
"    font-size: 70px;             /* Taille du texte */\n"
"    font-weight: bold;           /* Texte en gras */\n"
"    font-family: \"Segoe UI\", sans-serif; /* Police moderne */\n"
"    letter-spacing: 1px;         /* Espacement des lettres */\n"
"    background-color: transparent; /* Fond transparent */\n"
"}\n"
""));
        equip = new QPushButton(pageMenu);
        equip->setObjectName("equip");
        equip->setGeometry(QRect(280, 220, 221, 51));
        equip->setStyleSheet(QString::fromUtf8("#equip {\n"
"    background-color: #ffffff; /* Fond blanc */\n"
"    color: #003366;            /* Texte bleu fonc\303\251 */\n"
"    border: 2px solid #003366;\n"
"    padding: 12px 24px;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    border-radius: 8px;\n"
"    cursor: pointer;\n"
"    transition: background-color 0.3s ease;\n"
"}\n"
"\n"
"#equip:hover {\n"
"    background-color: #f0f0f0; /* Survol gris clair */\n"
"}\n"
"\n"
"#equip:active {\n"
"    background-color: #e0e0e0; /* Clic gris un peu plus fonc\303\251 */\n"
"}\n"
""));
        cherch = new QPushButton(pageMenu);
        cherch->setObjectName("cherch");
        cherch->setGeometry(QRect(830, 220, 251, 51));
        cherch->setStyleSheet(QString::fromUtf8("#cherch {\n"
"    background-color: #ffffff; /* Fond blanc */\n"
"    color: #003366;            /* Texte bleu fonc\303\251 */\n"
"    border: 2px solid #003366;\n"
"    padding: 12px 24px;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    border-radius: 8px;\n"
"    cursor: pointer;\n"
"    transition: background-color 0.3s ease;\n"
"}\n"
"\n"
"#cherch:hover {\n"
"    background-color: #f0f0f0; /* Survol gris clair */\n"
"}\n"
"\n"
"#cherch:active {\n"
"    background-color: #e0e0e0; /* Clic gris un peu plus fonc\303\251 */\n"
"}\n"
""));
        bg_2 = new QLabel(pageMenu);
        bg_2->setObjectName("bg_2");
        bg_2->setGeometry(QRect(-10, -30, 1671, 651));
        bg_2->setPixmap(QPixmap(QString::fromUtf8("../projet_c/bg.jpg")));
        logo = new QLabel(pageMenu);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(60, 0, 111, 111));
        logo->setPixmap(QPixmap(QString::fromUtf8("../application/logo1.png")));
        equip_2 = new QPushButton(pageMenu);
        equip_2->setObjectName("equip_2");
        equip_2->setGeometry(QRect(570, 290, 201, 51));
        equip_2->setStyleSheet(QString::fromUtf8("#equip_2 {\n"
"    background-color: #ffffff; /* Fond blanc */\n"
"    color: #003366;            /* Texte bleu fonc\303\251 */\n"
"    border: 2px solid #003366;\n"
"    padding: 12px 24px;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    border-radius: 8px;\n"
"    cursor: pointer;\n"
"    transition: background-color 0.3s ease;\n"
"}\n"
"\n"
"#equip_2:hover {\n"
"    background-color: #f0f0f0; /* Survol gris clair */\n"
"}\n"
"\n"
"#equip_2:active {\n"
"    background-color: #e0e0e0; /* Clic gris un peu plus fonc\303\251 */\n"
"}\n"
""));
        equip_3 = new QPushButton(pageMenu);
        equip_3->setObjectName("equip_3");
        equip_3->setGeometry(QRect(280, 390, 221, 51));
        equip_3->setStyleSheet(QString::fromUtf8("#equip_3 {\n"
"    background-color: #ffffff; /* Fond blanc */\n"
"    color: #003366;            /* Texte bleu fonc\303\251 */\n"
"    border: 2px solid #003366;\n"
"    padding: 12px 24px;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    border-radius: 8px;\n"
"    cursor: pointer;\n"
"    transition: background-color 0.3s ease;\n"
"}\n"
"\n"
"#equip_3:hover {\n"
"    background-color: #f0f0f0; /* Survol gris clair */\n"
"}\n"
"\n"
"#equip_3:active {\n"
"    background-color: #e0e0e0; /* Clic gris un peu plus fonc\303\251 */\n"
"}\n"
""));
        equip_4 = new QPushButton(pageMenu);
        equip_4->setObjectName("equip_4");
        equip_4->setGeometry(QRect(580, 470, 191, 51));
        equip_4->setStyleSheet(QString::fromUtf8("#equip_4 {\n"
"    background-color: #ffffff; /* Fond blanc */\n"
"    color: #003366;            /* Texte bleu fonc\303\251 */\n"
"    border: 2px solid #003366;\n"
"    padding: 12px 24px;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    border-radius: 8px;\n"
"    cursor: pointer;\n"
"    transition: background-color 0.3s ease;\n"
"}\n"
"\n"
"#equip_4:hover {\n"
"    background-color: #f0f0f0; /* Survol gris clair */\n"
"}\n"
"\n"
"#equip_4:active {\n"
"    background-color: #e0e0e0; /* Clic gris un peu plus fonc\303\251 */\n"
"}\n"
""));
        equip_5 = new QPushButton(pageMenu);
        equip_5->setObjectName("equip_5");
        equip_5->setGeometry(QRect(820, 410, 261, 51));
        equip_5->setStyleSheet(QString::fromUtf8("#equip_5 {\n"
"    background-color: #ffffff; /* Fond blanc */\n"
"    color: #003366;            /* Texte bleu fonc\303\251 */\n"
"    border: 2px solid #003366;\n"
"    padding: 12px 24px;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    border-radius: 8px;\n"
"    cursor: pointer;\n"
"    transition: background-color 0.3s ease;\n"
"}\n"
"\n"
"#equip_5:hover {\n"
"    background-color: #f0f0f0; /* Survol gris clair */\n"
"}\n"
"\n"
"#equip_5:active {\n"
"    background-color: #e0e0e0; /* Clic gris un peu plus fonc\303\251 */\n"
"}\n"
""));
        leqq = new QLabel(pageMenu);
        leqq->setObjectName("leqq");
        leqq->setGeometry(QRect(330, 80, 161, 161));
        leqq->setStyleSheet(QString::fromUtf8("#buttonEquip {\n"
"    background-color: #4CAF50; /* Vert doux */\n"
"    color: white;\n"
"    border: none;\n"
"    padding: 12px 24px;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    border-radius: 8px;\n"
"    cursor: pointer;\n"
"    transition: background-color 0.3s ease, transform 0.2s ease;\n"
"    box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);\n"
"}\n"
"\n"
"#buttonEquip:hover {\n"
"    background-color: #45a049; /* L\303\251g\303\250rement plus fonc\303\251 au survol */\n"
"    transform: scale(1.05);\n"
"}\n"
"\n"
"#buttonEquip:active {\n"
"    background-color: #3e8e41;\n"
"    transform: scale(0.98);\n"
"}\n"
""));
        leqq->setPixmap(QPixmap(QString::fromUtf8("leq.png")));
        tes = new QLabel(pageMenu);
        tes->setObjectName("tes");
        tes->setGeometry(QRect(870, 260, 161, 141));
        tes->setPixmap(QPixmap(QString::fromUtf8("te.png")));
        vv = new QLabel(pageMenu);
        vv->setObjectName("vv");
        vv->setGeometry(QRect(610, 160, 121, 121));
        vv->setPixmap(QPixmap(QString::fromUtf8("vv.png")));
        ee = new QLabel(pageMenu);
        ee->setObjectName("ee");
        ee->setGeometry(QRect(620, 350, 121, 111));
        ee->setPixmap(QPixmap(QString::fromUtf8("ee.png")));
        cc = new QLabel(pageMenu);
        cc->setObjectName("cc");
        cc->setGeometry(QRect(330, 280, 121, 91));
        cc->setPixmap(QPixmap(QString::fromUtf8("cc.png")));
        hh = new QLabel(pageMenu);
        hh->setObjectName("hh");
        hh->setGeometry(QRect(870, 90, 141, 111));
        hh->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/hh.png")));
        stackedWidget->addWidget(pageMenu);
        bg_2->raise();
        label->raise();
        equip->raise();
        cherch->raise();
        logo->raise();
        equip_2->raise();
        equip_3->raise();
        equip_4->raise();
        equip_5->raise();
        leqq->raise();
        tes->raise();
        vv->raise();
        ee->raise();
        cc->raise();
        hh->raise();
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        stackedWidget->addWidget(page_3);
        menu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(menu);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1545, 26));
        menu->setMenuBar(menubar);
        statusbar = new QStatusBar(menu);
        statusbar->setObjectName("statusbar");
        menu->setStatusBar(statusbar);

        retranslateUi(menu);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(menu);
    } // setupUi

    void retranslateUi(QMainWindow *menu)
    {
        menu->setWindowTitle(QCoreApplication::translate("menu", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("menu", "Menu", nullptr));
        equip->setText(QCoreApplication::translate("menu", "gestion equipement ", nullptr));
        cherch->setText(QCoreApplication::translate("menu", "gestion chercheur", nullptr));
        bg_2->setText(QString());
        logo->setText(QString());
        equip_2->setText(QCoreApplication::translate("menu", "gestion vaccin ", nullptr));
        equip_3->setText(QCoreApplication::translate("menu", "gestion client", nullptr));
        equip_4->setText(QCoreApplication::translate("menu", "gestion employ\303\251", nullptr));
        equip_5->setText(QCoreApplication::translate("menu", "gestion teste biologique", nullptr));
        leqq->setText(QString());
        tes->setText(QString());
        vv->setText(QString());
        ee->setText(QString());
        cc->setText(QString());
        hh->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class menu: public Ui_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
