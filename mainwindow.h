#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPixmap>
#include <QIcon>
#include <QMainWindow>
#include "equipement.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QString selectedImagePath;

private slots:
    void actualiserTableau();
private:
    void remplirTableWidget();


private slots:
    void on_pushButton_clicked();

private slots:
    void on_pushButton_2_clicked();
    void afficherEquipements(); // Fonction pour mettre à jour le tableau

private:
    Ui::MainWindow *ui;
    Equipement equip;

};

#endif // MAINWINDOW_H
