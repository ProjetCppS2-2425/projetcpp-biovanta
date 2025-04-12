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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QGroupBox *groupBox_2;
    QLabel *label_8;
    QComboBox *filtrage;
    QComboBox *tri;
    QLabel *label_11;
    QPushButton *pdf;
    QPushButton *stat;
    QPushButton *ok;
    QCheckBox *ASC;
    QCheckBox *DSC;
    QGroupBox *groupBox_4;
    QLabel *label_10;
    QPushButton *supp;
    QLabel *label_16;
    QTableWidget *tableWidget;
    QLineEdit *S1;
    QGroupBox *groupBox_5;
    QLabel *label_12;
    QPushButton *supp_2;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_9;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QComboBox *comboBox_4;
    QLineEdit *lineEdit_4;
    QLabel *label_7;
    QLineEdit *lineEdit_5;
    QLabel *label_13;
    QLineEdit *lineEdit_7;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *lineEdit_8;
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
    QLabel *label_3;
    QLabel *label_6;
    QWidget *widget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1536, 670);
        MainWindow->setStyleSheet(QString::fromUtf8("/* Style global des boutons */\n"
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
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(150, 509, 311, 91));
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #02767F; /* Couleur turquoise pour la bordure */\n"
"    border-radius: 10px;  /* Coins arrondis */\n"
"    padding: 10px;  /* Espacement interne */\n"
"    margin-bottom: 20px;  /* Espacement en bas */\n"
"}\n"
""));
        radioButton = new QRadioButton(groupBox_3);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(10, 20, 110, 24));
        radioButton_2 = new QRadioButton(groupBox_3);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(210, 20, 110, 24));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(490, 70, 1061, 571));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        groupBox_2->setFont(font);
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
        label_8->setGeometry(QRect(100, 30, 101, 20));
        filtrage = new QComboBox(groupBox_2);
        filtrage->addItem(QString());
        filtrage->addItem(QString());
        filtrage->addItem(QString());
        filtrage->setObjectName("filtrage");
        filtrage->setGeometry(QRect(560, 30, 71, 21));
        tri = new QComboBox(groupBox_2);
        tri->addItem(QString());
        tri->addItem(QString());
        tri->addItem(QString());
        tri->setObjectName("tri");
        tri->setGeometry(QRect(370, 80, 151, 31));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(300, 80, 63, 31));
        pdf = new QPushButton(groupBox_2);
        pdf->setObjectName("pdf");
        pdf->setGeometry(QRect(190, 80, 81, 31));
        pdf->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    qproperty-iconSize: 21px 21px;  /* Taille de l'ic\303\264ne */\n"
"    text-align: center; /* Centrage du texte si besoin */\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8("pdf1.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pdf->setIcon(icon);
        pdf->setIconSize(QSize(21, 21));
        stat = new QPushButton(groupBox_2);
        stat->setObjectName("stat");
        stat->setGeometry(QRect(660, 80, 81, 31));
        stat->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    qproperty-iconSize: 21px 21px;  /* Taille de l'ic\303\264ne */\n"
