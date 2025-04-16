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
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *sidebare;
    QLabel *logo;
    QPushButton *emp1;
    QPushButton *chercheur;
    QPushButton *vac;
    QPushButton *eq;
    QPushButton *client;
    QPushButton *pushButton_8;
    QLabel *logout;
    QLabel *label_3;
    QLabel *label_6;
    QWidget *widget;
    QStackedWidget *stackedWidget;
    QWidget *page_5;
    QPushButton *test;
    QGroupBox *groupBox_12;
    QLabel *label_49;
    QComboBox *filtrage_4;
    QComboBox *tri_4;
    QLabel *label_50;
    QPushButton *pdf_4;
    QPushButton *stat_4;
    QPushButton *ok_4;
    QCheckBox *ASC_4;
    QCheckBox *DSC_4;
    QGroupBox *groupBox_14;
    QLabel *label_51;
    QPushButton *supp_6;
    QLabel *label_52;
    QTableWidget *tableWidget_4;
    QLineEdit *S1_4;
    QPushButton *btn_goToStats;
    QGroupBox *groupBox_15;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QGroupBox *groupBox_11;
    QLabel *label_41;
    QLineEdit *lineEdit_1;
    QLabel *label_42;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QLabel *label_43;
    QLineEdit *lineEdit_19;
    QLabel *label_44;
    QComboBox *comboBox_7;
    QLineEdit *lineEdit_20;
    QLabel *label_45;
    QLineEdit *lineEdit_21;
    QLabel *label_46;
    QLineEdit *lineEdit_23;
    QLabel *label_47;
    QLabel *label_48;
    QLineEdit *lineEdit_24;
    QWidget *page_6;
    QPushButton *btn_backHome;
    QPushButton *btn_goToReports;
    QPushButton *mk;
    QWidget *page_7;
    QTableWidget *tableWidget_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1752, 670);
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
        sidebare = new QWidget(centralwidget);
        sidebare->setObjectName("sidebare");
        sidebare->setGeometry(QRect(0, 0, 131, 651));
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
        logo->setGeometry(QRect(20, 20, 81, 111));
        logo->setPixmap(QPixmap(QString::fromUtf8("../../../Documents/projet_c/application/logo1.png")));
        emp1 = new QPushButton(sidebare);
        emp1->setObjectName("emp1");
        emp1->setGeometry(QRect(0, 150, 141, 41));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../Documents/projet_c/projet_c/empe.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        emp1->setIcon(icon);
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../Documents/projet_c/projet_c/cher.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        chercheur->setIcon(icon1);
        vac = new QPushButton(sidebare);
        vac->setObjectName("vac");
        vac->setGeometry(QRect(0, 250, 141, 41));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../../../Documents/projet_c/projet_c/vaccin.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        vac->setIcon(icon2);
        vac->setIconSize(QSize(20, 20));
        eq = new QPushButton(sidebare);
        eq->setObjectName("eq");
        eq->setGeometry(QRect(0, 300, 141, 41));
        eq->setStyleSheet(QString::fromUtf8(""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../../../Documents/projet_c/projet_c/equipement.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        eq->setIcon(icon3);
        client = new QPushButton(sidebare);
        client->setObjectName("client");
        client->setGeometry(QRect(0, 400, 141, 41));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../../../Documents/projet_c/projet_c/client.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        client->setIcon(icon4);
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
        widget->setGeometry(QRect(120, 0, 1391, 51));
        widget->setStyleSheet(QString::fromUtf8(" background-color: #2C3E50; /* Couleur bleu fonc\303\251 */\n"
"    border-right: 2px solid #1A252F;"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(140, 60, 1391, 561));
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        test = new QPushButton(page_5);
        test->setObjectName("test");
        test->setGeometry(QRect(-160, 280, 151, 41));
        test->setStyleSheet(QString::fromUtf8(""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("../../../Documents/projet_c/projet_c/teste.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        test->setIcon(icon5);
        groupBox_12 = new QGroupBox(page_5);
        groupBox_12->setObjectName("groupBox_12");
        groupBox_12->setGeometry(QRect(330, 10, 1041, 571));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        groupBox_12->setFont(font);
        groupBox_12->setStyleSheet(QString::fromUtf8("/* Tableau principal */\n"
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
        label_49 = new QLabel(groupBox_12);
        label_49->setObjectName("label_49");
        label_49->setGeometry(QRect(100, 30, 101, 20));
        filtrage_4 = new QComboBox(groupBox_12);
        filtrage_4->addItem(QString());
        filtrage_4->addItem(QString());
        filtrage_4->addItem(QString());
        filtrage_4->addItem(QString());
        filtrage_4->setObjectName("filtrage_4");
        filtrage_4->setGeometry(QRect(560, 30, 71, 21));
        tri_4 = new QComboBox(groupBox_12);
        tri_4->addItem(QString());
        tri_4->addItem(QString());
        tri_4->addItem(QString());
        tri_4->setObjectName("tri_4");
        tri_4->setGeometry(QRect(370, 80, 151, 31));
        label_50 = new QLabel(groupBox_12);
        label_50->setObjectName("label_50");
        label_50->setGeometry(QRect(300, 80, 63, 31));
        pdf_4 = new QPushButton(groupBox_12);
        pdf_4->setObjectName("pdf_4");
        pdf_4->setGeometry(QRect(190, 80, 81, 31));
        pdf_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    qproperty-iconSize: 21px 21px;  /* Taille de l'ic\303\264ne */\n"
"    text-align: center; /* Centrage du texte si besoin */\n"
"}\n"
""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("pdf1.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pdf_4->setIcon(icon6);
        pdf_4->setIconSize(QSize(21, 21));
        stat_4 = new QPushButton(groupBox_12);
        stat_4->setObjectName("stat_4");
        stat_4->setGeometry(QRect(660, 80, 81, 31));
        stat_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    qproperty-iconSize: 21px 21px;  /* Taille de l'ic\303\264ne */\n"
"    text-align: center; /* Centrage du texte si besoin */\n"
"}\n"
""));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("st.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        stat_4->setIcon(icon7);
        stat_4->setIconSize(QSize(21, 21));
        ok_4 = new QPushButton(groupBox_12);
        ok_4->setObjectName("ok_4");
        ok_4->setGeometry(QRect(650, 20, 61, 51));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("search.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        ok_4->setIcon(icon8);
        ok_4->setIconSize(QSize(40, 40));
        ASC_4 = new QCheckBox(groupBox_12);
        ASC_4->setObjectName("ASC_4");
        ASC_4->setGeometry(QRect(530, 90, 91, 24));
        DSC_4 = new QCheckBox(groupBox_12);
        DSC_4->setObjectName("DSC_4");
        DSC_4->setGeometry(QRect(590, 90, 91, 24));
        groupBox_14 = new QGroupBox(groupBox_12);
        groupBox_14->setObjectName("groupBox_14");
        groupBox_14->setGeometry(QRect(20, 130, 1001, 411));
        label_51 = new QLabel(groupBox_14);
        label_51->setObjectName("label_51");
        label_51->setGeometry(QRect(20, 10, 161, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI Variable")});
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setUnderline(true);
        label_51->setFont(font1);
        supp_6 = new QPushButton(groupBox_14);
        supp_6->setObjectName("supp_6");
        supp_6->setGeometry(QRect(930, 10, 41, 41));
        supp_6->setStyleSheet(QString::fromUtf8("\n"
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
        icon9.addFile(QString::fromUtf8("effacer.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        supp_6->setIcon(icon9);
        supp_6->setIconSize(QSize(25, 25));
        label_52 = new QLabel(groupBox_14);
        label_52->setObjectName("label_52");
        label_52->setGeometry(QRect(670, 20, 251, 20));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setItalic(false);
        label_52->setFont(font2);
        label_52->setStyleSheet(QString::fromUtf8("label_12\n"
"(rgb(0, 0, 100)\n"
"font: 900 italic 14pt \"Segoe UI\";)"));
        label_52->setTextFormat(Qt::TextFormat::PlainText);
        tableWidget_4 = new QTableWidget(groupBox_14);
        if (tableWidget_4->columnCount() < 8)
            tableWidget_4->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        if (tableWidget_4->rowCount() < 7)
            tableWidget_4->setRowCount(7);
        tableWidget_4->setObjectName("tableWidget_4");
        tableWidget_4->setGeometry(QRect(30, 60, 911, 311));
        S1_4 = new QLineEdit(groupBox_12);
        S1_4->setObjectName("S1_4");
        S1_4->setGeometry(QRect(192, 30, 361, 26));
        btn_goToStats = new QPushButton(groupBox_12);
        btn_goToStats->setObjectName("btn_goToStats");
        btn_goToStats->setGeometry(QRect(920, 10, 93, 29));
        groupBox_15 = new QGroupBox(page_5);
        groupBox_15->setObjectName("groupBox_15");
        groupBox_15->setGeometry(QRect(10, 490, 311, 91));
        groupBox_15->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #02767F; /* Couleur turquoise pour la bordure */\n"
"    border-radius: 10px;  /* Coins arrondis */\n"
"    padding: 10px;  /* Espacement interne */\n"
"    margin-bottom: 20px;  /* Espacement en bas */\n"
"}\n"
""));
        radioButton_5 = new QRadioButton(groupBox_15);
        radioButton_5->setObjectName("radioButton_5");
        radioButton_5->setGeometry(QRect(30, 20, 110, 24));
        radioButton_6 = new QRadioButton(groupBox_15);
        radioButton_6->setObjectName("radioButton_6");
        radioButton_6->setGeometry(QRect(180, 20, 110, 24));
        groupBox_11 = new QGroupBox(page_5);
        groupBox_11->setObjectName("groupBox_11");
        groupBox_11->setGeometry(QRect(10, 10, 311, 491));
        groupBox_11->setAutoFillBackground(false);
        groupBox_11->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #02767F; /* Couleur turquoise pour la bordure */\n"
"    border-radius: 10px;  /* Coins arrondis */\n"
"    padding: 10px;  /* Espacement interne */\n"
"    margin-bottom: 20px;  /* Espacement en bas */\n"
"}\n"
""));
        label_41 = new QLabel(groupBox_11);
        label_41->setObjectName("label_41");
        label_41->setGeometry(QRect(20, 50, 131, 20));
        lineEdit_1 = new QLineEdit(groupBox_11);
        lineEdit_1->setObjectName("lineEdit_1");
        lineEdit_1->setGeometry(QRect(140, 50, 131, 26));
        label_42 = new QLabel(groupBox_11);
        label_42->setObjectName("label_42");
        label_42->setGeometry(QRect(20, 90, 151, 20));
        pushButton_9 = new QPushButton(groupBox_11);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(40, 400, 91, 31));
        pushButton_10 = new QPushButton(groupBox_11);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(180, 400, 91, 31));
        label_43 = new QLabel(groupBox_11);
        label_43->setObjectName("label_43");
        label_43->setGeometry(QRect(10, 10, 301, 21));
        QPalette palette;
        label_43->setPalette(palette);
        label_43->setFont(font1);
        label_43->setStyleSheet(QString::fromUtf8(""));
        lineEdit_19 = new QLineEdit(groupBox_11);
        lineEdit_19->setObjectName("lineEdit_19");
        lineEdit_19->setGeometry(QRect(140, 90, 131, 26));
        label_44 = new QLabel(groupBox_11);
        label_44->setObjectName("label_44");
        label_44->setGeometry(QRect(20, 140, 151, 20));
        comboBox_7 = new QComboBox(groupBox_11);
        comboBox_7->addItem(QString());
        comboBox_7->addItem(QString());
        comboBox_7->addItem(QString());
        comboBox_7->setObjectName("comboBox_7");
        comboBox_7->setGeometry(QRect(180, 300, 91, 26));
        lineEdit_20 = new QLineEdit(groupBox_11);
        lineEdit_20->setObjectName("lineEdit_20");
        lineEdit_20->setGeometry(QRect(140, 130, 131, 26));
        label_45 = new QLabel(groupBox_11);
        label_45->setObjectName("label_45");
        label_45->setGeometry(QRect(20, 190, 151, 20));
        lineEdit_21 = new QLineEdit(groupBox_11);
        lineEdit_21->setObjectName("lineEdit_21");
        lineEdit_21->setGeometry(QRect(140, 180, 131, 26));
        label_46 = new QLabel(groupBox_11);
        label_46->setObjectName("label_46");
        label_46->setGeometry(QRect(20, 250, 151, 20));
        lineEdit_23 = new QLineEdit(groupBox_11);
        lineEdit_23->setObjectName("lineEdit_23");
        lineEdit_23->setGeometry(QRect(140, 240, 131, 26));
        label_47 = new QLabel(groupBox_11);
        label_47->setObjectName("label_47");
        label_47->setGeometry(QRect(10, 300, 151, 20));
        label_48 = new QLabel(groupBox_11);
        label_48->setObjectName("label_48");
        label_48->setGeometry(QRect(10, 360, 151, 20));
        lineEdit_24 = new QLineEdit(groupBox_11);
        lineEdit_24->setObjectName("lineEdit_24");
        lineEdit_24->setGeometry(QRect(180, 360, 91, 26));
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        btn_backHome = new QPushButton(page_6);
        btn_backHome->setObjectName("btn_backHome");
        btn_backHome->setGeometry(QRect(20, 10, 93, 29));
        btn_goToReports = new QPushButton(page_6);
        btn_goToReports->setObjectName("btn_goToReports");
        btn_goToReports->setGeometry(QRect(1240, 30, 93, 29));
        mk = new QPushButton(page_6);
        mk->setObjectName("mk");
        mk->setGeometry(QRect(810, 290, 93, 29));
        stackedWidget->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName("page_7");
        tableWidget_5 = new QTableWidget(page_7);
        if (tableWidget_5->columnCount() < 4)
            tableWidget_5->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        if (tableWidget_5->rowCount() < 5)
            tableWidget_5->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_5->setVerticalHeaderItem(0, __qtablewidgetitem12);
        tableWidget_5->setObjectName("tableWidget_5");
        tableWidget_5->setGeometry(QRect(75, 101, 521, 231));
        stackedWidget->addWidget(page_7);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1752, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        logo->setText(QString());
        emp1->setText(QCoreApplication::translate("MainWindow", "employ\303\251es", nullptr));
        chercheur->setText(QCoreApplication::translate("MainWindow", "chercheurs", nullptr));
        vac->setText(QCoreApplication::translate("MainWindow", "vaccins", nullptr));
        eq->setText(QCoreApplication::translate("MainWindow", "\303\251quipements", nullptr));
        client->setText(QCoreApplication::translate("MainWindow", "clients", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "D\303\251connexion", nullptr));
        logout->setText(QString());
        label_3->setText(QString());
        label_6->setText(QString());
        test->setText(QCoreApplication::translate("MainWindow", "tests biologiques", nullptr));
        groupBox_12->setTitle(QString());
        label_49->setText(QCoreApplication::translate("MainWindow", "rechercher :", nullptr));
        filtrage_4->setItemText(0, QCoreApplication::translate("MainWindow", "NOM", nullptr));
        filtrage_4->setItemText(1, QCoreApplication::translate("MainWindow", "EMAIL", nullptr));
        filtrage_4->setItemText(2, QCoreApplication::translate("MainWindow", "projet en cours", nullptr));
        filtrage_4->setItemText(3, QCoreApplication::translate("MainWindow", "id", nullptr));

        tri_4->setItemText(0, QCoreApplication::translate("MainWindow", "nom", nullptr));
        tri_4->setItemText(1, QCoreApplication::translate("MainWindow", "id", nullptr));
        tri_4->setItemText(2, QCoreApplication::translate("MainWindow", "projet en cours", nullptr));

        label_50->setText(QCoreApplication::translate("MainWindow", "Tri par :", nullptr));
        pdf_4->setText(QString());
        stat_4->setText(QString());
        ok_4->setText(QString());
        ASC_4->setText(QCoreApplication::translate("MainWindow", "ASC", nullptr));
        DSC_4->setText(QCoreApplication::translate("MainWindow", "DSC", nullptr));
        groupBox_14->setTitle(QString());
        label_51->setText(QCoreApplication::translate("MainWindow", "  Listes ", nullptr));
        supp_6->setText(QString());
        label_52->setText(QCoreApplication::translate("MainWindow", "supprimer un chercheur", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_4->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_4->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_4->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "prenom", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_4->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "telepone", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_4->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "email", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_4->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "domaine de recherche", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_4->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "project en cours", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_4->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Historique", nullptr));
        btn_goToStats->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        groupBox_15->setTitle(QString());
        radioButton_5->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        radioButton_6->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        groupBox_11->setTitle(QString());
        label_41->setText(QCoreApplication::translate("MainWindow", "Id chercheurs", nullptr));
        label_42->setText(QCoreApplication::translate("MainWindow", "nom", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "valider", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        label_43->setText(QCoreApplication::translate("MainWindow", " Ajout ", nullptr));
        label_44->setText(QCoreApplication::translate("MainWindow", "prenom", nullptr));
        comboBox_7->setItemText(0, QCoreApplication::translate("MainWindow", "Virologie ", nullptr));
        comboBox_7->setItemText(1, QCoreApplication::translate("MainWindow", "Immunologie ", nullptr));
        comboBox_7->setItemText(2, QCoreApplication::translate("MainWindow", "Biotechnologie ", nullptr));

        label_45->setText(QCoreApplication::translate("MainWindow", "telephone", nullptr));
        label_46->setText(QCoreApplication::translate("MainWindow", "email", nullptr));
        label_47->setText(QCoreApplication::translate("MainWindow", "domaine_recherches", nullptr));
        label_48->setText(QCoreApplication::translate("MainWindow", "project_en_cours", nullptr));
        btn_backHome->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        btn_goToReports->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        mk->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_5->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_5->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "project en cours", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_5->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "rapport", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_5->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "id", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_5->verticalHeaderItem(0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
