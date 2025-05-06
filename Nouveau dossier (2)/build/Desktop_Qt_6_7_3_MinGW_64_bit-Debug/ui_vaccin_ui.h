/********************************************************************************
** Form generated from reading UI file 'vaccin_ui.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VACCIN_UI_H
#define UI_VACCIN_UI_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_vaccin_ui
{
public:
    QGroupBox *groupBox_3;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
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
    QComboBox *comboBox_6;
    QComboBox *comboBox_7;
    QLabel *label_15;
    QPushButton *pushButton_5;
    QPushButton *pdf_2;
    QPushButton *stat_2;
    QPushButton *ok_2;
    QTableView *tableView_vaccin;
    QLabel *bg;
    QLabel *type_vaccin;
    QLabel *nombre_doses;

    void setupUi(QDialog *vaccin_ui)
    {
        if (vaccin_ui->objectName().isEmpty())
            vaccin_ui->setObjectName("vaccin_ui");
        vaccin_ui->resize(1211, 646);
        groupBox_3 = new QGroupBox(vaccin_ui);
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
        sidebare = new QWidget(vaccin_ui);
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
        pushButton_10->setGeometry(QRect(30, 560, 111, 31));
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
        logout_2->setGeometry(QRect(10, 560, 41, 21));
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
        groupBox = new QGroupBox(vaccin_ui);
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

        groupBox_2 = new QGroupBox(vaccin_ui);
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
        comboBox_6 = new QComboBox(groupBox_2);
        comboBox_6->addItem(QString());
        comboBox_6->addItem(QString());
        comboBox_6->addItem(QString());
        comboBox_6->setObjectName("comboBox_6");
        comboBox_6->setGeometry(QRect(270, 55, 351, 31));
        comboBox_7 = new QComboBox(groupBox_2);
        comboBox_7->addItem(QString());
        comboBox_7->addItem(QString());
        comboBox_7->addItem(QString());
        comboBox_7->setObjectName("comboBox_7");
        comboBox_7->setGeometry(QRect(370, 120, 151, 31));
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(300, 120, 63, 31));
        pushButton_5 = new QPushButton(groupBox_2);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(680, 120, 31, 31));
        pushButton_5->setStyleSheet(QString::fromUtf8("\n"
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
        pdf_2 = new QPushButton(groupBox_2);
        pdf_2->setObjectName("pdf_2");
        pdf_2->setGeometry(QRect(190, 120, 81, 31));
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
        bg = new QLabel(vaccin_ui);
        bg->setObjectName("bg");
        bg->setGeometry(QRect(140, 0, 1071, 701));
        bg->setPixmap(QPixmap(QString::fromUtf8("bg.jpg")));
        type_vaccin = new QLabel(vaccin_ui);
        type_vaccin->setObjectName("type_vaccin");
        type_vaccin->setGeometry(QRect(210, 610, 211, 16));
        nombre_doses = new QLabel(vaccin_ui);
        nombre_doses->setObjectName("nombre_doses");
        nombre_doses->setGeometry(QRect(470, 610, 211, 16));
        bg->raise();
        groupBox_3->raise();
        sidebare->raise();
        groupBox->raise();
        groupBox_2->raise();
        type_vaccin->raise();
        nombre_doses->raise();

        retranslateUi(vaccin_ui);

        QMetaObject::connectSlotsByName(vaccin_ui);
    } // setupUi

    void retranslateUi(QDialog *vaccin_ui)
    {
        vaccin_ui->setWindowTitle(QCoreApplication::translate("vaccin_ui", "Dialog", nullptr));
        groupBox_3->setTitle(QString());
        radioButton_3->setText(QCoreApplication::translate("vaccin_ui", "Ajouter", nullptr));
        radioButton_4->setText(QCoreApplication::translate("vaccin_ui", "Modifier", nullptr));
        emp->setText(QCoreApplication::translate("vaccin_ui", "employ\303\251es", nullptr));
        chercheur_->setText(QCoreApplication::translate("vaccin_ui", "chercheurs", nullptr));
        vac_2->setText(QCoreApplication::translate("vaccin_ui", "vaccins", nullptr));
        eq_2->setText(QCoreApplication::translate("vaccin_ui", "\303\251quipements", nullptr));
        client_2->setText(QCoreApplication::translate("vaccin_ui", "clients", nullptr));
        test_2->setText(QCoreApplication::translate("vaccin_ui", "tests biologiques", nullptr));
        pushButton_10->setText(QCoreApplication::translate("vaccin_ui", "D\303\251connexion", nullptr));
        logo->setText(QString());
        logout_2->setText(QString());
        groupBox->setTitle(QString());
        pushButton_7->setText(QCoreApplication::translate("vaccin_ui", "valider", nullptr));
        pushButton_9->setText(QCoreApplication::translate("vaccin_ui", "Annuler", nullptr));
        label_22->setText(QCoreApplication::translate("vaccin_ui", " Ajout ", nullptr));
        label_16->setText(QCoreApplication::translate("vaccin_ui", "Id_vaccin", nullptr));
        label_17->setText(QCoreApplication::translate("vaccin_ui", "Nom_vaccin", nullptr));
        label_23->setText(QCoreApplication::translate("vaccin_ui", "type_vaccin", nullptr));
        comboBox_10->setItemText(0, QCoreApplication::translate("vaccin_ui", "ARNm", nullptr));
        comboBox_10->setItemText(1, QCoreApplication::translate("vaccin_ui", "actif", nullptr));
        comboBox_10->setItemText(2, QCoreApplication::translate("vaccin_ui", "inactif", nullptr));

        label_18->setText(QCoreApplication::translate("vaccin_ui", "nombre_doses", nullptr));
        comboBox_11->setItemText(0, QCoreApplication::translate("vaccin_ui", "unidose", nullptr));
        comboBox_11->setItemText(1, QCoreApplication::translate("vaccin_ui", "multidose", nullptr));

        label_19->setText(QCoreApplication::translate("vaccin_ui", "temperature_conservation", nullptr));
        label_20->setText(QCoreApplication::translate("vaccin_ui", "date_expiration", nullptr));
        groupBox_2->setTitle(QString());
        label_13->setText(QCoreApplication::translate("vaccin_ui", "rechercher :", nullptr));
        label_14->setText(QCoreApplication::translate("vaccin_ui", "  Listes ", nullptr));
        comboBox_6->setItemText(0, QCoreApplication::translate("vaccin_ui", "type_vaccin", nullptr));
        comboBox_6->setItemText(1, QCoreApplication::translate("vaccin_ui", "id \303\251quipement ", nullptr));
        comboBox_6->setItemText(2, QCoreApplication::translate("vaccin_ui", "disponibilit\303\251", nullptr));

        comboBox_7->setItemText(0, QCoreApplication::translate("vaccin_ui", "nom_vaccin", nullptr));
        comboBox_7->setItemText(1, QCoreApplication::translate("vaccin_ui", "nbre d'\303\251quipement", nullptr));
        comboBox_7->setItemText(2, QCoreApplication::translate("vaccin_ui", "nom d'\303\251quipement", nullptr));

        label_15->setText(QCoreApplication::translate("vaccin_ui", "Tri par :", nullptr));
        pushButton_5->setText(QCoreApplication::translate("vaccin_ui", " X", nullptr));
        pdf_2->setText(QString());
        stat_2->setText(QString());
        ok_2->setText(QString());
        bg->setText(QString());
        type_vaccin->setText(QString());
        nombre_doses->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class vaccin_ui: public Ui_vaccin_ui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VACCIN_UI_H
