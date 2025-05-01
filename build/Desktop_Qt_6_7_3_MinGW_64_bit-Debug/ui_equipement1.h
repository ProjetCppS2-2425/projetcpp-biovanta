/********************************************************************************
** Form generated from reading UI file 'equipement1.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EQUIPEMENT1_H
#define UI_EQUIPEMENT1_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
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
    QPushButton *test;
    QPushButton *pushButton_8;
    QLabel *logout;
    QFrame *frame;
    QPushButton *noti;
    QLabel *notificationBadge;
    QPushButton *calen;
    QLabel *label_23;
    QStackedWidget *stackedWidget;
    QWidget *page_stats;
    QWidget *page_liste;
    QGroupBox *groupBox_2;
    QTableWidget *tableWidget_3;
    QLabel *label_25;
    QComboBox *comboBox_11;
    QComboBox *comboBox_12;
    QLabel *label_26;
    QPushButton *pdf_3;
    QPushButton *stat_3;
    QPushButton *ok_3;
    QGroupBox *groupBox_6;
    QLabel *label_27;
    QPushButton *supp_3;
    QLabel *label_28;
    QLabel *labelImage_3;
    QLineEdit *lineEdit_7;
    QPushButton *pushButton_10;
    QRadioButton *radioButton_9;
    QRadioButton *radioButton_10;
    QGroupBox *groupBox;
    QLabel *label_29;
    QLineEdit *lineEdit_8;
    QLabel *label_30;
    QLabel *label_31;
    QPushButton *pushButton_11;
    QLabel *label_32;
    QComboBox *comboBox_13;
    QLabel *label_33;
    QLabel *label_34;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QLabel *label_35;
    QComboBox *comboBox_14;
    QSpinBox *spinBox_3;
    QLineEdit *lineEdit_9;
    QLabel *label_36;
    QComboBox *comboBox_15;
    QLabel *label;
    QDateEdit *dateEditDebut;
    QLabel *label_2;
    QDateEdit *dateEditFin;
    QLabel *res;
    QComboBox *comboBox_16;
    QLabel *bg;
    QGroupBox *groupBox_3;
    QRadioButton *radioButton_11;
    QRadioButton *radioButton_12;
    QWidget *calender_page;
    QCalendarWidget *calendarWidget;
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
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(150, 0, 1391, 61));
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
        noti = new QPushButton(frame);
        noti->setObjectName("noti");
        noti->setGeometry(QRect(70, 10, 61, 41));
        noti->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("notif.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        noti->setIcon(icon6);
        noti->setIconSize(QSize(42, 42));
        notificationBadge = new QLabel(frame);
        notificationBadge->setObjectName("notificationBadge");
        notificationBadge->setGeometry(QRect(90, 10, 41, 20));
        calen = new QPushButton(frame);
        calen->setObjectName("calen");
        calen->setGeometry(QRect(170, 10, 51, 41));
        calen->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("calend.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        calen->setIcon(icon7);
        calen->setIconSize(QSize(60, 60));
        label_23 = new QLabel(frame);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(610, 10, 241, 41));
        notificationBadge->raise();
        label_23->raise();
        noti->raise();
        calen->raise();
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(150, 60, 1381, 561));
        page_stats = new QWidget();
        page_stats->setObjectName("page_stats");
        stackedWidget->addWidget(page_stats);
        page_liste = new QWidget();
        page_liste->setObjectName("page_liste");
        groupBox_2 = new QGroupBox(page_liste);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(410, 21, 941, 541));
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
        tableWidget_3 = new QTableWidget(groupBox_2);
        if (tableWidget_3->columnCount() < 8)
            tableWidget_3->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        if (tableWidget_3->rowCount() < 8)
            tableWidget_3->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_3->setItem(0, 0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_3->setItem(0, 1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_3->setItem(0, 4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_3->setItem(0, 5, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_3->setItem(0, 6, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_3->setItem(1, 0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_3->setItem(1, 1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_3->setItem(1, 4, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_3->setItem(1, 5, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_3->setItem(1, 6, __qtablewidgetitem17);
        tableWidget_3->setObjectName("tableWidget_3");
        tableWidget_3->setGeometry(QRect(110, 190, 741, 281));
        tableWidget_3->setStyleSheet(QString::fromUtf8("tableWidget->setStyleSheet(\n"
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
        tableWidget_3->setRowCount(8);
        tableWidget_3->setColumnCount(8);
        label_25 = new QLabel(groupBox_2);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(190, 30, 101, 20));
        comboBox_11 = new QComboBox(groupBox_2);
        comboBox_11->addItem(QString());
        comboBox_11->addItem(QString());
        comboBox_11->addItem(QString());
        comboBox_11->setObjectName("comboBox_11");
        comboBox_11->setGeometry(QRect(270, 30, 61, 31));
        comboBox_12 = new QComboBox(groupBox_2);
        comboBox_12->addItem(QString());
        comboBox_12->addItem(QString());
        comboBox_12->addItem(QString());
        comboBox_12->setObjectName("comboBox_12");
        comboBox_12->setGeometry(QRect(370, 80, 151, 31));
        label_26 = new QLabel(groupBox_2);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(300, 80, 63, 31));
        pdf_3 = new QPushButton(groupBox_2);
        pdf_3->setObjectName("pdf_3");
        pdf_3->setGeometry(QRect(190, 80, 81, 31));
        pdf_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    qproperty-iconSize: 21px 21px;  /* Taille de l'ic\303\264ne */\n"
