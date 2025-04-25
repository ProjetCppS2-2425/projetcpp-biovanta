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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *bg;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *ID;
    QLabel *label_2;
    QLabel *label_7;
    QPushButton *valider;
    QPushButton *annuler;
    QLabel *label_9;
    QLineEdit *Nom;
    QLabel *label_3;
    QLineEdit *mdp;
    QDateEdit *date;
    QLabel *label_5;
    QLineEdit *Telephone;
    QComboBox *poste;
    QLabel *label_6;
    QLabel *label_12;
    QLineEdit *salaire;
    QLabel *label_13;
    QLineEdit *Email;
    QLineEdit *prenom;
    QLabel *label_14;
    QFrame *frame;
    QPushButton *pushButton_6;
    QWidget *sidebare;
    QLabel *logo;
    QPushButton *pushButton_8;
    QLabel *logout;
    QPushButton *emp1;
    QPushButton *chercheur;
    QPushButton *vac;
    QPushButton *eq;
    QPushButton *test;
    QPushButton *client;
    QGroupBox *groupBox_3;
    QPushButton *supprimer;
    QPushButton *modifier;
    QPushButton *modification;
    QGroupBox *groupBox_2;
    QTableWidget *table;
    QLineEdit *rechercher;
    QLabel *label_8;
    QLabel *label_10;
    QComboBox *tri;
    QLabel *stat_2;
    QPushButton *pdfEmployes;
    QPushButton *stat;
    QComboBox *re;
    QPushButton *quit;
    QWidget *page_2;
    QFrame *frame_2;
    QLabel *label_4;
    QLabel *label_11;
    QLineEdit *emailline;
    QPushButton *connectionButton;
    QLabel *label_15;
    QLineEdit *mdpline;
    QLabel *label_16;
    QLabel *label_17;
    QPushButton *omdp;
    QFrame *frame_3;
    QLabel *logo1;
    QLabel *label_19;
    QWidget *page_3;
    QFrame *frame_4;
    QLineEdit *le_email_oub;
    QPushButton *pb_valider_mdp_oub;
    QLabel *label_22;
    QLineEdit *le_code_oub;
    QLabel *label_23;
    QLabel *label_24;
    QLineEdit *le_new_mdp_oub;
    QPushButton *valid;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1529, 732);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(-10, -10, 1601, 671));
        page = new QWidget();
        page->setObjectName("page");
        bg = new QLabel(page);
        bg->setObjectName("bg");
        bg->setGeometry(QRect(170, 60, 1421, 581));
        bg->setPixmap(QPixmap(QString::fromUtf8("assets/bg.jpg")));
        groupBox = new QGroupBox(page);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(180, 90, 311, 441));
        groupBox->setAutoFillBackground(false);
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #02767F; /* Couleur turquoise pour la bordure */\n"
"    border-radius: 10px;  /* Coins arrondis */\n"
"    padding: 10px;  /* Espacement interne */\n"
"    margin-bottom: 20px;  /* Espacement en bas */\n"
"}\n"
""));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 50, 131, 20));
        label->setStyleSheet(QString::fromUtf8("color: black;\n"
""));
        ID = new QLineEdit(groupBox);
        ID->setObjectName("ID");
        ID->setGeometry(QRect(180, 50, 91, 26));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 90, 151, 20));
        label_2->setStyleSheet(QString::fromUtf8("color: black;"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 330, 171, 20));
        label_7->setStyleSheet(QString::fromUtf8("color: black;"));
        valider = new QPushButton(groupBox);
        valider->setObjectName("valider");
        valider->setGeometry(QRect(20, 380, 91, 31));
        valider->setStyleSheet(QString::fromUtf8("/* Style global des boutons */\n"
"QPushButton {\n"
"    background-color: #34495E;  /* Bleu fonc\303\251 */\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    padding: 10px;\n"
"    border: none;\n"
"    text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
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
"}"));
        annuler = new QPushButton(groupBox);
        annuler->setObjectName("annuler");
        annuler->setGeometry(QRect(190, 380, 91, 31));
        annuler->setStyleSheet(QString::fromUtf8("/* Style global des boutons */\n"
"QPushButton {\n"
"    background-color: #34495E;  /* Bleu fonc\303\251 */\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    padding: 10px;\n"
"    border: none;\n"
"    text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
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
"}-"));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 10, 301, 41));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush1(QColor(0, 0, 0, 128));
        brush1.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush1);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush1);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush1);
