#include "equipement1.h"
#include <QApplication>
#include "connection.h"
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Création et initialisation de la connexion à la base de données
    connection c;
    bool test = c.createconnect();

    if (!test) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur de connexion"),
                              QObject::tr("Échec de la connexion à la base de données.\n"
                                          "Veuillez vérifier vos paramètres de connexion."),
                              QMessageBox::Cancel);
        return -1; // Quitter l'application si la connexion échoue
    }

    // Affichage de la fenêtre principale
    MainWindow w;
    w.show();

    return a.exec();
}
