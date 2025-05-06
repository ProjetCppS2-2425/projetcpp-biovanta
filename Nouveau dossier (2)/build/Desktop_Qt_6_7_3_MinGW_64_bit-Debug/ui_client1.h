/********************************************************************************
** Form generated from reading UI file 'client1.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT1_H
#define UI_CLIENT1_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_client1
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *lineEdit_ID;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *ajout;
    QLineEdit *lineEdit_nomA;
    QLabel *label_4;
    QComboBox *typeCombo;
    QLineEdit *lineEdit_Rep;
    QLineEdit *lineEdit_ctr;
    QLineEdit *lineEdit_email;
    QLineEdit *lineEdit_adr;
    QLabel *label_12;
    QWidget *sidebare;
    QLabel *logo;
    QPushButton *emp1;
    QPushButton *chercheur;
    QPushButton *vac;
    QPushButton *eq;
    QPushButton *client;
    QPushButton *test;
    QPushButton *pushButton_8;
    QLabel *logout;
    QGroupBox *groupBox_3;
    QRadioButton *radioButton_Ajouter;
    QRadioButton *radioButton_Modifier;
    QFrame *frame;
    QPushButton *todo;
    QLabel *label_debug;
    QLabel *debug;
    QPushButton *History;
    QLabel *client_2;
    QPushButton *retour;
    QGroupBox *groupBox_2;
    QLabel *label_8;
    QComboBox *CBbar;
    QComboBox *CBtri;
    QLabel *label_11;
    QPushButton *pdf;
    QPushButton *stat;
    QPushButton *ok;
    QCheckBox *ASC;
    QCheckBox *DSC;
    QGroupBox *groupBox_4;
    QLabel *label_10;
    QPushButton *pushButton_supp;
    QLineEdit *LineEdit_supp;
    QTableView *tableView;
    QLabel *label_6;
    QLineEdit *Rbar;
    QLineEdit *pdfline;
    QLabel *bg;
    QStackedWidget *stackedWidget;
    QWidget *page_9;
    QWidget *page_10;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *client1)
    {
        if (client1->objectName().isEmpty())
            client1->setObjectName("client1");
        client1->resize(1536, 670);
        client1->setStyleSheet(QString::fromUtf8("/* Style global des boutons */\n"
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
"}\n"
"\n"
"\n"
""));
        centralwidget = new QWidget(client1);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(160, 70, 311, 401));
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
        label->setGeometry(QRect(20, 50, 131, 20));
        label->setStyleSheet(QString::fromUtf8("QLabel#label{\n"
"color: #000000;\n"
"}"));
        lineEdit_ID = new QLineEdit(groupBox);
        lineEdit_ID->setObjectName("lineEdit_ID");
        lineEdit_ID->setGeometry(QRect(180, 50, 91, 26));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 90, 151, 20));
        label_2->setStyleSheet(QString::fromUtf8("QLabel#label_2{\n"
"color: #000000;\n"
"}"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 180, 131, 20));
        label_3->setStyleSheet(QString::fromUtf8("QLabel#label_3{\n"
"color: #000000;\n"
"}"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 220, 63, 20));
        label_5->setStyleSheet(QString::fromUtf8("QLabel#label_5{\n"
"color: #000000;\n"
"}"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 260, 171, 20));
        label_7->setStyleSheet(QString::fromUtf8("QLabel#label_7{\n"
"color: #000000;\n"
"}"));
        ajout = new QLabel(groupBox);
        ajout->setObjectName("ajout");
        ajout->setGeometry(QRect(30, 0, 301, 41));
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
        ajout->setPalette(palette);
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Variable")});
        font.setPointSize(14);
        font.setBold(true);
        font.setUnderline(true);
        ajout->setFont(font);
        ajout->setStyleSheet(QString::fromUtf8("QLabel#ajout{\n"
"color: #000000;\n"
"}"));
        lineEdit_nomA = new QLineEdit(groupBox);
        lineEdit_nomA->setObjectName("lineEdit_nomA");
        lineEdit_nomA->setGeometry(QRect(180, 90, 91, 26));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 140, 151, 20));
        label_4->setStyleSheet(QString::fromUtf8("QLabel#label_4{\n"
"color: #000000;\n"
"}"));
        typeCombo = new QComboBox(groupBox);
        typeCombo->addItem(QString());
        typeCombo->addItem(QString());
        typeCombo->addItem(QString());
        typeCombo->setObjectName("typeCombo");
        typeCombo->setGeometry(QRect(140, 140, 161, 26));
        lineEdit_Rep = new QLineEdit(groupBox);
        lineEdit_Rep->setObjectName("lineEdit_Rep");
        lineEdit_Rep->setGeometry(QRect(180, 180, 91, 26));
        lineEdit_ctr = new QLineEdit(groupBox);
        lineEdit_ctr->setObjectName("lineEdit_ctr");
        lineEdit_ctr->setGeometry(QRect(180, 300, 91, 26));
        lineEdit_email = new QLineEdit(groupBox);
        lineEdit_email->setObjectName("lineEdit_email");
        lineEdit_email->setGeometry(QRect(180, 260, 91, 26));
        lineEdit_adr = new QLineEdit(groupBox);
        lineEdit_adr->setObjectName("lineEdit_adr");
        lineEdit_adr->setGeometry(QRect(180, 220, 91, 26));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 300, 171, 20));
        label_12->setStyleSheet(QString::fromUtf8("QLabel#label_12{\n"
"color:#000000;\n"
"}"));
        sidebare = new QWidget(centralwidget);
        sidebare->setObjectName("sidebare");
        sidebare->setGeometry(QRect(10, -9, 141, 651));
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
        logo = new QLabel(sidebare);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(20, 20, 111, 111));
        logo->setPixmap(QPixmap(QString::fromUtf8("../application/logo1.png")));
        emp1 = new QPushButton(sidebare);
        emp1->setObjectName("emp1");
        emp1->setGeometry(QRect(0, 150, 141, 41));
        QIcon icon;
        icon.addFile(QString::fromUtf8("empe.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        emp1->setIcon(icon);
        chercheur = new QPushButton(sidebare);
        chercheur->setObjectName("chercheur");
        chercheur->setGeometry(QRect(0, 200, 141, 41));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("cher.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        chercheur->setIcon(icon1);
        vac = new QPushButton(sidebare);
        vac->setObjectName("vac");
        vac->setGeometry(QRect(0, 250, 141, 41));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("vaccin.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        vac->setIcon(icon2);
        vac->setIconSize(QSize(20, 20));
        eq = new QPushButton(sidebare);
        eq->setObjectName("eq");
        eq->setGeometry(QRect(0, 300, 141, 41));
        eq->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("equipement.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        eq->setIcon(icon3);
        client = new QPushButton(sidebare);
        client->setObjectName("client");
        client->setGeometry(QRect(0, 400, 141, 41));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("client.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        client->setIcon(icon4);
        test = new QPushButton(sidebare);
        test->setObjectName("test");
        test->setGeometry(QRect(0, 350, 151, 41));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("teste.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        test->setIcon(icon5);
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
        logout->setPixmap(QPixmap(QString::fromUtf8("../application/logout.png")));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(160, 480, 311, 91));
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #02767F; /* Couleur turquoise pour la bordure */\n"
"    border-radius: 10px;  /* Coins arrondis */\n"
"    padding: 10px;  /* Espacement interne */\n"
"    margin-bottom: 20px;  /* Espacement en bas */\n"
"}\n"
""));
        radioButton_Ajouter = new QRadioButton(groupBox_3);
        radioButton_Ajouter->setObjectName("radioButton_Ajouter");
        radioButton_Ajouter->setGeometry(QRect(30, 20, 110, 24));
        radioButton_Ajouter->setStyleSheet(QString::fromUtf8("QRadioButton#radioButton_Ajouter{\n"
"color:#000000;\n"
"}"));
        radioButton_Modifier = new QRadioButton(groupBox_3);
        radioButton_Modifier->setObjectName("radioButton_Modifier");
        radioButton_Modifier->setGeometry(QRect(180, 20, 110, 24));
        radioButton_Modifier->setStyleSheet(QString::fromUtf8("QRadioButton#radioButton_Modifier{\n"
"color:#000000;\n"
"}"));
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(150, 0, 1391, 51));
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
        todo = new QPushButton(frame);
        todo->setObjectName("todo");
        todo->setGeometry(QRect(60, 10, 61, 31));
        todo->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_debug = new QLabel(frame);
        label_debug->setObjectName("label_debug");
        label_debug->setGeometry(QRect(260, 20, 63, 20));
        debug = new QLabel(frame);
        debug->setObjectName("debug");
        debug->setGeometry(QRect(280, 10, 63, 20));
        History = new QPushButton(frame);
        History->setObjectName("History");
        History->setGeometry(QRect(140, 10, 131, 31));
        History->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        client_2 = new QLabel(frame);
        client_2->setObjectName("client_2");
        client_2->setGeometry(QRect(370, 20, 371, 16));
        retour = new QPushButton(frame);
        retour->setObjectName("retour");
        retour->setGeometry(QRect(950, 10, 83, 29));
        retour->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(500, 60, 961, 541));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setItalic(true);
        groupBox_2->setFont(font1);
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
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(120, 30, 81, 20));
        label_8->setStyleSheet(QString::fromUtf8("QLabel#label_8{\n"
"color:#000000;\n"
"}"));
        CBbar = new QComboBox(groupBox_2);
        CBbar->addItem(QString());
        CBbar->addItem(QString());
        CBbar->addItem(QString());
        CBbar->addItem(QString());
        CBbar->setObjectName("CBbar");
        CBbar->setGeometry(QRect(570, 30, 161, 31));
        CBtri = new QComboBox(groupBox_2);
        CBtri->addItem(QString());
        CBtri->addItem(QString());
        CBtri->addItem(QString());
        CBtri->setObjectName("CBtri");
        CBtri->setGeometry(QRect(370, 80, 151, 31));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(300, 80, 63, 31));
        label_11->setStyleSheet(QString::fromUtf8("QLabel#label_11{\n"
"color:#000000;\n"
"}"));
        pdf = new QPushButton(groupBox_2);
        pdf->setObjectName("pdf");
        pdf->setGeometry(QRect(190, 80, 81, 31));
        pdf->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    qproperty-iconSize: 21px 21px;  /* Taille de l'ic\303\264ne */\n"
