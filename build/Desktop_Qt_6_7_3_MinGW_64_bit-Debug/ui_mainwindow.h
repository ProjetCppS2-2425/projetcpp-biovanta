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
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *bg;
    QLabel *nombre_doses;
    QWidget *sidebare;
    QPushButton *emp;
    QPushButton *chercheur_;
    QPushButton *vac_2;
    QPushButton *eq_2;
    QPushButton *client_2;
    QPushButton *test_2;
    QPushButton *pushButton_10;
    QLabel *logo;
    QLabel *logout_2;
    QGroupBox *groupBox_3;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QLabel *type_vaccin;
    QGroupBox *groupBox;
    QPushButton *pushButton_7;
    QPushButton *pushButton_9;
    QLabel *label_22;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_16;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_17;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_23;
    QComboBox *comboBox_10;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_18;
    QComboBox *comboBox_11;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_19;
    QLineEdit *lineEdit_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_20;
    QDateEdit *dateEdit;
    QGroupBox *groupBox_2;
    QLabel *label_13;
    QLabel *label_14;
    QComboBox *cb_rech_emp;
    QComboBox *comboBox_7;
    QLabel *label_15;
    QPushButton *pdf_2;
    QPushButton *stat_2;
    QPushButton *ok_2;
    QTableView *tableView_vaccin;
    QLineEdit *le_rech;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QPushButton *pushButton_6;
    QLineEdit *vaccin_id_input;
    QLabel *labelFan;
    QWidget *tab_2;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QTextEdit *chatTextEdit_2;
    QPushButton *sendButton_2;
    QLineEdit *inputLineEdit_2;
    QLabel *bg_3;
    QPushButton *pushButton_2;
    QWidget *page_4;
    QLabel *bg_4;
    QLabel *label;
    QPushButton *pushButton_11;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1208, 649);
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
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 0, 1181, 581));
        tab = new QWidget();
        tab->setObjectName("tab");
        bg = new QLabel(tab);
        bg->setObjectName("bg");
        bg->setGeometry(QRect(140, 0, 1071, 701));
        bg->setPixmap(QPixmap(QString::fromUtf8("bg.jpg")));
        nombre_doses = new QLabel(tab);
        nombre_doses->setObjectName("nombre_doses");
        nombre_doses->setGeometry(QRect(470, 610, 211, 16));
        sidebare = new QWidget(tab);
        sidebare->setObjectName("sidebare");
        sidebare->setGeometry(QRect(-2, 1, 141, 651));
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
        emp = new QPushButton(sidebare);
        emp->setObjectName("emp");
        emp->setGeometry(QRect(0, 150, 141, 41));
        QIcon icon;
        icon.addFile(QString::fromUtf8("empe.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        emp->setIcon(icon);
        chercheur_ = new QPushButton(sidebare);
        chercheur_->setObjectName("chercheur_");
        chercheur_->setGeometry(QRect(0, 200, 141, 41));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../projet_c/projet_c/cher.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        chercheur_->setIcon(icon1);
        vac_2 = new QPushButton(sidebare);
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
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../projet_c/projet_c/vaccin.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        vac_2->setIcon(icon2);
        vac_2->setIconSize(QSize(20, 20));
        eq_2 = new QPushButton(sidebare);
        eq_2->setObjectName("eq_2");
        eq_2->setGeometry(QRect(0, 300, 141, 41));
        eq_2->setStyleSheet(QString::fromUtf8(""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../projet_c/projet_c/equipement.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        eq_2->setIcon(icon3);
        client_2 = new QPushButton(sidebare);
        client_2->setObjectName("client_2");
        client_2->setGeometry(QRect(0, 400, 141, 41));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../projet_c/projet_c/client.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        client_2->setIcon(icon4);
        test_2 = new QPushButton(sidebare);
        test_2->setObjectName("test_2");
        test_2->setGeometry(QRect(0, 350, 151, 41));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("../projet_c/projet_c/teste.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        test_2->setIcon(icon5);
        pushButton_10 = new QPushButton(sidebare);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(30, 522, 111, 31));
        pushButton_10->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_10 {\n"
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
        logo = new QLabel(sidebare);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(10, 10, 121, 101));
        logo->setPixmap(QPixmap(QString::fromUtf8("logo1.png")));
        logout_2 = new QLabel(sidebare);
        logout_2->setObjectName("logout_2");
        logout_2->setGeometry(QRect(10, 530, 41, 21));
        logout_2->setPixmap(QPixmap(QString::fromUtf8("logout.png")));
        emp->raise();
        chercheur_->raise();
        vac_2->raise();
        eq_2->raise();
        client_2->raise();
        test_2->raise();
        pushButton_10->raise();
        logout_2->raise();
        logo->raise();
        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(148, 510, 311, 91));
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #02767F; /* Couleur turquoise pour la bordure */\n"
"    border-radius: 10px;  /* Coins arrondis */\n"
"    padding: 10px;  /* Espacement interne */\n"
"    margin-bottom: 20px;  /* Espacement en bas */\n"
"}\n"
""));
        radioButton_3 = new QRadioButton(groupBox_3);
        radioButton_3->setObjectName("radioButton_3");
        radioButton_3->setGeometry(QRect(30, 20, 110, 24));
        radioButton_4 = new QRadioButton(groupBox_3);
        radioButton_4->setObjectName("radioButton_4");
        radioButton_4->setGeometry(QRect(180, 20, 110, 24));
        type_vaccin = new QLabel(tab);
        type_vaccin->setObjectName("type_vaccin");
        type_vaccin->setGeometry(QRect(210, 610, 211, 16));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(148, 61, 311, 461));
        groupBox->setAutoFillBackground(false);
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #02767F; /* Couleur turquoise pour la bordure */\n"
"    border-radius: 10px;  /* Coins arrondis */\n"
"    padding: 10px;  /* Espacement interne */\n"
"    margin-bottom: 20px;  /* Espacement en bas */\n"
"}\n"
""));
        pushButton_7 = new QPushButton(groupBox);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(40, 400, 71, 31));
        pushButton_9 = new QPushButton(groupBox);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(180, 400, 71, 31));
        label_22 = new QLabel(groupBox);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(30, 0, 301, 41));
        QPalette palette;
        label_22->setPalette(palette);
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Variable")});
        font.setPointSize(14);
        font.setBold(true);
        font.setUnderline(true);
        label_22->setFont(font);
        label_22->setStyleSheet(QString::fromUtf8(""));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 80, 271, 271));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName("label_16");

        horizontalLayout->addWidget(label_16);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName("lineEdit_2");

        horizontalLayout->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_17 = new QLabel(layoutWidget);
        label_17->setObjectName("label_17");

        horizontalLayout_2->addWidget(label_17);

        lineEdit_4 = new QLineEdit(layoutWidget);
        lineEdit_4->setObjectName("lineEdit_4");

        horizontalLayout_2->addWidget(lineEdit_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_23 = new QLabel(layoutWidget);
        label_23->setObjectName("label_23");

        horizontalLayout_3->addWidget(label_23);

        comboBox_10 = new QComboBox(layoutWidget);
        comboBox_10->addItem(QString());
        comboBox_10->addItem(QString());
        comboBox_10->addItem(QString());
        comboBox_10->setObjectName("comboBox_10");

        horizontalLayout_3->addWidget(comboBox_10);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_18 = new QLabel(layoutWidget);
        label_18->setObjectName("label_18");

        horizontalLayout_4->addWidget(label_18);

        comboBox_11 = new QComboBox(layoutWidget);
        comboBox_11->addItem(QString());
        comboBox_11->addItem(QString());
        comboBox_11->setObjectName("comboBox_11");

        horizontalLayout_4->addWidget(comboBox_11);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_19 = new QLabel(layoutWidget);
        label_19->setObjectName("label_19");

        horizontalLayout_5->addWidget(label_19);

        lineEdit_5 = new QLineEdit(layoutWidget);
        lineEdit_5->setObjectName("lineEdit_5");

        horizontalLayout_5->addWidget(lineEdit_5);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_20 = new QLabel(layoutWidget);
        label_20->setObjectName("label_20");

        horizontalLayout_6->addWidget(label_20);

        dateEdit = new QDateEdit(layoutWidget);
        dateEdit->setObjectName("dateEdit");

        horizontalLayout_6->addWidget(dateEdit);


        verticalLayout->addLayout(horizontalLayout_6);

        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(470, 60, 731, 541));
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
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(190, 60, 101, 20));
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(20, 10, 341, 31));
        label_14->setFont(font);
        cb_rech_emp = new QComboBox(groupBox_2);
        cb_rech_emp->addItem(QString());
        cb_rech_emp->addItem(QString());
        cb_rech_emp->addItem(QString());
        cb_rech_emp->addItem(QString());
        cb_rech_emp->setObjectName("cb_rech_emp");
        cb_rech_emp->setGeometry(QRect(270, 55, 111, 31));
        comboBox_7 = new QComboBox(groupBox_2);
        comboBox_7->addItem(QString());
        comboBox_7->addItem(QString());
        comboBox_7->addItem(QString());
        comboBox_7->setObjectName("comboBox_7");
        comboBox_7->setGeometry(QRect(242, 120, 181, 31));
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(200, 120, 63, 31));
        pdf_2 = new QPushButton(groupBox_2);
        pdf_2->setObjectName("pdf_2");
        pdf_2->setGeometry(QRect(140, 120, 51, 31));
        pdf_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    qproperty-iconSize: 21px 21px;  /* Taille de l'ic\303\264ne */\n"
