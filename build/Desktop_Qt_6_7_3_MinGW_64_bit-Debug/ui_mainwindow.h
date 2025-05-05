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
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_9;
    QLineEdit *lineEdit_3;
    QComboBox *comboBox_4;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *lineEdit_2;
    QLabel *label_16;
    QDateEdit *dateEdit;
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
    QGroupBox *groupBox_2;
    QTableWidget *tableWidget;
    QLabel *label_8;
    QLabel *label_10;
    QComboBox *comboBox_5;
    QComboBox *comboBox;
    QLabel *label_11;
    QPushButton *pdfButton;
    QPushButton *stat;
    QPushButton *ok;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit_4;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QGroupBox *groupBox_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QPushButton *suppButton;
    QLabel *bg;
    QLabel *label_5;
    QWidget *widget;
    QPushButton *pushButton;
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
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(160, 50, 311, 461));
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
        label->setGeometry(QRect(20, 110, 131, 20));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"}\n"
""));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(180, 100, 91, 26));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 150, 151, 20));
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"}\n"
""));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(180, 390, 91, 31));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(50, 390, 91, 31));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 10, 301, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Variable")});
        font.setPointSize(14);
        font.setBold(true);
        font.setUnderline(true);
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"}\n"
""));
        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(180, 150, 91, 26));
        comboBox_4 = new QComboBox(groupBox);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName("comboBox_4");
        comboBox_4->setGeometry(QRect(180, 200, 91, 26));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(20, 200, 151, 20));
        label_14->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"}\n"
""));
        label_15 = new QLabel(groupBox);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(10, 250, 151, 20));
        label_15->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"}\n"
""));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(190, 310, 91, 26));
        label_16 = new QLabel(groupBox);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(10, 310, 161, 20));
        label_16->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"}\n"
""));
        dateEdit = new QDateEdit(groupBox);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(180, 250, 110, 29));
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
        chercheur->setStyleSheet(QString::fromUtf8(""));
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
        eq->setStyleSheet(QString::fromUtf8(""));
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
        test->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_3 = new QLabel(sidebare);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 570, 63, 20));
        label_3->setPixmap(QPixmap(QString::fromUtf8("logout.png")));
        label_6 = new QLabel(sidebare);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 20, 151, 121));
        label_6->setPixmap(QPixmap(QString::fromUtf8("logo1.png")));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(480, 80, 731, 501));
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
        tableWidget = new QTableWidget(groupBox_2);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
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
        if (tableWidget->rowCount() < 8)
            tableWidget->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem8);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 200, 701, 261));
        tableWidget->setRowCount(8);
        tableWidget->setColumnCount(5);
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(120, 50, 101, 20));
        label_8->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"}\n"
""));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 10, 341, 31));
        QFont font1;
        font1.setPointSize(11);
        font1.setUnderline(true);
        label_10->setFont(font1);
        label_10->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"}\n"
""));
        comboBox_5 = new QComboBox(groupBox_2);
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->setObjectName("comboBox_5");
        comboBox_5->setGeometry(QRect(510, 40, 71, 31));
        comboBox = new QComboBox(groupBox_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(550, 120, 151, 31));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(470, 120, 63, 31));
        label_11->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"}\n"
""));
        pdfButton = new QPushButton(groupBox_2);
        pdfButton->setObjectName("pdfButton");
        pdfButton->setGeometry(QRect(250, 140, 81, 31));
        pdfButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    qproperty-iconSize: 21px 21px;  /* Taille de l'ic\303\264ne */\n"
