#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize with your exact variable names
    widget_2 = new chercheur_1(this);
    page_liste = new equipement1(this);

    // Add to stacked widget
    ui->stackedWidget->addWidget(widget_2);
    ui->stackedWidget->addWidget(page_liste);

    // Connect buttons using your preferred naming


    // Start with chercheur page
    ui->stackedWidget->setCurrentWidget(widget_2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ChercheurButton_clicked()
{
    qDebug() << "Showing chercheur page (widget_2)";
    ui->stackedWidget->setCurrentWidget(widget_2);
}

void MainWindow::on_EquipementButton_clicked()
{
    qDebug() << "Showing equipement page (page_liste)";
    ui->stackedWidget->setCurrentWidget(page_liste);
}
