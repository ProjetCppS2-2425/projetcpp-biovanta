#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // First: Attempt database connection
    Connexion c;
    bool test = c.openConnexion();

    if(test) {
        // Only create window AFTER successful connection
        MainWindow w;
        w.show();

        QMessageBox::information(nullptr, QObject::tr("Database Status"),
                                 QObject::tr("Connection successful!"),
                                 QMessageBox::Ok);

        // Load translations
        QTranslator translator;
        const QStringList uiLanguages = QLocale::system().uiLanguages();
        for (const QString &locale : uiLanguages) {
            const QString baseName = "Source_Projet2A_" + QLocale(locale).name();
            if (translator.load(":/i18n/" + baseName)) {
                a.installTranslator(&translator);
                break;
            }
        }

        return a.exec();  // Start event loop ONLY if connected
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Database Error"),
                              QObject::tr("Connection failed!\nCheck database settings."),
                              QMessageBox::Ok);
        return -1;  // Exit immediately on failure
    }
}
