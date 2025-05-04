#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QStackedWidget>
#include "ui_menu.h"
// Forward declarations
class chercheur_1;
class equipement1;
class vaccin1;
class client1;

namespace Ui { class menu; }

class menu : public QMainWindow {
    Q_OBJECT
public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();
private slots:
    void on_btnRetourChercheur_clicked();  // Slot pour le bouton Chercheur
    void on_btnRetourEquipement_clicked();    // Slot pour le bouton Équipement
    void on_btnRetourvaccin_clicked();

private slots:
    void on_cherch_clicked();  // Bouton "Chercheur"
    void on_equip_clicked();    // Bouton "Équipement"
    void on_equip_2_clicked();

    void on_equip_3_clicked();

private:
    Ui::menu *ui;
    chercheur_1 *chercheurInterface;  // Pointeur vers l'interface Chercheur
    equipement1 *equipementInterface;    // Pointeur vers l'interface Équipement
    vaccin1 *vaccinInterface;
    client1 *client1interface;
    QStackedWidget *stackedWidget;    // Gestionnaire de pages
};

#endif // MENU_H
