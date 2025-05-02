#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QPushButton>
#include "chercheur_1.h"
#include "equipement1.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    // Your exact requested widget names
    chercheur_1 *widget_2;
    equipement1 *page_liste;

private slots:
    void on_ChercheurButton_clicked();
    void on_EquipementButton_clicked();
};

#endif // MAINWINDOW_H