"    text-align: center; /* Centrage du texte si besoin */\n"
"}\n"
""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("pdf1.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pdfButton->setIcon(icon6);
        pdfButton->setIconSize(QSize(21, 21));
        stat = new QPushButton(groupBox_2);
        stat->setObjectName("stat");
        stat->setGeometry(QRect(160, 140, 81, 31));
        stat->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    qproperty-iconSize: 21px 21px;  /* Taille de l'ic\303\264ne */\n"
"    text-align: center; /* Centrage du texte si besoin */\n"
"}\n"
""));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("st.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        stat->setIcon(icon7);
        stat->setIconSize(QSize(21, 21));
        ok = new QPushButton(groupBox_2);
        ok->setObjectName("ok");
        ok->setGeometry(QRect(600, 30, 61, 51));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("search.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        ok->setIcon(icon8);
        ok->setIconSize(QSize(40, 40));
        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(70, 140, 81, 31));
        lineEdit_4 = new QLineEdit(groupBox_2);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(220, 50, 261, 26));
        radioButton_3 = new QRadioButton(groupBox_2);
        radioButton_3->setObjectName("radioButton_3");
        radioButton_3->setGeometry(QRect(410, 170, 110, 24));
        radioButton_4 = new QRadioButton(groupBox_2);
        radioButton_4->setObjectName("radioButton_4");
        radioButton_4->setGeometry(QRect(480, 170, 110, 24));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(160, 500, 311, 131));
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #02767F; /* Couleur turquoise pour la bordure */\n"
"    border-radius: 10px;  /* Coins arrondis */\n"
"    padding: 10px;  /* Espacement interne */\n"
"    margin-bottom: 20px;  /* Espacement en bas */\n"
"}\n"
""));
        radioButton = new QRadioButton(groupBox_3);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(30, 20, 110, 24));
        radioButton->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    color: black;\n"
"}\n"
""));
        radioButton_2 = new QRadioButton(groupBox_3);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(150, 20, 110, 24));
        radioButton_2->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    color: black;\n"
"}\n"
""));
        suppButton = new QPushButton(groupBox_3);
        suppButton->setObjectName("suppButton");
        suppButton->setGeometry(QRect(110, 50, 111, 41));
        bg = new QLabel(centralwidget);
        bg->setObjectName("bg");
        bg->setGeometry(QRect(150, -20, 1411, 631));
        bg->setPixmap(QPixmap(QString::fromUtf8("../application/bg.jpg")));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(150, 0, 1071, 651));
        label_5->setPixmap(QPixmap(QString::fromUtf8("bg.jpg")));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(150, 0, 1071, 41));
        widget->setStyleSheet(QString::fromUtf8(" background-color: #2C3E50; /* Couleur bleu fonc\303\251 */\n"
"    border-right: 2px solid #1A252F;"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 10, 141, 31));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: #02767F;  /* Vert fonc\303\251 */\n"
"    color: white;   "));
        MainWindow->setCentralWidget(centralwidget);
        label_5->raise();
        bg->raise();
        groupBox->raise();
        sidebare->raise();
        groupBox_2->raise();
        groupBox_3->raise();
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
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Id test", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "nom", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "valider", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", " Ajout ", nullptr));
        comboBox_4->setItemText(0, QCoreApplication::translate("MainWindow", "urine", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("MainWindow", "sang", nullptr));
        comboBox_4->setItemText(2, QCoreApplication::translate("MainWindow", "tissu", nullptr));

        label_14->setText(QCoreApplication::translate("MainWindow", "type", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Date de pr\303\251l\303\250vement", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Chercheur_responsable", nullptr));
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
        groupBox_2->setTitle(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Id test", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "type", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Date de pr\303\251l\303\250vement", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Chercheur responsable", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        tableWidget->setSortingEnabled(__sortingEnabled);

        label_8->setText(QCoreApplication::translate("MainWindow", "Rechercher :", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "  Listes ", nullptr));
        comboBox_5->setItemText(0, QCoreApplication::translate("MainWindow", "type", nullptr));
        comboBox_5->setItemText(1, QCoreApplication::translate("MainWindow", "id test", nullptr));
        comboBox_5->setItemText(2, QCoreApplication::translate("MainWindow", "nom", nullptr));

        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "type", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "nom", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Id test", nullptr));

        label_11->setText(QCoreApplication::translate("MainWindow", "Tri par :", nullptr));
        pdfButton->setText(QString());
        stat->setText(QString());
        ok->setText(QString());
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "QR Code", nullptr));
        radioButton_3->setText(QCoreApplication::translate("MainWindow", "ASC", nullptr));
        radioButton_4->setText(QCoreApplication::translate("MainWindow", "DSC", nullptr));
        groupBox_3->setTitle(QString());
        radioButton->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        suppButton->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        bg->setText(QString());
        label_5->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "fonctionnalite", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
