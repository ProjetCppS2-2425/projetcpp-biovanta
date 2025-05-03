#include "vaccin_ui.h"
#include "ui_vaccin_ui.h"
#include <QMessageBox>
#include <QShowEvent>
#include "vaccin.h"

vaccin_ui::vaccin_ui(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::vaccin_ui)
{
    ui->setupUi(this);

    ui->lineEdit_2->setPlaceholderText("ID Vaccin");
    ui->lineEdit_4->setPlaceholderText("Nom Vaccin");
    ui->lineEdit_5->setPlaceholderText("Température Conservation");

    ui->type_vaccin->setVisible(false);
    ui->nombre_doses->setVisible(false);

    vaccin vac;
    ui->tableView_vaccin->setModel(vac.afficher());
}

vaccin_ui::~vaccin_ui()
{
    delete ui;
}

void vaccin_ui::loadTableView()
{
    vaccin vac;
    ui->tableView_vaccin->setModel(vac.afficher());
}

void vaccin_ui::showEvent(QShowEvent *event)
{
    QDialog::showEvent(event);
    loadTableView();
}

QString vaccin_ui::checkType()
{
    if (ui->radioButton_3->isChecked()) return "add";
    if (ui->radioButton_4->isChecked()) return "edit";
    return "check edit or delete";
}

void vaccin_ui::clearInputs()
{
    ui->lineEdit_2->clear();
    ui->lineEdit_4->clear();
    ui->type_vaccin->clear();
    ui->nombre_doses->clear();
    ui->lineEdit_5->clear();
    ui->dateEdit->setDate(QDate::currentDate());
}

bool vaccin_ui::validateInputs()
{
    if (ui->lineEdit_2->text().isEmpty() ||
        ui->lineEdit_4->text().isEmpty() ||
        ui->type_vaccin->text().isEmpty() ||
        ui->nombre_doses->text().isEmpty() ||
        ui->lineEdit_5->text().isEmpty()) {
        QMessageBox::warning(this, "Validation Error", "Tous les champs doivent être remplis !");
        return false;
    }

    return true;
}

void vaccin_ui::on_pushButton_7_clicked()
{
    QString type = checkType();

    if (type == "add") {
        if (!validateInputs()) return;

        QString id = ui->lineEdit_2->text();
        QString nom = ui->lineEdit_4->text();
        QString type_vaccin = ui->type_vaccin->text();
        QString nbr_doses = ui->nombre_doses->text();
        float temperature_conservation = ui->lineEdit_5->text().toFloat();
        QDate date_exp = ui->dateEdit->date();

        vaccin vac(id, nom, type_vaccin, temperature_conservation, nbr_doses, date_exp);

        if (vac.Ajouter()) {
            ui->tableView_vaccin->setModel(vac.afficher());
            QMessageBox::information(this, "Success!", "Vaccin ajouté avec succès.");
            clearInputs();
        } else {
            QMessageBox::critical(this, "Error!", "Problème d'ajout.");
        }
    }
    else if (type == "edit") {
        if (!validateInputs()) return;

        QString id = ui->lineEdit_2->text();
        QString nom = ui->lineEdit_4->text();
        QString type_vaccin = ui->type_vaccin->text();
        QString nbr_doses = ui->nombre_doses->text();
        float temperature_conservation = ui->lineEdit_5->text().toFloat();
        QDate date_exp = ui->dateEdit->date();

        vaccin vac(id, nom, type_vaccin, temperature_conservation, nbr_doses, date_exp);

        if (vac.modifier()) {
            ui->tableView_vaccin->setModel(vac.afficher());
            QMessageBox::information(this, "Success!", "Vaccin modifié avec succès.");
            clearInputs();
        } else {
            QMessageBox::critical(this, "Error!", "Problème de modification.");
        }
    }
    else {
        QMessageBox::warning(this, "Warning", "Veuillez choisir une option valide (ajout/modification).");
    }
}

void vaccin_ui::on_comboBox_10_currentTextChanged(const QString &arg1)
{
    ui->type_vaccin->setText(arg1);
}

void vaccin_ui::on_comboBox_11_currentTextChanged(const QString &arg1)
{
    ui->nombre_doses->setText(arg1);
}

void vaccin_ui::on_tableView_vaccin_doubleClicked(const QModelIndex &index)
{
    QString selectedId = ui->tableView_vaccin->model()->data(index.sibling(index.row(), 0)).toString();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation",
                                  "Êtes-vous sûr de vouloir supprimer ce vaccin?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        vaccin vac;
        if (vac.Supprime(selectedId)) {
            QMessageBox::information(this, "Success", "Le vaccin a été supprimé avec succès.");
            ui->tableView_vaccin->setModel(vac.afficher());
            clearInputs();
        } else {
            QMessageBox::critical(this, "Error", "Échec de la suppression du vaccin.");
        }
    }
}

void vaccin_ui::on_tableView_vaccin_clicked(const QModelIndex &index)
{
    int row = index.row();

    QString id = ui->tableView_vaccin->model()->data(ui->tableView_vaccin->model()->index(row, 0)).toString();
    QString nom = ui->tableView_vaccin->model()->data(ui->tableView_vaccin->model()->index(row, 1)).toString();
    QString type = ui->tableView_vaccin->model()->data(ui->tableView_vaccin->model()->index(row, 2)).toString();
    QString nbr_doses = ui->tableView_vaccin->model()->data(ui->tableView_vaccin->model()->index(row, 3)).toString();
    QString temperature_conservation = ui->tableView_vaccin->model()->data(ui->tableView_vaccin->model()->index(row, 4)).toString();
    QString date_expiration = ui->tableView_vaccin->model()->data(ui->tableView_vaccin->model()->index(row, 5)).toString();

    ui->lineEdit_2->setText(id);
    ui->lineEdit_4->setText(nom);
    ui->type_vaccin->setText(type);
    ui->nombre_doses->setText(nbr_doses);
    ui->lineEdit_5->setText(temperature_conservation);
    ui->dateEdit->setDate(QDate::fromString(date_expiration, "yyyy-MM-dd"));
}

void vaccin_ui::on_pushButton_9_clicked()
{
    clearInputs();
}

