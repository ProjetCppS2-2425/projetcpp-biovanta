#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPixmap>
#include <QIcon>

#include <QMainWindow>


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
   // void on_pushButton_ajouter_clicked();
public slots:
    void on_radioButton_Ajouter_toggled(bool checked);


private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
