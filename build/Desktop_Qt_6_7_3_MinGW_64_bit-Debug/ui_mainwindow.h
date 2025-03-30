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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
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
    QLabel *label_3;
    QPushButton *pushButton;
    QLabel *label_5;
    QComboBox *comboBox_2;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_9;
    QComboBox *comboBox_3;
    QSpinBox *spinBox;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QComboBox *comboBox_4;
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
    QGroupBox *groupBox_2;
    QTableWidget *tableWidget;
    QLabel *label_8;
    QComboBox *comboBox_5;
    QComboBox *comboBox;
    QLabel *label_11;
    QPushButton *pdf;
    QPushButton *stat;
    QPushButton *ok;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QGroupBox *groupBox_4;
    QLabel *label_10;
    QPushButton *supp;
    QLabel *label_13;
    QLabel *labelImage;
    QLineEdit *lineEdit_2;
    QGroupBox *groupBox_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLabel *bg;
    QFrame *frame;
    QPushButton *pushButton_5;
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
        groupBox->setGeometry(QRect(160, 80, 311, 461));
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
        lineEdit->setGeometry(QRect(180, 50, 91, 26));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 90, 151, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 210, 63, 20));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(170, 190, 111, 41));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 250, 63, 20));
        comboBox_2 = new QComboBox(groupBox);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(165, 250, 111, 26));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 300, 131, 20));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 350, 171, 20));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(40, 400, 91, 31));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(180, 400, 91, 31));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(30, 0, 301, 41));
        QPalette palette;
        label_9->setPalette(palette);
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Variable")});
        font.setPointSize(14);
        font.setBold(true);
        font.setUnderline(true);
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8(""));
        comboBox_3 = new QComboBox(groupBox);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(160, 300, 121, 26));
        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(210, 350, 42, 26));
        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(180, 90, 91, 26));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 140, 151, 20));
        comboBox_4 = new QComboBox(groupBox);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName("comboBox_4");
        comboBox_4->setGeometry(QRect(170, 140, 131, 26));
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
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(480, 81, 991, 541));
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
        tableWidget = new QTableWidget(groupBox_2);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
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
        if (tableWidget->rowCount() < 8)
            tableWidget->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setItem(0, 4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setItem(0, 5, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setItem(0, 6, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setItem(1, 4, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setItem(1, 5, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setItem(1, 6, __qtablewidgetitem16);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(110, 190, 741, 281));
        tableWidget->setStyleSheet(QString::fromUtf8("tableWidget->setStyleSheet(\n"
"    \"QTableWidget {\"\n"
"    \"   background-color: #f8f9fa;\"\n"
"    \"   gridline-color: #dee2e6;\"\n"
"    \"   font-size: 14px;\"\n"
"    \"}\"\n"
"    \"QHeaderView::section {\"\n"
"    \"   background-color: #007bff;\"\n"
"    \"   color: white;\"\n"
"    \"   padding: 5px;\"\n"
"    \"   border: 1px solid #0056b3;\"\n"
"    \"}\"\n"
"    \"QTableWidget::item {\"\n"
"    \"   padding: 5px;\"\n"
"    \"}\"\n"
"    \"QTableWidget::item:selected {\"\n"
"    \"   background-color: #ffc107;\"\n"
"    \"   color: black;\"\n"
"    \"}\"\n"
");\n"
""));
        tableWidget->setRowCount(8);
        tableWidget->setColumnCount(7);
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(190, 30, 101, 20));
        comboBox_5 = new QComboBox(groupBox_2);
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->setObjectName("comboBox_5");
        comboBox_5->setGeometry(QRect(270, 30, 61, 31));
        comboBox = new QComboBox(groupBox_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(370, 80, 151, 31));
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
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("pdf1.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pdf->setIcon(icon6);
        pdf->setIconSize(QSize(21, 21));
        stat = new QPushButton(groupBox_2);
        stat->setObjectName("stat");
        stat->setGeometry(QRect(670, 80, 81, 31));
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
        ok->setGeometry(QRect(650, 20, 61, 51));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("search.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        ok->setIcon(icon8);
        ok->setIconSize(QSize(40, 40));
        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(530, 90, 91, 24));
        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setGeometry(QRect(590, 90, 91, 24));
        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(50, 130, 841, 391));
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 10, 161, 31));
        label_10->setFont(font);
        supp = new QPushButton(groupBox_4);
        supp->setObjectName("supp");
        supp->setGeometry(QRect(750, 10, 41, 41));
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
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("effacer.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        supp->setIcon(icon9);
        supp->setIconSize(QSize(25, 25));
        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(550, 20, 251, 20));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setItalic(false);
        label_13->setFont(font2);
        label_13->setStyleSheet(QString::fromUtf8("label_12\n"
"(rgb(0, 0, 100)\n"
"font: 900 italic 14pt \"Segoe UI\";)"));
        labelImage = new QLabel(groupBox_2);
        labelImage->setObjectName("labelImage");
        labelImage->setGeometry(QRect(380, 270, 63, 20));
        lineEdit_2 = new QLineEdit(groupBox_2);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(340, 30, 291, 31));
        labelImage->raise();
        groupBox_4->raise();
        tableWidget->raise();
        label_8->raise();
        comboBox_5->raise();
        comboBox->raise();
        label_11->raise();
        pdf->raise();
        stat->raise();
        ok->raise();
        checkBox->raise();
        checkBox_2->raise();
        lineEdit_2->raise();
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(160, 530, 311, 91));
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
        radioButton_2 = new QRadioButton(groupBox_3);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(180, 20, 110, 24));
        bg = new QLabel(centralwidget);
        bg->setObjectName("bg");
        bg->setGeometry(QRect(130, -10, 1411, 631));
        bg->setPixmap(QPixmap(QString::fromUtf8("../application/bg.jpg")));
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
        pushButton_5 = new QPushButton(frame);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(60, 10, 131, 31));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        MainWindow->setCentralWidget(centralwidget);
        bg->raise();
        groupBox->raise();
        sidebare->raise();
        groupBox_2->raise();
        groupBox_3->raise();
        frame->raise();
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
        label->setText(QCoreApplication::translate("MainWindow", "Id \303\251quipement", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Nom de l'\303\251quipement", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Image", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "choisir image", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Etat ", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "Fonctionnel ", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "pas Fonctionnel ", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "Nouvel \303\251l\303\251ment", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("MainWindow", "En maintenance", nullptr));

        label_6->setText(QCoreApplication::translate("MainWindow", "Disponibilit\303\251 ", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Nombre de l'\303\251quipement ", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "valider", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", " Ajout ", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("MainWindow", "disponible", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("MainWindow", "pas disponible", nullptr));

        label_4->setText(QCoreApplication::translate("MainWindow", "type", nullptr));
        comboBox_4->setItemText(0, QCoreApplication::translate("MainWindow", "Appareil de laboratoire", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("MainWindow", "Appareil de diagnostic", nullptr));
        comboBox_4->setItemText(2, QCoreApplication::translate("MainWindow", "R\303\251frig\303\251ration et Stockage des Vaccins", nullptr));

        logo->setText(QString());
        emp1->setText(QCoreApplication::translate("MainWindow", "employ\303\251es", nullptr));
        chercheur->setText(QCoreApplication::translate("MainWindow", "chercheurs", nullptr));
        vac->setText(QCoreApplication::translate("MainWindow", "vaccins", nullptr));
        eq->setText(QCoreApplication::translate("MainWindow", "\303\251quipements", nullptr));
        client->setText(QCoreApplication::translate("MainWindow", "clients", nullptr));
        test->setText(QCoreApplication::translate("MainWindow", "tests biologiques", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "D\303\251connexion", nullptr));
        logout->setText(QString());
        groupBox_2->setTitle(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Id \303\251quipement ", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Nom ", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "image ", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "type", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "\303\251tat", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Disponibilit\303\251 ", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "nombre", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->item(1, 0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "01245", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->item(1, 1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Microscopes optiques", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->item(1, 4);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "marche ", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->item(1, 5);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "disponible", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->item(1, 6);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

        label_8->setText(QCoreApplication::translate("MainWindow", "rechercher :", nullptr));
        comboBox_5->setItemText(0, QCoreApplication::translate("MainWindow", "type", nullptr));
        comboBox_5->setItemText(1, QCoreApplication::translate("MainWindow", "id \303\251quipement ", nullptr));
        comboBox_5->setItemText(2, QCoreApplication::translate("MainWindow", "disponibilit\303\251", nullptr));

        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\303\251tat", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "nbre d'\303\251quipement", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "nom d'\303\251quipement", nullptr));

        label_11->setText(QCoreApplication::translate("MainWindow", "Tri par :", nullptr));
        pdf->setText(QString());
        stat->setText(QString());
        ok->setText(QString());
        checkBox->setText(QCoreApplication::translate("MainWindow", "ASC", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "DSC", nullptr));
        groupBox_4->setTitle(QString());
        label_10->setText(QCoreApplication::translate("MainWindow", "  Listes ", nullptr));
        supp->setText(QString());
        label_13->setText(QCoreApplication::translate("MainWindow", " supprimer un \303\251quipement :", nullptr));
        labelImage->setText(QString());
        groupBox_3->setTitle(QString());
        radioButton->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        bg->setText(QString());
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "fonctionnalit\303\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
