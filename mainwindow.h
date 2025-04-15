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
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QCalendarWidget>  // Pour le widget calendrier
#include <QDate>            // Pour la manipulation des dates
#include <QDateEdit>        // Pour les champs de saisie de date
#include <QTextCharFormat>  // Pour le formatage des dates dans le calendrier
#include <QMainWindow>
#include <QPushButton>
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
    QWidget *statsPage;  // Nouvelle page pour les statistiques
private:
    // ... autres membres existants ...
    QChartView *etatView;
    QChartView *dispoView;
    QChartView *typeView;
    QCalendarWidget *calendarWidget;  // Déclaration du calendrier
    QPushButton *backButtonCalendar;

private slots:
    void on_tableWidget_3_itemClicked(QTableWidgetItem *item);
    void supp_3_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
    void on_pdf_3_clicked();
    void on_stat_3_clicked();
    void on_ok_3_clicked();
    void on_pushButton_10_clicked();
    void onTriDeclenche();
    void checkEquipmentStatus();
    void showEquipmentAlerts();
    void actualiserTableau();
    void chargerEquipement();
    void afficherEquipements(const QList<Equipement>& liste);
    void afficherDisponibiliteSurCalendrier();
    void afficherDetailsEquipement(const QDate &date);

};

#endif // MAINWINDOW_H