"    text-align: center; /* Centrage du texte si besoin */\n"
"}\n"
""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("../projet_c/projet_c/pdf1.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pdf_2->setIcon(icon6);
        pdf_2->setIconSize(QSize(21, 21));
        stat_2 = new QPushButton(groupBox_2);
        stat_2->setObjectName("stat_2");
        stat_2->setGeometry(QRect(560, 120, 81, 31));
        stat_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    qproperty-iconSize: 21px 21px;  /* Taille de l'ic\303\264ne */\n"
"    text-align: center; /* Centrage du texte si besoin */\n"
"}\n"
""));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("../projet_c/projet_c/st.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        stat_2->setIcon(icon7);
        stat_2->setIconSize(QSize(21, 21));
        ok_2 = new QPushButton(groupBox_2);
        ok_2->setObjectName("ok_2");
        ok_2->setGeometry(QRect(650, 40, 61, 51));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("../projet_c/projet_c/search.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        ok_2->setIcon(icon8);
        ok_2->setIconSize(QSize(40, 40));
        tableView_vaccin = new QTableView(groupBox_2);
        tableView_vaccin->setObjectName("tableView_vaccin");
        tableView_vaccin->setGeometry(QRect(10, 180, 701, 321));
        le_rech = new QLineEdit(groupBox_2);
        le_rech->setObjectName("le_rech");
        le_rech->setGeometry(QRect(390, 55, 231, 31));
        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(430, 123, 51, 22));
        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setGeometry(QRect(487, 123, 51, 22));
        pushButton_6 = new QPushButton(groupBox_2);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(650, 120, 71, 31));
        pushButton_6->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"        background-color: #ff4d4d;  /* Rouge */\n"
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
        vaccin_id_input = new QLineEdit(groupBox_2);
        vaccin_id_input->setObjectName("vaccin_id_input");
        vaccin_id_input->setGeometry(QRect(64, 120, 71, 31));
        labelFan = new QLabel(tab);
        labelFan->setObjectName("labelFan");
        labelFan->setGeometry(QRect(310, 30, 291, 16));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        stackedWidget = new QStackedWidget(tab_2);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(30, 20, 1131, 511));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        chatTextEdit_2 = new QTextEdit(page_3);
        chatTextEdit_2->setObjectName("chatTextEdit_2");
        chatTextEdit_2->setGeometry(QRect(0, 20, 1111, 401));
        sendButton_2 = new QPushButton(page_3);
        sendButton_2->setObjectName("sendButton_2");
        sendButton_2->setGeometry(QRect(810, 430, 201, 61));
        inputLineEdit_2 = new QLineEdit(page_3);
        inputLineEdit_2->setObjectName("inputLineEdit_2");
        inputLineEdit_2->setGeometry(QRect(120, 430, 651, 61));
        bg_3 = new QLabel(page_3);
        bg_3->setObjectName("bg_3");
        bg_3->setGeometry(QRect(-80, -70, 1221, 731));
        bg_3->setPixmap(QPixmap(QString::fromUtf8("bg.jpg")));
        pushButton_2 = new QPushButton(page_3);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(960, 30, 131, 41));
        stackedWidget->addWidget(page_3);
        bg_3->raise();
        chatTextEdit_2->raise();
        sendButton_2->raise();
        inputLineEdit_2->raise();
        pushButton_2->raise();
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        bg_4 = new QLabel(page_4);
        bg_4->setObjectName("bg_4");
        bg_4->setGeometry(QRect(-130, 30, 1221, 731));
        bg_4->setPixmap(QPixmap(QString::fromUtf8("bg.jpg")));
        label = new QLabel(page_4);
        label->setObjectName("label");
        label->setGeometry(QRect(68, 10, 850, 600));
        pushButton_11 = new QPushButton(page_4);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(840, 650, 101, 31));
        pushButton_11->setStyleSheet(QString::fromUtf8("QPushButton {\n"
" 	font: 14pt \"Sitka Text\";\n"
"   	background-color: transparent;\n"
"    border: 1px solid  #000000;\n"
"    color: #000000;\n"
"    padding: 5px 5px;\n"
"    border-radius: 5px;\n"
"    transition: background-color 0.3s ease;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	\n"
"	font: 75 italic 14pt \"Sitka Text\";\n"
"    background-color: #transparent;\n"
"	color: #000000;\n"
" 	border: 1px solid  #FFFFFF;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    color: black;\n"
"}"));
        pushButton = new QPushButton(page_4);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(980, 60, 71, 41));
        stackedWidget->addWidget(page_4);
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1208, 18));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        bg->setText(QString());
        nombre_doses->setText(QString());
        emp->setText(QCoreApplication::translate("MainWindow", "employ\303\251es", nullptr));
        chercheur_->setText(QCoreApplication::translate("MainWindow", "chercheurs", nullptr));
        vac_2->setText(QCoreApplication::translate("MainWindow", "vaccins", nullptr));
        eq_2->setText(QCoreApplication::translate("MainWindow", "\303\251quipements", nullptr));
        client_2->setText(QCoreApplication::translate("MainWindow", "clients", nullptr));
        test_2->setText(QCoreApplication::translate("MainWindow", "tests biologiques", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "D\303\251connexion", nullptr));
        logo->setText(QString());
        logout_2->setText(QString());
        groupBox_3->setTitle(QString());
        radioButton_3->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        radioButton_4->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        type_vaccin->setText(QString());
        groupBox->setTitle(QString());
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "valider", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", " Ajout ", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Id_vaccin", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Nom_vaccin", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "type_vaccin", nullptr));
        comboBox_10->setItemText(0, QCoreApplication::translate("MainWindow", "ARNm", nullptr));
        comboBox_10->setItemText(1, QCoreApplication::translate("MainWindow", "actif", nullptr));
        comboBox_10->setItemText(2, QCoreApplication::translate("MainWindow", "inactif", nullptr));

        label_18->setText(QCoreApplication::translate("MainWindow", "nombre_doses", nullptr));
        comboBox_11->setItemText(0, QCoreApplication::translate("MainWindow", "unidose", nullptr));
        comboBox_11->setItemText(1, QCoreApplication::translate("MainWindow", "multidose", nullptr));

        label_19->setText(QCoreApplication::translate("MainWindow", "temperature_conservation", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "date_expiration", nullptr));
        groupBox_2->setTitle(QString());
        label_13->setText(QCoreApplication::translate("MainWindow", "rechercher :", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "  Listes ", nullptr));
        cb_rech_emp->setItemText(0, QCoreApplication::translate("MainWindow", "type_vaccin", nullptr));
        cb_rech_emp->setItemText(1, QCoreApplication::translate("MainWindow", "id_vaccin", nullptr));
        cb_rech_emp->setItemText(2, QCoreApplication::translate("MainWindow", "nom_vaccin", nullptr));
        cb_rech_emp->setItemText(3, QCoreApplication::translate("MainWindow", "temperature_conservation", nullptr));

        comboBox_7->setItemText(0, QCoreApplication::translate("MainWindow", "nom_vaccin", nullptr));
        comboBox_7->setItemText(1, QCoreApplication::translate("MainWindow", "temperature_conservation", nullptr));
        comboBox_7->setItemText(2, QCoreApplication::translate("MainWindow", "date_expiration", nullptr));

        label_15->setText(QCoreApplication::translate("MainWindow", "Tri par :", nullptr));
        pdf_2->setText(QString());
        stat_2->setText(QString());
        ok_2->setText(QString());
        checkBox->setText(QCoreApplication::translate("MainWindow", "ASC", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "DSC", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        labelFan->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        sendButton_2->setText(QCoreApplication::translate("MainWindow", "Envoyer", nullptr));
        bg_3->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Aller vers stats", nullptr));
        bg_4->setText(QString());
        label->setText(QString());
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "Fermer", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Retour", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