"    text-align: center; /* Centrage du texte si besoin */\n"
"}\n"
""));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("pdf1.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pdf_3->setIcon(icon8);
        pdf_3->setIconSize(QSize(21, 21));
        stat_3 = new QPushButton(groupBox_2);
        stat_3->setObjectName("stat_3");
        stat_3->setGeometry(QRect(670, 80, 81, 31));
        stat_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    qproperty-iconSize: 21px 21px;  /* Taille de l'ic\303\264ne */\n"
"    text-align: center; /* Centrage du texte si besoin */\n"
"}\n"
""));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("st.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        stat_3->setIcon(icon9);
        stat_3->setIconSize(QSize(21, 21));
        ok_3 = new QPushButton(groupBox_2);
        ok_3->setObjectName("ok_3");
        ok_3->setGeometry(QRect(650, 20, 61, 51));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8("search.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        ok_3->setIcon(icon10);
        ok_3->setIconSize(QSize(40, 40));
        groupBox_6 = new QGroupBox(groupBox_2);
        groupBox_6->setObjectName("groupBox_6");
        groupBox_6->setGeometry(QRect(50, 130, 841, 391));
        label_27 = new QLabel(groupBox_6);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(20, 10, 161, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI Variable")});
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setUnderline(true);
        label_27->setFont(font1);
        supp_3 = new QPushButton(groupBox_6);
        supp_3->setObjectName("supp_3");
        supp_3->setGeometry(QRect(750, 10, 41, 41));
        supp_3->setStyleSheet(QString::fromUtf8("\n"
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
        QIcon icon11;
        icon11.addFile(QString::fromUtf8("effacer.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        supp_3->setIcon(icon11);
        supp_3->setIconSize(QSize(25, 25));
        label_28 = new QLabel(groupBox_6);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(520, 20, 251, 20));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setItalic(false);
        label_28->setFont(font2);
        label_28->setStyleSheet(QString::fromUtf8("label_12\n"
"(rgb(0, 0, 100)\n"
"font: 900 italic 14pt \"Segoe UI\";)"));
        labelImage_3 = new QLabel(groupBox_2);
        labelImage_3->setObjectName("labelImage_3");
        labelImage_3->setGeometry(QRect(380, 270, 63, 20));
        lineEdit_7 = new QLineEdit(groupBox_2);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(340, 30, 291, 31));
        pushButton_10 = new QPushButton(groupBox_2);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(740, 30, 51, 41));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8("loading-arrow.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_10->setIcon(icon12);
        pushButton_10->setIconSize(QSize(30, 30));
        radioButton_9 = new QRadioButton(groupBox_2);
        radioButton_9->setObjectName("radioButton_9");
        radioButton_9->setGeometry(QRect(530, 90, 110, 24));
        radioButton_10 = new QRadioButton(groupBox_2);
        radioButton_10->setObjectName("radioButton_10");
        radioButton_10->setGeometry(QRect(590, 90, 110, 24));
        groupBox_6->raise();
        tableWidget_3->raise();
        label_25->raise();
        comboBox_11->raise();
        comboBox_12->raise();
        label_26->raise();
        pdf_3->raise();
        stat_3->raise();
        ok_3->raise();
        labelImage_3->raise();
        lineEdit_7->raise();
        pushButton_10->raise();
        radioButton_9->raise();
        radioButton_10->raise();
        groupBox = new QGroupBox(page_liste);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 20, 381, 461));
        groupBox->setAutoFillBackground(false);
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #02767F; /* Couleur turquoise pour la bordure */\n"
"    border-radius: 10px;  /* Coins arrondis */\n"
"    padding: 10px;  /* Espacement interne */\n"
"    margin-bottom: 20px;  /* Espacement en bas */\n"
"}\n"
""));
        label_29 = new QLabel(groupBox);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(30, 40, 131, 20));
        lineEdit_8 = new QLineEdit(groupBox);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(210, 40, 91, 26));
        label_30 = new QLabel(groupBox);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(20, 80, 151, 20));
        label_31 = new QLabel(groupBox);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(30, 160, 63, 20));
        pushButton_11 = new QPushButton(groupBox);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(190, 150, 111, 41));
        label_32 = new QLabel(groupBox);
        label_32->setObjectName("label_32");
        label_32->setGeometry(QRect(40, 210, 63, 20));
        comboBox_13 = new QComboBox(groupBox);
        comboBox_13->addItem(QString());
        comboBox_13->addItem(QString());
        comboBox_13->addItem(QString());
        comboBox_13->addItem(QString());
        comboBox_13->setObjectName("comboBox_13");
        comboBox_13->setGeometry(QRect(190, 210, 111, 26));
        label_33 = new QLabel(groupBox);
        label_33->setObjectName("label_33");
        label_33->setGeometry(QRect(30, 250, 131, 20));
        label_34 = new QLabel(groupBox);
        label_34->setObjectName("label_34");
        label_34->setGeometry(QRect(20, 290, 171, 20));
        pushButton_12 = new QPushButton(groupBox);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(40, 400, 91, 31));
        pushButton_13 = new QPushButton(groupBox);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(180, 400, 91, 31));
        label_35 = new QLabel(groupBox);
        label_35->setObjectName("label_35");
        label_35->setGeometry(QRect(20, 0, 301, 41));
        QPalette palette;
        label_35->setPalette(palette);
        label_35->setFont(font1);
        label_35->setStyleSheet(QString::fromUtf8(""));
        comboBox_14 = new QComboBox(groupBox);
        comboBox_14->addItem(QString());
        comboBox_14->addItem(QString());
        comboBox_14->setObjectName("comboBox_14");
        comboBox_14->setGeometry(QRect(190, 250, 121, 26));
        spinBox_3 = new QSpinBox(groupBox);
        spinBox_3->setObjectName("spinBox_3");
        spinBox_3->setGeometry(QRect(240, 290, 42, 26));
        lineEdit_9 = new QLineEdit(groupBox);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setGeometry(QRect(210, 80, 91, 26));
        label_36 = new QLabel(groupBox);
        label_36->setObjectName("label_36");
        label_36->setGeometry(QRect(30, 120, 91, 20));
        comboBox_15 = new QComboBox(groupBox);
        comboBox_15->addItem(QString());
        comboBox_15->addItem(QString());
        comboBox_15->addItem(QString());
        comboBox_15->setObjectName("comboBox_15");
        comboBox_15->setGeometry(QRect(190, 110, 131, 26));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 330, 71, 21));
        dateEditDebut = new QDateEdit(groupBox);
        dateEditDebut->setObjectName("dateEditDebut");
        dateEditDebut->setGeometry(QRect(90, 330, 110, 26));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(200, 340, 63, 20));
        dateEditFin = new QDateEdit(groupBox);
        dateEditFin->setObjectName("dateEditFin");
        dateEditFin->setGeometry(QRect(260, 330, 110, 26));
        res = new QLabel(groupBox);
        res->setObjectName("res");
        res->setGeometry(QRect(20, 370, 161, 20));
        comboBox_16 = new QComboBox(groupBox);
        comboBox_16->addItem(QString());
        comboBox_16->addItem(QString());
        comboBox_16->setObjectName("comboBox_16");
        comboBox_16->setGeometry(QRect(200, 370, 111, 26));
        bg = new QLabel(page_liste);
        bg->setObjectName("bg");
        bg->setGeometry(QRect(-10, -70, 1411, 631));
        bg->setPixmap(QPixmap(QString::fromUtf8("../application/bg.jpg")));
        groupBox_3 = new QGroupBox(page_liste);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(10, 470, 381, 91));
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #02767F; /* Couleur turquoise pour la bordure */\n"
"    border-radius: 10px;  /* Coins arrondis */\n"
"    padding: 10px;  /* Espacement interne */\n"
"    margin-bottom: 20px;  /* Espacement en bas */\n"
"}\n"
""));
        radioButton_11 = new QRadioButton(groupBox_3);
        radioButton_11->setObjectName("radioButton_11");
        radioButton_11->setGeometry(QRect(60, 20, 110, 24));
        radioButton_12 = new QRadioButton(groupBox_3);
        radioButton_12->setObjectName("radioButton_12");
        radioButton_12->setGeometry(QRect(220, 20, 110, 24));
        stackedWidget->addWidget(page_liste);
        bg->raise();
        groupBox_2->raise();
        groupBox_3->raise();
        groupBox->raise();
        calender_page = new QWidget();
        calender_page->setObjectName("calender_page");
        calendarWidget = new QCalendarWidget(calender_page);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setGeometry(QRect(60, 80, 1201, 461));
        stackedWidget->addWidget(calender_page);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1536, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


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
        test->setText(QCoreApplication::translate("MainWindow", "tests biologiques", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "D\303\251connexion", nullptr));
        logout->setText(QString());
        noti->setText(QString());
        notificationBadge->setText(QString());
        calen->setText(QString());
        label_23->setText(QString());
        groupBox_2->setTitle(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget_3->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Id \303\251quipement ", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_3->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Nom ", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_3->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "image ", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_3->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "type", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_3->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "\303\251tat", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_3->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Disponibilit\303\251 ", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_3->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "nombre", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_3->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "resistance_eq_feu", nullptr));

        const bool __sortingEnabled = tableWidget_3->isSortingEnabled();
        tableWidget_3->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_3->item(1, 0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "01245", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_3->item(1, 1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Microscopes optiques", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_3->item(1, 4);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "marche ", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_3->item(1, 5);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "disponible", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_3->item(1, 6);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        tableWidget_3->setSortingEnabled(__sortingEnabled);

        label_25->setText(QCoreApplication::translate("MainWindow", "rechercher :", nullptr));
        comboBox_11->setItemText(0, QCoreApplication::translate("MainWindow", "type", nullptr));
        comboBox_11->setItemText(1, QCoreApplication::translate("MainWindow", "id \303\251quipement ", nullptr));
        comboBox_11->setItemText(2, QCoreApplication::translate("MainWindow", "disponibilit\303\251", nullptr));

        comboBox_12->setItemText(0, QCoreApplication::translate("MainWindow", "\303\251tat", nullptr));
        comboBox_12->setItemText(1, QCoreApplication::translate("MainWindow", "nbre d'\303\251quipement", nullptr));
        comboBox_12->setItemText(2, QCoreApplication::translate("MainWindow", "nom d'\303\251quipement", nullptr));

        label_26->setText(QCoreApplication::translate("MainWindow", "Tri par :", nullptr));
        pdf_3->setText(QString());
        stat_3->setText(QString());
        ok_3->setText(QString());
        groupBox_6->setTitle(QString());
        label_27->setText(QCoreApplication::translate("MainWindow", "  Listes ", nullptr));
        supp_3->setText(QString());
        label_28->setText(QCoreApplication::translate("MainWindow", " supprimer un \303\251quipement :", nullptr));
        labelImage_3->setText(QString());
        pushButton_10->setText(QString());
        radioButton_9->setText(QCoreApplication::translate("MainWindow", "ASC", nullptr));
        radioButton_10->setText(QCoreApplication::translate("MainWindow", "DSC", nullptr));
        groupBox->setTitle(QString());
        label_29->setText(QCoreApplication::translate("MainWindow", "Id \303\251quipement", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "Nom de l'\303\251quipement", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "Image", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "choisir image", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "Etat ", nullptr));
        comboBox_13->setItemText(0, QCoreApplication::translate("MainWindow", "Fonctionnel ", nullptr));
        comboBox_13->setItemText(1, QCoreApplication::translate("MainWindow", "pas Fonctionnel ", nullptr));
        comboBox_13->setItemText(2, QCoreApplication::translate("MainWindow", "pas fonctionnel incendie", nullptr));
        comboBox_13->setItemText(3, QCoreApplication::translate("MainWindow", "En maintenance", nullptr));

        label_33->setText(QCoreApplication::translate("MainWindow", "Disponibilit\303\251 ", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "Nombre de l'\303\251quipement ", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "valider", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", " Ajout ", nullptr));
        comboBox_14->setItemText(0, QCoreApplication::translate("MainWindow", "disponible", nullptr));
        comboBox_14->setItemText(1, QCoreApplication::translate("MainWindow", "pas disponible", nullptr));

        label_36->setText(QCoreApplication::translate("MainWindow", "type", nullptr));
        comboBox_15->setItemText(0, QCoreApplication::translate("MainWindow", "Appareil de laboratoire", nullptr));
        comboBox_15->setItemText(1, QCoreApplication::translate("MainWindow", "Appareil de diagnostic", nullptr));
        comboBox_15->setItemText(2, QCoreApplication::translate("MainWindow", "R\303\251frig\303\251ration et Stockage des Vaccins", nullptr));

        label->setText(QCoreApplication::translate("MainWindow", "dateDebut", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "dateFin", nullptr));
        res->setText(QCoreApplication::translate("MainWindow", "resistance_eq_feu", nullptr));
        comboBox_16->setItemText(0, QCoreApplication::translate("MainWindow", "resistible", nullptr));
        comboBox_16->setItemText(1, QCoreApplication::translate("MainWindow", "pas resistible", nullptr));

        bg->setText(QString());
        groupBox_3->setTitle(QString());
        radioButton_11->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        radioButton_12->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EQUIPEMENT1_H