"    text-align: center; /* Centrage du texte si besoin */\n"
"}\n"
""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("../../../Downloads/projet_c (3)/projet_c/pdf1.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pdf->setIcon(icon6);
        pdf->setIconSize(QSize(21, 21));
        stat = new QPushButton(groupBox_2);
        stat->setObjectName("stat");
        stat->setGeometry(QRect(700, 80, 81, 31));
        stat->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    qproperty-iconSize: 21px 21px;  /* Taille de l'ic\303\264ne */\n"
"    text-align: center; /* Centrage du texte si besoin */\n"
"}\n"
""));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("../../../Downloads/projet_c (3)/projet_c/st.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        stat->setIcon(icon7);
        stat->setIconSize(QSize(21, 21));
        ok = new QPushButton(groupBox_2);
        ok->setObjectName("ok");
        ok->setGeometry(QRect(750, 20, 61, 51));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("../../../Downloads/projet_c (3)/projet_c/search.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        ok->setIcon(icon8);
        ok->setIconSize(QSize(40, 40));
        ASC = new QCheckBox(groupBox_2);
        ASC->setObjectName("ASC");
        ASC->setGeometry(QRect(530, 90, 91, 24));
        DSC = new QCheckBox(groupBox_2);
        DSC->setObjectName("DSC");
        DSC->setGeometry(QRect(590, 90, 91, 24));
        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(20, 120, 921, 411));
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 10, 161, 31));
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("QLabel#label_10{\n"
"color:#000000;\n"
"}"));
        pushButton_supp = new QPushButton(groupBox_4);
        pushButton_supp->setObjectName("pushButton_supp");
        pushButton_supp->setGeometry(QRect(740, 10, 41, 41));
        pushButton_supp->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"        background-color: #cbddf5; /* Rouge */\n"
