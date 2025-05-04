#include "menu.h"
#include "ui_menu.h"
#include "chercheur_1.h"
#include "equipement1.h"
#include "vaccin1.h"
#include "client1.h"
#include "ui_client1.h"

#include <QDebug>
#include <QPushButton>
#include <QPixmap>
#include <QStackedWidget>

menu::menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);

    // Set background and icons
    ui->bg_2->setPixmap(QPixmap("C:\\Users\\user\\Desktop\\projetarwa\\bg.jpg"));
    ui->logo->setPixmap(QPixmap("C:\\Users\\user\\Desktop\\projetarwa\\logo1.png"));
    ui->leqq->setPixmap(QPixmap("C:\\Users\\user\\Desktop\\projetarwa\\leq.png"));
    ui->tes->setPixmap(QPixmap("C:\\Users\\user\\Desktop\\projetarwa\\te.png"));
    ui->ee->setPixmap(QPixmap("C:\\Users\\user\\Desktop\\projetarwa\\ee.png"));
    ui->cc->setPixmap(QPixmap("C:\\Users\\user\\Desktop\\projetarwa\\cc.png"));
    ui->hh->setPixmap(QPixmap("C:\\Users\\user\\Desktop\\projetarwa\\hh.png"));
    ui->vv->setPixmap(QPixmap("C:\\Users\\user\\Desktop\\projetarwa\\vv.png"));

    // Initialize QStackedWidget
    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    // Add the main menu page
    stackedWidget->addWidget(ui->pageMenu); // Index 0

    // Create and add the other interfaces
    chercheurInterface = new chercheur_1();
    equipementInterface = new equipement1();
    vaccinInterface = new vaccin1();
    client1interface = new client1(); // New

    stackedWidget->addWidget(chercheurInterface);   // Index 1
    stackedWidget->addWidget(equipementInterface);  // Index 2
    stackedWidget->addWidget(vaccinInterface);      // Index 3
    stackedWidget->addWidget(client1interface);     // Index 4

    // Connect return buttons (manual)
    QPushButton* btnRetourChercheur = chercheurInterface->findChild<QPushButton*>("btnRetourChercheur");
    QPushButton* btnRetourEquipement = equipementInterface->findChild<QPushButton*>("btnRetourEquipement");
    QPushButton* btnRetourvaccin = vaccinInterface->findChild<QPushButton*>("btnRetourvaccin");
    QPushButton* btnRetourclient = client1interface->findChild<QPushButton*>("retour");

    if (btnRetourChercheur) {
        connect(btnRetourChercheur, &QPushButton::clicked, this, [this]() {
            qDebug() << "Retour chercheur cliqué";
            stackedWidget->setCurrentIndex(0);
        });
    } else {
        qDebug() << "Erreur: Bouton retour chercheur non trouvé!";
    }

    if (btnRetourEquipement) {
        connect(btnRetourEquipement, &QPushButton::clicked, this, [this]() {
            qDebug() << "Retour equipement cliqué";
            stackedWidget->setCurrentIndex(0);
        });
    } else {
        qDebug() << "Erreur: Bouton retour equipement non trouvé!";
    }

    if (btnRetourvaccin) {
        connect(btnRetourvaccin, &QPushButton::clicked, this, [this]() {
            qDebug() << "Retour vaccin cliqué";
            stackedWidget->setCurrentIndex(0);
        });
    } else {
        qDebug() << "Erreur: Bouton retour vaccin non trouvé!";
    }
    if (btnRetourclient) {
        connect(btnRetourclient, &QPushButton::clicked, this, [this]() {
            qDebug() << "Retour client cliqué";
            stackedWidget->setCurrentIndex(0);
        });
    } else {
        qDebug() << "Erreur: Bouton retour vaccin non trouvé!";
    }
}

menu::~menu()
{
    delete ui;
    delete chercheurInterface;
    delete equipementInterface;
    delete vaccinInterface;
   delete client1interface; // Added cleanup
}

// Slots for navigation buttons
void menu::on_cherch_clicked()
{
    qDebug() << "Affichage interface chercheur";
    stackedWidget->setCurrentIndex(1);  // Page chercheur
}

void menu::on_equip_clicked()
{
    qDebug() << "Affichage interface equipement";
    stackedWidget->setCurrentIndex(2);  // Page équipement
}

void menu::on_equip_2_clicked()
{
    qDebug() << "Affichage interface vaccin1";
    stackedWidget->setCurrentIndex(3);  // Page vaccin
}

void menu::on_equip_3_clicked()
{
    qDebug() << "Affichage interface client1";
    stackedWidget->setCurrentIndex(4);  // Page client1 (new)
}

// Slots for return buttons (optional, auto-connected)
void menu::on_btnRetourChercheur_clicked()
{
    qDebug() << "Retour via slot automatique (chercheur)";
    stackedWidget->setCurrentIndex(0);
}

void menu::on_btnRetourEquipement_clicked()
{
    qDebug() << "Retour via slot automatique (equipement)";
    stackedWidget->setCurrentIndex(0);
}

void menu::on_btnRetourvaccin_clicked()
{
    qDebug() << "Retour via slot automatique (vaccin)";
    stackedWidget->setCurrentIndex(0);
}
/*void menu::on_btnRetourclient_clicked()
{
    qDebug() << "Retour via slot automatique (client)";
    stackedWidget->setCurrentIndex(0);
}*/
