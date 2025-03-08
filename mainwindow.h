#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPixmap>
#include <QIcon>
#include <QMainWindow>
#include <QTableWidgetItem>
#include "equipement.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public:
    static Equipement getEquipementById(const QString &id);
private:
    QString selectedImagePath;
private:
    QString selectedId; // Stocke l'ID de l'équipement sélectionné
    bool isModifying;
    void reinitialiserFormulaire();
private slots:
    void on_tableWidget_itemClicked(QTableWidgetItem *item); // Sélection de ligne
    void supp_clicked(); // Suppression
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
private slots:
    void actualiserTableau();
    void chargerEquipement();

private:
    void remplirTableWidget();


private slots:
    void on_pushButton_clicked();

private slots:
    void afficherEquipements();    // Fonction pour mettre à jour le tableau

private:
    Ui::MainWindow *ui;
    Equipement equip;

};

#endif // MAINWINDOW_H