"        color: white;\n"
"        border-radius: 5px;\n"
"        padding: 5px;\n"
"        font-weight: bold;\n"
"    }\n"
"    QPushButton:hover {\n"
"        background-color: #ff1a1a;  /* Rouge plus fonc\303\251 au survol */\n"
"    }\n"
"    QPushButton:pressed {\n"
"        background-color: #cc0000;  /* Rouge fonc\303\251 au clic */\n"
"    }"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("../../../Downloads/projet_c (3)/projet_c/effacer.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_supp->setIcon(icon9);
        pushButton_supp->setIconSize(QSize(25, 25));
        LineEdit_supp = new QLineEdit(groupBox_4);
        LineEdit_supp->setObjectName("LineEdit_supp");
        LineEdit_supp->setGeometry(QRect(790, 20, 113, 28));
        tableView = new QTableView(groupBox_4);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(25, 81, 881, 281));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(600, 20, 121, 20));
        label_6->setStyleSheet(QString::fromUtf8("QLabel#label_6{\n"
"color:#000000;\n"
"}"));
        Rbar = new QLineEdit(groupBox_2);
        Rbar->setObjectName("Rbar");
        Rbar->setGeometry(QRect(210, 30, 341, 28));
        pdfline = new QLineEdit(groupBox_2);
        pdfline->setObjectName("pdfline");
        pdfline->setGeometry(QRect(82, 80, 101, 28));
        groupBox_4->raise();
        label_8->raise();
        CBbar->raise();
        CBtri->raise();
        label_11->raise();
        pdf->raise();
        stat->raise();
        ok->raise();
        ASC->raise();
        DSC->raise();
        Rbar->raise();
        pdfline->raise();
        bg = new QLabel(centralwidget);
        bg->setObjectName("bg");
        bg->setGeometry(QRect(150, 50, 1381, 571));
        bg->setPixmap(QPixmap(QString::fromUtf8("../application/bg.jpg")));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(9, -1, 1531, 621));
        page_9 = new QWidget();
        page_9->setObjectName("page_9");
        stackedWidget->addWidget(page_9);
        page_10 = new QWidget();
        page_10->setObjectName("page_10");
        stackedWidget->addWidget(page_10);
        client1->setCentralWidget(centralwidget);
        stackedWidget->raise();
        bg->raise();
        groupBox->raise();
        groupBox_2->raise();
        sidebare->raise();
        groupBox_3->raise();
        frame->raise();
        menubar = new QMenuBar(client1);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1536, 25));
        client1->setMenuBar(menubar);
        statusbar = new QStatusBar(client1);
        statusbar->setObjectName("statusbar");
        client1->setStatusBar(statusbar);

        retranslateUi(client1);

        QMetaObject::connectSlotsByName(client1);
    } // setupUi

    void retranslateUi(QMainWindow *client1)
    {
        client1->setWindowTitle(QCoreApplication::translate("client1", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("client1", "Id Client", nullptr));
        label_2->setText(QCoreApplication::translate("client1", "Nom de l'association", nullptr));
        label_3->setText(QCoreApplication::translate("client1", "Nom Repr\303\251sentant", nullptr));
        label_5->setText(QCoreApplication::translate("client1", "Adresse", nullptr));
        label_7->setText(QCoreApplication::translate("client1", "Email", nullptr));
        ajout->setText(QCoreApplication::translate("client1", " Ajout ", nullptr));
        label_4->setText(QCoreApplication::translate("client1", "Type", nullptr));
        typeCombo->setItemText(0, QCoreApplication::translate("client1", "Minist\303\250re de Sant\303\251", nullptr));
        typeCombo->setItemText(1, QCoreApplication::translate("client1", "Laboratoire d'analyse", nullptr));
        typeCombo->setItemText(2, QCoreApplication::translate("client1", "Centre pharmaceutique", nullptr));

        label_12->setText(QCoreApplication::translate("client1", "Id du contrat", nullptr));
        logo->setText(QString());
        emp1->setText(QCoreApplication::translate("client1", "employ\303\251es", nullptr));
        chercheur->setText(QCoreApplication::translate("client1", "chercheurs", nullptr));
        vac->setText(QCoreApplication::translate("client1", "vaccins", nullptr));
        eq->setText(QCoreApplication::translate("client1", "\303\251quipements", nullptr));
        client->setText(QCoreApplication::translate("client1", "clients", nullptr));
        test->setText(QCoreApplication::translate("client1", "tests biologiques", nullptr));
        pushButton_8->setText(QCoreApplication::translate("client1", "D\303\251connexion", nullptr));
        logout->setText(QString());
        groupBox_3->setTitle(QString());
        radioButton_Ajouter->setText(QCoreApplication::translate("client1", "Ajouter", nullptr));
        radioButton_Modifier->setText(QCoreApplication::translate("client1", "Modifier", nullptr));
        todo->setText(QCoreApplication::translate("client1", "ToDo", nullptr));
        label_debug->setText(QString());
        debug->setText(QString());
        History->setText(QCoreApplication::translate("client1", "Historique", nullptr));
        client_2->setText(QString());
        retour->setText(QCoreApplication::translate("client1", "Retour", nullptr));
        groupBox_2->setTitle(QString());
        label_8->setText(QCoreApplication::translate("client1", "rechercher :", nullptr));
        CBbar->setItemText(0, QCoreApplication::translate("client1", "ID", nullptr));
        CBbar->setItemText(1, QCoreApplication::translate("client1", "Aucune", nullptr));
        CBbar->setItemText(2, QCoreApplication::translate("client1", "Adresse", nullptr));
        CBbar->setItemText(3, QCoreApplication::translate("client1", "Type Association", nullptr));

        CBtri->setItemText(0, QCoreApplication::translate("client1", "Nom Association", nullptr));
        CBtri->setItemText(1, QCoreApplication::translate("client1", "Adresse", nullptr));
        CBtri->setItemText(2, QCoreApplication::translate("client1", "Type Association", nullptr));

        label_11->setText(QCoreApplication::translate("client1", "Tri par :", nullptr));
        pdf->setText(QString());
        stat->setText(QString());
        ok->setText(QString());
        ASC->setText(QCoreApplication::translate("client1", "ASC", nullptr));
        DSC->setText(QCoreApplication::translate("client1", "DSC", nullptr));
        groupBox_4->setTitle(QString());
        label_10->setText(QCoreApplication::translate("client1", "  Listes ", nullptr));
        pushButton_supp->setText(QString());
        label_6->setText(QCoreApplication::translate("client1", "Supprimer Client:", nullptr));
        bg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class client1: public Ui_client1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT1_H