"    text-align: center; /* Centrage du texte si besoin */\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("st.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        stat->setIcon(icon1);
        stat->setIconSize(QSize(21, 21));
        ok = new QPushButton(groupBox_2);
        ok->setObjectName("ok");
        ok->setGeometry(QRect(650, 20, 61, 51));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("search.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        ok->setIcon(icon2);
        ok->setIconSize(QSize(40, 40));
        ASC = new QCheckBox(groupBox_2);
        ASC->setObjectName("ASC");
        ASC->setGeometry(QRect(530, 90, 91, 24));
        DSC = new QCheckBox(groupBox_2);
        DSC->setObjectName("DSC");
        DSC->setGeometry(QRect(590, 90, 91, 24));
        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(30, 130, 611, 391));
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 10, 161, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI Variable")});
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setUnderline(true);
        label_10->setFont(font1);
        supp = new QPushButton(groupBox_4);
        supp->setObjectName("supp");
        supp->setGeometry(QRect(850, 10, 41, 41));
        supp->setStyleSheet(QString::fromUtf8("\n"
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
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("effacer.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        supp->setIcon(icon3);
        supp->setIconSize(QSize(25, 25));
        label_16 = new QLabel(groupBox_4);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(150, 30, 251, 20));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setItalic(false);
        label_16->setFont(font2);
        label_16->setStyleSheet(QString::fromUtf8("label_12\n"
"(rgb(0, 0, 100)\n"
"font: 900 italic 14pt \"Segoe UI\";)"));
        tableWidget = new QTableWidget(groupBox_4);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        if (tableWidget->rowCount() < 7)
            tableWidget->setRowCount(7);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 70, 571, 271));
        S1 = new QLineEdit(groupBox_2);
        S1->setObjectName("S1");
        S1->setGeometry(QRect(192, 30, 361, 26));
        groupBox_5 = new QGroupBox(groupBox_2);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(660, 130, 371, 391));
        groupBox_5->setMinimumSize(QSize(371, 0));
        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(20, 10, 161, 31));
        label_12->setFont(font1);
        supp_2 = new QPushButton(groupBox_5);
        supp_2->setObjectName("supp_2");
        supp_2->setGeometry(QRect(850, 10, 41, 41));
        supp_2->setStyleSheet(QString::fromUtf8("\n"
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
        supp_2->setIcon(icon3);
        supp_2->setIconSize(QSize(25, 25));
        groupBox_4->raise();
        label_8->raise();
        filtrage->raise();
        tri->raise();
        label_11->raise();
        pdf->raise();
        stat->raise();
        ok->raise();
        ASC->raise();
        DSC->raise();
        S1->raise();
        groupBox_5->raise();
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(150, 60, 311, 461));
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
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(140, 50, 131, 26));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 90, 151, 20));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(40, 400, 91, 31));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(180, 400, 91, 31));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 0, 301, 41));
        QPalette palette;
        label_9->setPalette(palette);
        label_9->setFont(font1);
        label_9->setStyleSheet(QString::fromUtf8(""));
        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(140, 90, 131, 26));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 140, 151, 20));
        comboBox_4 = new QComboBox(groupBox);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName("comboBox_4");
        comboBox_4->setGeometry(QRect(180, 300, 91, 26));
        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(140, 130, 131, 26));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 190, 151, 20));
        lineEdit_5 = new QLineEdit(groupBox);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(140, 180, 131, 26));
        label_13 = new QLabel(groupBox);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(20, 250, 151, 20));
        lineEdit_7 = new QLineEdit(groupBox);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(140, 240, 131, 26));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(10, 300, 151, 20));
        label_15 = new QLabel(groupBox);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(10, 360, 151, 20));
        lineEdit_8 = new QLineEdit(groupBox);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(180, 360, 91, 26));
        sidebare = new QWidget(centralwidget);
        sidebare->setObjectName("sidebare");
        sidebare->setGeometry(QRect(0, 0, 141, 651));
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
        logo->setPixmap(QPixmap(QString::fromUtf8("../../../Documents/projet_c/application/logo1.png")));
        emp1 = new QPushButton(sidebare);
        emp1->setObjectName("emp1");
        emp1->setGeometry(QRect(0, 150, 141, 41));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../../../Documents/projet_c/projet_c/empe.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        emp1->setIcon(icon4);
        chercheur = new QPushButton(sidebare);
        chercheur->setObjectName("chercheur");
        chercheur->setGeometry(QRect(0, 200, 141, 41));
        chercheur->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("../../../Documents/projet_c/projet_c/cher.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        chercheur->setIcon(icon5);
        vac = new QPushButton(sidebare);
        vac->setObjectName("vac");
        vac->setGeometry(QRect(0, 250, 141, 41));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("../../../Documents/projet_c/projet_c/vaccin.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        vac->setIcon(icon6);
        vac->setIconSize(QSize(20, 20));
        eq = new QPushButton(sidebare);
        eq->setObjectName("eq");
        eq->setGeometry(QRect(0, 300, 141, 41));
        eq->setStyleSheet(QString::fromUtf8(""));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("../../../Documents/projet_c/projet_c/equipement.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        eq->setIcon(icon7);
        client = new QPushButton(sidebare);
        client->setObjectName("client");
        client->setGeometry(QRect(0, 400, 141, 41));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("../../../Documents/projet_c/projet_c/client.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        client->setIcon(icon8);
        test = new QPushButton(sidebare);
        test->setObjectName("test");
        test->setGeometry(QRect(0, 350, 151, 41));
        test->setStyleSheet(QString::fromUtf8(""));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("../../../Documents/projet_c/projet_c/teste.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        test->setIcon(icon9);
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
        logout->setPixmap(QPixmap(QString::fromUtf8("../../../Documents/projet_c/application/logout.png")));
        label_3 = new QLabel(sidebare);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 570, 63, 20));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../../../Documents/projet_c/projet_c/logout.png")));
        label_6 = new QLabel(sidebare);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 40, 111, 91));
        label_6->setPixmap(QPixmap(QString::fromUtf8("../../../Documents/projet_c/projet_c/logo1.png")));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(140, 0, 1391, 51));
        widget->setStyleSheet(QString::fromUtf8(" background-color: #2C3E50; /* Couleur bleu fonc\303\251 */\n"
"    border-right: 2px solid #1A252F;"));
        MainWindow->setCentralWidget(centralwidget);
        groupBox_2->raise();
        groupBox_3->raise();
        groupBox->raise();
        sidebare->raise();
        widget->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1536, 26));
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
        groupBox_3->setTitle(QString());
        radioButton->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        groupBox_2->setTitle(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "rechercher :", nullptr));
        filtrage->setItemText(0, QCoreApplication::translate("MainWindow", "NOM", nullptr));
        filtrage->setItemText(1, QCoreApplication::translate("MainWindow", "EMAIL", nullptr));
        filtrage->setItemText(2, QCoreApplication::translate("MainWindow", "projet en cours", nullptr));

        tri->setItemText(0, QCoreApplication::translate("MainWindow", "nom", nullptr));
        tri->setItemText(1, QCoreApplication::translate("MainWindow", "id", nullptr));
        tri->setItemText(2, QCoreApplication::translate("MainWindow", "projet en cours", nullptr));

        label_11->setText(QCoreApplication::translate("MainWindow", "Tri par :", nullptr));
        pdf->setText(QString());
        stat->setText(QString());
        ok->setText(QString());
        ASC->setText(QCoreApplication::translate("MainWindow", "ASC", nullptr));
        DSC->setText(QCoreApplication::translate("MainWindow", "DSC", nullptr));
        groupBox_4->setTitle(QString());
        label_10->setText(QCoreApplication::translate("MainWindow", "  Listes ", nullptr));
        supp->setText(QString());
        label_16->setText(QCoreApplication::translate("MainWindow", " supprimer un  chercheur", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "prenom", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "telepone", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "email", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "domaine de recherche", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "project en cours", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Historique", nullptr));
        groupBox_5->setTitle(QString());
        label_12->setText(QCoreApplication::translate("MainWindow", "assitance ai", nullptr));
        supp_2->setText(QString());
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Id chercheurs", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "nom", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "valider", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", " Ajout ", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "prenom", nullptr));
        comboBox_4->setItemText(0, QCoreApplication::translate("MainWindow", "Virologie ", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("MainWindow", "Immunologie ", nullptr));
        comboBox_4->setItemText(2, QCoreApplication::translate("MainWindow", "Biotechnologie ", nullptr));

        label_7->setText(QCoreApplication::translate("MainWindow", "telephone", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "email", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "domaine_recherches", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "project_en_cours", nullptr));
        logo->setText(QString());
        emp1->setText(QCoreApplication::translate("MainWindow", "employ\303\251es", nullptr));
        chercheur->setText(QCoreApplication::translate("MainWindow", "chercheurs", nullptr));
        vac->setText(QCoreApplication::translate("MainWindow", "vaccins", nullptr));
        eq->setText(QCoreApplication::translate("MainWindow", "\303\251quipements", nullptr));
        client->setText(QCoreApplication::translate("MainWindow", "clients", nullptr));
        test->setText(QCoreApplication::translate("MainWindow", "tests biologiques", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "D\303\251connexion", nullptr));
        logout->setText(QString());
        label_3->setText(QString());
        label_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
