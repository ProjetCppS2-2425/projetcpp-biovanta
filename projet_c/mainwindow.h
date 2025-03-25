#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPixmap>
#include <QIcon>

#include <QMainWindow>
#include "Client.h"

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
public slots:
    void on_radioButton_Ajouter_toggled(bool checked);
    void on_pushButton_supp_clicked();
    void on_radioButton_Modifier_toggled(bool checked);
    void onPdfButtonClicked();
private:
    Ui::MainWindow *ui;
    Client C;

};
#endif // MAINWINDOW_H