#endif
        label_9->setPalette(palette);
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Variable")});
        font.setPointSize(14);
        font.setBold(true);
        font.setUnderline(true);
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("color: black;"));
        Nom = new QLineEdit(groupBox);
        Nom->setObjectName("Nom");
        Nom->setGeometry(QRect(180, 90, 91, 26));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 130, 151, 20));
        label_3->setStyleSheet(QString::fromUtf8("color: black;\n"
""));
        mdp = new QLineEdit(groupBox);
        mdp->setObjectName("mdp");
        mdp->setGeometry(QRect(180, 160, 91, 26));
        date = new QDateEdit(groupBox);
        date->setObjectName("date");
        date->setGeometry(QRect(190, 330, 110, 29));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 190, 151, 20));
        label_5->setStyleSheet(QString::fromUtf8("color: black;"));
        Telephone = new QLineEdit(groupBox);
        Telephone->setObjectName("Telephone");
        Telephone->setGeometry(QRect(180, 190, 91, 26));
        poste = new QComboBox(groupBox);
        poste->addItem(QString());
        poste->addItem(QString());
        poste->addItem(QString());
        poste->setObjectName("poste");
        poste->setGeometry(QRect(140, 220, 151, 28));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 220, 151, 20));
        label_6->setStyleSheet(QString::fromUtf8("color: black;"));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 300, 151, 20));
        label_12->setStyleSheet(QString::fromUtf8("color: black;"));
        salaire = new QLineEdit(groupBox);
        salaire->setObjectName("salaire");
        salaire->setGeometry(QRect(180, 290, 91, 26));
        label_13 = new QLabel(groupBox);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 260, 151, 20));
        label_13->setStyleSheet(QString::fromUtf8("color: black;"));
        Email = new QLineEdit(groupBox);
        Email->setObjectName("Email");
        Email->setGeometry(QRect(100, 260, 201, 26));
        prenom = new QLineEdit(groupBox);
        prenom->setObjectName("prenom");
        prenom->setGeometry(QRect(180, 130, 91, 26));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(10, 160, 151, 20));
        label_14->setStyleSheet(QString::fromUtf8("color: black;"));
        frame = new QFrame(page);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(90, -20, 1391, 91));
        frame->setStyleSheet(QString::fromUtf8("#frame {\n"
"    background-color: #2C3E50; /* Couleur bleu fonc\303\251 */\n"
"    border-right: 2px solid #dee2e6;;\n"
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
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        pushButton_6 = new QPushButton(frame);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(220, 40, 141, 41));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"}"));
        sidebare = new QWidget(page);
        sidebare->setObjectName("sidebare");
        sidebare->setGeometry(QRect(10, 10, 161, 631));
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
"}"));
        logo = new QLabel(sidebare);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(10, 30, 111, 111));
        logo->setPixmap(QPixmap(QString::fromUtf8("assets/logo1.png")));
        pushButton_8 = new QPushButton(sidebare);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(30, 560, 111, 31));
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
        logout->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/application/application/logout.png")));
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
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../Downloads/projet_c (3)/projet_c/empe.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        emp1->setIcon(icon);
        chercheur = new QPushButton(sidebare);
        chercheur->setObjectName("chercheur");
        chercheur->setGeometry(QRect(0, 200, 141, 41));
        chercheur->setStyleSheet(QString::fromUtf8("/* Style global des boutons */\n"
"QPushButton {\n"
"    background-color: #34495E;  /* Bleu fonc\303\251 */\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    padding: 10px;\n"
"    border: none;\n"
"    text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
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
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../Downloads/projet_c (3)/projet_c/cher.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        chercheur->setIcon(icon1);
        vac = new QPushButton(sidebare);
        vac->setObjectName("vac");
        vac->setGeometry(QRect(0, 250, 141, 41));
        vac->setStyleSheet(QString::fromUtf8("/* Style global des boutons */\n"
"QPushButton {\n"
"    background-color: #34495E;  /* Bleu fonc\303\251 */\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    padding: 10px;\n"
"    border: none;\n"
"    text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
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
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../../../Downloads/projet_c (3)/projet_c/vaccin.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        vac->setIcon(icon2);
        vac->setIconSize(QSize(20, 20));
        eq = new QPushButton(sidebare);
        eq->setObjectName("eq");
        eq->setGeometry(QRect(0, 300, 141, 41));
        eq->setStyleSheet(QString::fromUtf8("/* Style global des boutons */\n"
"QPushButton {\n"
"    background-color: #34495E;  /* Bleu fonc\303\251 */\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    padding: 10px;\n"
"    border: none;\n"
"    text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
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
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../../../Downloads/projet_c (3)/projet_c/equipement.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        eq->setIcon(icon3);
        test = new QPushButton(sidebare);
        test->setObjectName("test");
        test->setGeometry(QRect(-10, 350, 151, 41));
        test->setStyleSheet(QString::fromUtf8("/* Style global des boutons */\n"
"QPushButton {\n"
"    background-color: #34495E;  /* Bleu fonc\303\251 */\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    padding: 10px;\n"
"    border: none;\n"
"    text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
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
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../../../Downloads/projet_c (3)/projet_c/teste.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        test->setIcon(icon4);
        client = new QPushButton(sidebare);
        client->setObjectName("client");
        client->setGeometry(QRect(0, 400, 141, 41));
        client->setStyleSheet(QString::fromUtf8("/* Style global des boutons */\n"
"QPushButton {\n"
"    background-color: #34495E;  /* Bleu fonc\303\251 */\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    padding: 10px;\n"
"    border: none;\n"
"    text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
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
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("../../../Downloads/projet_c (3)/projet_c/client.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        client->setIcon(icon5);
        groupBox_3 = new QGroupBox(page);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(180, 540, 291, 81));
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #02767F; /* Couleur turquoise pour la bordure */\n"
"    border-radius: 10px;  /* Coins arrondis */\n"
"    padding: 10px;  /* Espacement interne */\n"
"    margin-bottom: 20px;  /* Espacement en bas */\n"
"}\n"
""));
        supprimer = new QPushButton(groupBox_3);
        supprimer->setObjectName("supprimer");
        supprimer->setGeometry(QRect(10, 20, 91, 31));
        supprimer->setStyleSheet(QString::fromUtf8("/* Style global des boutons */\n"
"QPushButton {\n"
"    background-color: #34495E;  /* Bleu fonc\303\251 */\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    padding: 10px;\n"
"    border: none;\n"
"    text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
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
"}"));
        modifier = new QPushButton(groupBox_3);
        modifier->setObjectName("modifier");
        modifier->setGeometry(QRect(110, 20, 91, 31));
        modifier->setStyleSheet(QString::fromUtf8("/* Style global des boutons */\n"
"QPushButton {\n"
"    background-color: #34495E;  /* Bleu fonc\303\251 */\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    padding: 10px;\n"
"    border: none;\n"
"    text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
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
"}"));
        modification = new QPushButton(groupBox_3);
        modification->setObjectName("modification");
        modification->setGeometry(QRect(210, 20, 91, 31));
        modification->setStyleSheet(QString::fromUtf8("/* Style global des boutons */\n"
"QPushButton {\n"
"    background-color: #34495E;  /* Bleu fonc\303\251 */\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    padding: 10px;\n"
"    border: none;\n"
"    text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
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
"}"));
        groupBox_2 = new QGroupBox(page);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(500, 90, 961, 531));
        groupBox_2->setStyleSheet(QString::fromUtf8("/* Tableau principal */\n"
"table {\n"
"    width: 100%;\n"
"    border-collapse: collapse;\n"
"    margin: 20px 0;\n"
"    font-size: 14px;\n"
"    background-color: #02767F;\n"
"    border: 1px solid #02767F;\n"
"}\n"
"\n"
"/* Style des en-t\303\252tes de colonne */\n"
"th {\n"
"    background-color: #007bff;\n"
"    color: white;\n"
"    padding: 12px 15px;\n"
"    text-align: center;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Style des cellules de donn\303\251es */\n"
"td {\n"
"    padding: 12px 15px;\n"
"    text-align: center;\n"
"    border: 1px solid #ddd;\n"
"}\n"
"\n"
"/* Style de la colonne \"Actions\" */\n"
"td.actions {\n"
"    display: flex;\n"
"    justify-content: center;\n"
"    gap: 10px;\n"
"}\n"
"\n"
"/* Bouton Modifier */\n"
"button.modify-btn {\n"
"    background-color: #ffc107;\n"
"    color: black;\n"
"    border: none;\n"
"    padding: 8px 12px;\n"
"    border-radius: 5px;\n"
"    cursor: pointer;\n"
"    font-size: 14px;\n"
"    transition: background-color 0.3s;\n"
"}\n"
"\n"
"butt"
                        "on.modify-btn:hover {\n"
"    background-color: #e0a800;\n"
"}\n"
"\n"
"/* Bouton Supprimer */\n"
"button.delete-btn {\n"
"    background-color: #dc3545;\n"
"    color: white;\n"
"    border: none;\n"
"    padding: 8px 12px;\n"
"    border-radius: 5px;\n"
"    cursor: pointer;\n"
"    font-size: 14px;\n"
"    transition: background-color 0.3s;\n"
"}\n"
"\n"
"button.delete-btn:hover {\n"
"    background-color: #c82333;\n"
"}\n"
"\n"
"/* Style de ligne lorsque la souris passe dessus */\n"
"tr:hover {\n"
"    background-color: #f1f1f1;\n"
"}\n"
"\n"
"/* Style des lignes impaires pour un meilleur contraste */\n"
"tr:nth-child(odd) {\n"
"    background-color: #f7f7f7;\n"
"}\n"
"\n"
"/* Style de la derni\303\250re colonne (Actions) */\n"
"td.actions {\n"
"    display: flex;\n"
"    justify-content: center;\n"
"    align-items: center;\n"
"}\n"
"\n"
"/* Pour le contenu des images */\n"
"td img {\n"
"    width: 40px;\n"
"    height: 40px;\n"
"    object-fit: cover;\n"
"    border-radius: 50%;\n"
"}\n"
"QGroupBox {\n"
""
                        "    border: 2px solid #02767F; /* Couleur turquoise pour la bordure */\n"
"    border-radius: 10px;  /* Coins arrondis */\n"
"    padding: 10px;  /* Espacement interne */\n"
"    margin-bottom: 20px;  /* Espacement en bas */\n"
"}\n"
"\n"
"\n"
""));
        table = new QTableWidget(groupBox_2);
        if (table->columnCount() < 9)
            table->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        if (table->rowCount() < 8)
            table->setRowCount(8);
        table->setObjectName("table");
        table->setGeometry(QRect(10, 160, 891, 341));
        table->setSortingEnabled(false);
        table->setRowCount(8);
        table->setColumnCount(9);
        rechercher = new QLineEdit(groupBox_2);
        rechercher->setObjectName("rechercher");
        rechercher->setGeometry(QRect(300, 60, 321, 31));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 60, 101, 20));
        label_8->setStyleSheet(QString::fromUtf8("color: black;"));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 10, 341, 31));
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("color: black;"));
        tri = new QComboBox(groupBox_2);
        tri->setObjectName("tri");
        tri->setGeometry(QRect(430, 110, 171, 28));
        stat_2 = new QLabel(groupBox_2);
        stat_2->setObjectName("stat_2");
        stat_2->setGeometry(QRect(340, 110, 71, 31));
        stat_2->setStyleSheet(QString::fromUtf8("color: black;"));
        pdfEmployes = new QPushButton(groupBox_2);
        pdfEmployes->setObjectName("pdfEmployes");
        pdfEmployes->setGeometry(QRect(230, 110, 81, 31));
        pdfEmployes->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    qproperty-iconSize: 21px 21px;  /* Taille de l'ic\303\264ne */\n"
"    text-align: center; /* Centrage du texte si besoin */\n"
"}\n"
""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("../../../Downloads/projet_c (3)/projet_c/pdf1.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pdfEmployes->setIcon(icon6);
        pdfEmployes->setIconSize(QSize(21, 21));
        stat = new QPushButton(groupBox_2);
        stat->setObjectName("stat");
        stat->setGeometry(QRect(670, 110, 81, 31));
        stat->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    qproperty-iconSize: 21px 21px;  /* Taille de l'ic\303\264ne */\n"
"    text-align: center; /* Centrage du texte si besoin */\n"
"}\n"
""));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("../../../Downloads/projet_c (3)/projet_c/st.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        stat->setIcon(icon7);
        stat->setIconSize(QSize(21, 21));
        re = new QComboBox(groupBox_2);
        re->setObjectName("re");
        re->setGeometry(QRect(130, 60, 151, 28));
        quit = new QPushButton(groupBox_2);
        quit->setObjectName("quit");
        quit->setGeometry(QRect(670, 60, 91, 31));
        quit->setStyleSheet(QString::fromUtf8("/* Style global des boutons */\n"
"QPushButton {\n"
"    background-color: #34495E;  /* Bleu fonc\303\251 */\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    padding: 10px;\n"
"    border: none;\n"
"    text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
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
"}-"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        frame_2 = new QFrame(page_2);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(40, 10, 741, 621));
        frame_2->setMinimumSize(QSize(741, 0));
        frame_2->setStyleSheet(QString::fromUtf8("QFrame#frame_2{\n"
"    background-color: white;\n"
"    border-radius: 10px;\n"
"    padding: 20px;\n"
"}\n"
""));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        label_4 = new QLabel(frame_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(90, 169, 331, 51));
        label_4->setStyleSheet(QString::fromUtf8("QLabel#label_4 {\n"
"    font-size: 30px;\n"
"    font-weight: bold;\n"
"    color: #333;\n"
"}\n"
""));
        label_11 = new QLabel(frame_2);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(90, 210, 591, 51));
        label_11->setStyleSheet(QString::fromUtf8("QLabel#label_11 {\n"
"    font-size: 20px;\n"
"    font-weight: bold;\n"
"    color: #2C8D7A;\n"
"}\n"
""));
        emailline = new QLineEdit(frame_2);
        emailline->setObjectName("emailline");
        emailline->setGeometry(QRect(100, 300, 371, 51));
        emailline->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_15 = new QLabel(frame_2);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(140, 570, 321, 20));
        label_15->setStyleSheet(QString::fromUtf8("color: black;"));
        mdpline = new QLineEdit(frame_2);
        mdpline->setObjectName("mdpline");
        mdpline->setGeometry(QRect(100, 400, 371, 51));
        mdpline->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"}"));
        mdpline->setEchoMode(QLineEdit::EchoMode::Password);
        label_16 = new QLabel(frame_2);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(100, 270, 191, 20));
        label_16->setStyleSheet(QString::fromUtf8("color: black;"));
        label_17 = new QLabel(frame_2);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(100, 370, 191, 20));
        label_17->setStyleSheet(QString::fromUtf8("color: black;"));
        omdp = new QPushButton(frame_2);
        omdp->setObjectName("omdp");
        omdp->setGeometry(QRect(300, 460, 181, 31));
        omdp->setStyleSheet(QString::fromUtf8("QPushButton#omdp {\n"
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
        frame_3 = new QFrame(page_2);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(780, 10, 751, 621));
        frame_3->setStyleSheet(QString::fromUtf8("QFrame#frame_3 {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #0E3A47, stop:1 #104F52);\n"
"    border-radius: 10px;\n"
"    padding: 40px;\n"
"    color: white;\n"
"}\n"
""));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        logo1 = new QLabel(frame_3);
        logo1->setObjectName("logo1");
        logo1->setGeometry(QRect(170, 70, 461, 461));
        logo1->setStyleSheet(QString::fromUtf8("QLabel#logo1 {\n"
"    font-size: 30px;\n"
"    font-weight: bold;\n"
"    color: #333;\n"
"}\n"
""));
        logo1->setPixmap(QPixmap(QString::fromUtf8("assets/logo2.png")));
        label_19 = new QLabel(frame_3);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(200, 480, 421, 51));
        label_19->setSizeIncrement(QSize(10, 0));
        QFont font1;
        font1.setBold(true);
        label_19->setFont(font1);
        label_19->setStyleSheet(QString::fromUtf8("QLabel#label_2 {\n"
"    font-size: 30px;\n"
"    font-weight: bold;\n"
"    color: #333;\n"
"}\n"
""));
        label_19->setTextFormat(Qt::TextFormat::RichText);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        frame_4 = new QFrame(page_3);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(410, 0, 741, 621));
        frame_4->setMinimumSize(QSize(741, 0));
        frame_4->setStyleSheet(QString::fromUtf8("QFrame#frame_4{\n"
"    background-color: white;\n"
"    border-radius: 10px;\n"
"    padding: 20px;\n"
"}\n"
""));
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        le_email_oub = new QLineEdit(frame_4);
        le_email_oub->setObjectName("le_email_oub");
        le_email_oub->setGeometry(QRect(170, 180, 371, 51));
        le_email_oub->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"}"));
        pb_valider_mdp_oub = new QPushButton(frame_4);
        pb_valider_mdp_oub->setObjectName("pb_valider_mdp_oub");
        pb_valider_mdp_oub->setGeometry(QRect(190, 500, 371, 41));
        pb_valider_mdp_oub->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_22 = new QLabel(frame_4);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(200, 570, 321, 20));
        label_22->setStyleSheet(QString::fromUtf8("color: black;"));
        le_code_oub = new QLineEdit(frame_4);
        le_code_oub->setObjectName("le_code_oub");
        le_code_oub->setGeometry(QRect(160, 290, 371, 51));
        le_code_oub->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"}"));
        le_code_oub->setEchoMode(QLineEdit::EchoMode::Password);
        label_23 = new QLabel(frame_4);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(180, 130, 191, 20));
        label_23->setStyleSheet(QString::fromUtf8("color: black;"));
        label_24 = new QLabel(frame_4);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(160, 260, 191, 20));
        label_24->setStyleSheet(QString::fromUtf8("color: black;"));
        le_new_mdp_oub = new QLineEdit(frame_4);
        le_new_mdp_oub->setObjectName("le_new_mdp_oub");
        le_new_mdp_oub->setGeometry(QRect(160, 420, 371, 51));
        le_new_mdp_oub->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"}"));
        le_new_mdp_oub->setEchoMode(QLineEdit::EchoMode::Password);
        valid = new QPushButton(frame_4);
        valid->setObjectName("valid");
        valid->setGeometry(QRect(570, 190, 121, 41));
        valid->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        stackedWidget->addWidget(page_3);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1529, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        bg->setText(QString());
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("MainWindow", "ID employe", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Nom de l'employ\303\251", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Date d'embauchement", nullptr));
        valider->setText(QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        annuler->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", " AJOUT :", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Prenom de l'employ\303\251", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "num telephone", nullptr));
        poste->setItemText(0, QCoreApplication::translate("MainWindow", "chef de chercheur", nullptr));
        poste->setItemText(1, QCoreApplication::translate("MainWindow", "chef departement", nullptr));
        poste->setItemText(2, QCoreApplication::translate("MainWindow", "chef de stock", nullptr));

        label_6->setText(QCoreApplication::translate("MainWindow", "Poste", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Salaire", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Mot de passe", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "fonctionnalit\303\251", nullptr));
        logo->setText(QString());
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "D\303\251connexion", nullptr));
        logout->setText(QString());
        emp1->setText(QCoreApplication::translate("MainWindow", "employ\303\251es", nullptr));
        chercheur->setText(QCoreApplication::translate("MainWindow", "chercheurs", nullptr));
        vac->setText(QCoreApplication::translate("MainWindow", "vaccins", nullptr));
        eq->setText(QCoreApplication::translate("MainWindow", "\303\251quipements", nullptr));
        test->setText(QCoreApplication::translate("MainWindow", "tests biologiques", nullptr));
        client->setText(QCoreApplication::translate("MainWindow", "clients", nullptr));
        groupBox_3->setTitle(QString());
        supprimer->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        modifier->setText(QCoreApplication::translate("MainWindow", "choisir", nullptr));
        modification->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        groupBox_2->setTitle(QString());
        QTableWidgetItem *___qtablewidgetitem = table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID employ\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Nom de l'employ\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Mot de passe", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Prenom d'employ\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = table->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "num telephone", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = table->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Poste", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = table->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = table->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Date d'embauchement", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = table->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Salaire", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "rechercher :", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "LISTE : ", nullptr));
        stat_2->setText(QCoreApplication::translate("MainWindow", "tri par :", nullptr));
        pdfEmployes->setText(QString());
        stat->setText(QString());
        quit->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", " Bienvenue !", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Connectez-vous \303\240 votre compte Biovanta", nullptr));
        connectionButton->setText(QCoreApplication::translate("MainWindow", "connection", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", " \302\251 2025 Biovanta ,Tous droits r\303\251serv\303\251s.", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Entrer votre email", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Entrer votre mot de passe ", nullptr));
        omdp->setText(QCoreApplication::translate("MainWindow", "mot de pass oublier?", nullptr));
        logo1->setText(QString());
        label_19->setText(QCoreApplication::translate("MainWindow", "Biovanta \342\200\223 R\303\251volutionnez la Recherche, Simplifiez la Science.", nullptr));
        pb_valider_mdp_oub->setText(QCoreApplication::translate("MainWindow", "login using code", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", " \302\251 2025 Biovanta ,Tous droits r\303\251serv\303\251s.", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "Entrer votre email", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Entrer votre code", nullptr));
        valid->setText(QCoreApplication::translate("MainWindow", "send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
