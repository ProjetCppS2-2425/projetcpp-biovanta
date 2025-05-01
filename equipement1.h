#ifndef EQUIPEMENT1_H
#define EQUIPEMENT1_H

#include <QPixmap>
#include <QIcon>
#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QMainWindow>
#include <QTableWidgetItem>
#include <QByteArray>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QCalendarWidget>
#include <QDate>
#include <QDateEdit>
#include <QTextCharFormat>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include "arduinoE.h"
#include <QMessageBox>
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
    // In mainwindow.h, add to private members:
private slots:
    void initArduinoConnection();
    void readSerialData();
private:
    arduino arduino;
private:
    QByteArray selectedImageData;
    QString selectedId;
    bool isModifying;
    Equipement equip;
    Ui::MainWindow *ui;
    void reinitialiserFormulaire();
    void remplirTableWidget();
    void refreshAlertCount();
    void handleFireDetection();

private:
    class NotificationPopup : public QWidget {
    public:
        NotificationPopup(QWidget* parent = nullptr) : QWidget(parent) {
            setWindowFlags(Qt::Popup | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
            setAttribute(Qt::WA_TranslucentBackground);
            setStyleSheet("background: transparent;");

            QVBoxLayout* layout = new QVBoxLayout(this);
            layout->setContentsMargins(5, 5, 5, 5);

            contentWidget = new QWidget(this);
            contentWidget->setStyleSheet(
                "background-color: white;"
                "border: 1px solid #ddd;"
                "border-radius: 4px;"
                "padding: 10px;"
                );

            layout->addWidget(contentWidget);
        }

        void setContent(QWidget* widget) {
            QLayout* layout = contentWidget->layout();
            if (layout) QWidget().setLayout(layout); // Clear existing layout

            QVBoxLayout* newLayout = new QVBoxLayout(contentWidget);
            newLayout->addWidget(widget);
        }

    private:
        QWidget* contentWidget;
    };

    NotificationPopup* notificationPopup = nullptr;
private slots:
    void showAlertNotification();
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
protected:
    bool eventFilter(QObject *watched, QEvent *event) override;
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

#endif // EQUIPEMENT1_H
