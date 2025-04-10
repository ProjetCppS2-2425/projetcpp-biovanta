#include "mainwindow.h"
#include "connection.h"

#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow M;
    connection c;
    if (c.createconnect()) {
        QMessageBox::information(nullptr, "Connection Success", "Database connected successfully!", QMessageBox::Ok);
        M.show();
    } else {
        QMessageBox::critical(nullptr, "Connection Failed", "Failed to connect to the database.", QMessageBox::Cancel);
        return 1;
    }
    return a.exec();
}
