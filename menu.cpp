#include "menu.h"
#include "ui_menu.h"
#include "chercheur_1.h"
#include "equipement1.h"
#include <QDebug>
#include <QPushButton>

menu::menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
    ui->bg_2->setPixmap(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\bg.jpg"));
    ui->logo->setPixmap(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\logo1.png"));
    ui->leqq->setPixmap(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\leq.png"));
    ui->tes->setPixmap(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\te.png"));
    ui->ee->setPixmap(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\ee.png"));
    ui->cc->setPixmap(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\cc.png"));
    ui->hh->setPixmap(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\hh.png"));
    ui->vv->setPixmap(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\vv.png"));
    // Initialisation du QStackedWidget
    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    // Ajout de la page menu (index 0)
    stackedWidget->addWidget(ui->pageMenu);

    // Création et ajout des interfaces
    chercheurInterface = new chercheur_1();
    equipementInterface = new equipement1();
    stackedWidget->addWidget(chercheurInterface);  // Index 1
    stackedWidget->addWidget(equipementInterface); // Index 2

    // Connexion manuelle des boutons de retour (solution robuste)
    QPushButton* btnRetourChercheur = chercheurInterface->findChild<QPushButton*>("btnRetourChercheur");
    QPushButton* btnRetourEquipement = equipementInterface->findChild<QPushButton*>("btnRetourEquipement");

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
}

menu::~menu()
{
    delete ui;
    delete chercheurInterface;
    delete equipementInterface;
}

void menu::on_cherch_clicked()
{
    qDebug() << "Affichage interface chercheur";
    stackedWidget->setCurrentIndex(1);  // Page chercheur (index 1)
}

void menu::on_equip_clicked()
{
    qDebug() << "Affichage interface equipement";
    stackedWidget->setCurrentIndex(2);  // Page equipement (index 2)
}

// Slots automatiques (doivent correspondre aux noms exacts des boutons)
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
