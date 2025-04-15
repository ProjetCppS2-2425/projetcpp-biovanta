#ifndef TODO_H
#define TODO_H
#include <QFile>
#include <QStandardPaths>
#include <QDialog>

namespace Ui {
class Todo;
}

class Todo : public QDialog
{
    Q_OBJECT

public:
    explicit Todo(QWidget *parent = nullptr);
    ~Todo();

private slots:


    void on_btnAdd_clicked();



    void on_Supp_clicked();

private:
    Ui::Todo *ui;
    QString path ;
};

#endif // TODO_H
