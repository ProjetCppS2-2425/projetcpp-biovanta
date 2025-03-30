#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPixmap>
#include <QIcon>
#include <QMainWindow>
#include <QTableWidgetItem>
#include <QByteArray>  // Ajout pour la gestion des données binaires
#include "equipement.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Méthode statique pour récupérer un équipement par son ID
    static Equipement getEquipementById(const QString &id);

private:
    // Variables membres
    QByteArray selectedImageData;  // Remplace QString selectedImagePath pour stocker les données binaires de l'image
    QString selectedId;            // Stocke l'ID de l'équipement sélectionné
    bool isModifying;              // Indicateur de mode modification
    Equipement equip;              // Instance de la classe Equipement
    Ui::MainWindow *ui;            // Interface utilisateur

    // Méthodes privées
    void reinitialiserFormulaire(); // Réinitialise le formulaire
    void remplirTableWidget();     // Remplit le tableau avec les données

private slots:
    // Gestion des interactions
    void on_tableWidget_itemClicked(QTableWidgetItem *item); // Gère le clic sur une ligne du tableau
    void supp_clicked();            // Gère la suppression d'un équipement
    void on_pushButton_clicked();   // Gère la sélection d'image
    void on_pushButton_2_clicked(); // Gère l'ajout/modification
    void on_pushButton_3_clicked(); // Gère la réinitialisation
    void on_pdf_clicked();

    // Gestion des données
    void actualiserTableau();       // Met à jour l'affichage du tableau
    void chargerEquipement();       // Charge les données d'un équipement
    void afficherEquipements();     // Affiche la liste des équipements
};

#endif // MAINWINDOW_H
