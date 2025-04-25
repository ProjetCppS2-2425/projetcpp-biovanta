#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPixmap>
#include <QIcon>
#include <QMainWindow>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QStackedWidget>
#include "employe.h"
#include "arduino.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_valider_clicked();

    void on_supprimer_clicked();

    void on_modifier_clicked();

    void on_modification_clicked();

    void on_annuler_clicked();

    void afficherStatistiquesEmployes();

    void on_pdfEmployes_clicked();

    void onTriComboBoxChanged(int index);

    void onSearchTextChanged(const QString &text);

    void on_quitButton_clicked();
    void switchToPage2();

    void on_pb_mdp_oub_clicked();
    void on_pb_confirm_email_oub_clicked();
    void on_pb_reset_password_oub_clicked();
    void on_pb_valider_mdp_oub_clicked();

private:
    Ui::MainWindow *ui;
    QStackedWidget *stackedWidget;
private:
     void setupForgotPasswordPage();
    void verifyLoginAndSwitchPage();
    void verifyEmailAndSendOTP();
    void verifyOTPAndSwitchPage();
    QMap<QString, QString> otpStorage;
    bool verifyEmailAndSendOTP(const QString& email);
    void refreshEmployeeTable();
    QString currentSortColumn;
    QString currentSortOrder;
    void updateSearchQuery();
    void showEmployePage();
    void populateTable(QSqlQuery &query);
    QMap<QString, int> mdpOubTentativesMap;
    QMap<QString, QDateTime> mdpOubBlocageMap;
    QString storedOTP;
    QString currentEmailForOTP;
    QString generateRandomCode(int length = 6);
    bool sendEmail(QString recipient, QString subject, QString body);
    QString storedVerificationCode_oub;
    QString currentEmailForReset_oub;
    const int MAX_TENTATIVES = 3;
    const int BLOCK_DURATION_SECONDS = 60;


    QByteArray data;
    Arduino A;




};
#endif // MAINWINDOW_H
