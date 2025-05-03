#ifndef VACCIN1_H
#define VACCIN1_H
#include <QPixmap>
#include <QIcon>
#include <QSerialPort>

#include <QMainWindow>
#include "vaccin.h"
#include "statistique.h"
#include "arduinomanager.h"
QT_BEGIN_NAMESPACE

namespace Ui {
class vaccin1;
}
QT_END_NAMESPACE

class vaccin1: public QMainWindow
{
    Q_OBJECT

public:
    vaccin1(QWidget *parent = nullptr);
    ~vaccin1();

    QString checkType();

    void clearInputs();

    bool validateInputs();

    void loadTableView();

private slots:
    void on_pushButton_7_clicked();

    void on_comboBox_10_currentTextChanged(const QString &arg1);

    void on_comboBox_11_currentTextChanged(const QString &arg1);

    void on_tableView_vaccin_doubleClicked(const QModelIndex &index);

    void on_tableView_vaccin_clicked(const QModelIndex &index);

    void on_pushButton_9_clicked();

    void on_comboBox_7_activated(int index);


    void on_checkBox_stateChanged(int arg1);

    void on_checkBox_2_stateChanged(int arg1);

    void on_ok_2_clicked();

    void on_pushButton_6_clicked();

    void on_stat_2_clicked();

    void on_pdf_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void verifierTempEtMettreAJour();
    void lireDonneesArduino() ;

private:
    Ui::vaccin1 *ui;
    vaccin vac;
    bool ASC = false;
    bool DSC = false;
    ArduinoManager *arduino;
    QSerialPort *serial;

protected:
    void showEvent(QShowEvent *event) override;

};
#endif // VACCIN1_H
