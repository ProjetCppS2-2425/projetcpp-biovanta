#include "testbio.h"  // or "mainwindow.h" depending on your actual header
#include <QApplication>
#include "connection.h"
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Database connection
    connection c;
    if (!c.createconnect()) {
        QMessageBox::critical(nullptr, "Connection Error",
                              "Failed to connect to database.\n"
                              "Please check your connection settings.",
                              QMessageBox::Cancel);
        return -1;
    }

    // Create main window with alternative name
    TestBio mainWindow;  // Changed from 'w' to 'mainWindow'
    mainWindow.show();

    return a.exec();
}
