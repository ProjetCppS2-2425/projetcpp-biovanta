#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QStackedWidget>

// Forward declarations (évite les inclusions circulaires)
class chercheur_1;
class equipement1;
class vaccin1;

namespace Ui { class menu; }

class menu : public QMainWindow {
    Q_OBJECT
public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();
private slots:
    void on_btnRetourChercheur_clicked();  // Slot pour le bouton Chercheur
    void on_btnRetourEquipement_clicked(); // Slot pour le bouton Équipement
private slots:
    void on_cherch_clicked();  // Bouton "Chercheur"
    void on_equip_clicked();    // Bouton "Équipement"
    void on_equip_2_clicked();

private:
    Ui::menu *ui;
    chercheur_1 *chercheurInterface;  // Pointeur vers l'interface Chercheur
    equipement1 *equipementInterface;    // Pointeur vers l'interface Équipement
    vaccin1 *vaccinInterface;
    QStackedWidget *stackedWidget;    // Gestionnaire de pages
};

#endif // MENU_H
