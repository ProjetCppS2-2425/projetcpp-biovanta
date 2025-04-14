#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPixmap>
#include <QIcon>
#include <QMainWindow>
#include <QLabel>  // Ajoutez cette ligne
#include <QTimer>
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
    static Equipement getEquipementById(const QString &id);

private:
    QByteArray selectedImageData;
    QString selectedId;
    bool isModifying;
    Equipement equip;
    Ui::MainWindow *ui;
    void reinitialiserFormulaire();
    void remplirTableWidget();
    void refreshAlertCount();



private:
    bool wasInAlertState = false;
    QLabel *notificationBadge;
    QTimer *notificationTimer;
    void updateNotificationBadge(int count);



private slots:
    void on_tableWidget_itemClicked(QTableWidgetItem *item);
    void supp_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pdf_clicked();
    void on_stat_clicked();
    void on_ok_clicked();
    void on_pushButton_4_clicked();
    void onTriDeclenche();
    void checkEquipmentStatus();
    void showEquipmentAlerts();
    void actualiserTableau();
    void chargerEquipement();
    void afficherEquipements(const QList<Equipement>& liste);

};

#endif // MAINWINDOW_H
