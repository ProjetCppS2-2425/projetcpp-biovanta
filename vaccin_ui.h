#ifndef VACCIN_UI_H
#define VACCIN_UI_H

#include <QDialog>
#include "vaccin.h"

namespace Ui {
class vaccin_ui;
}

class vaccin_ui : public QDialog
{
    Q_OBJECT

public:
    explicit vaccin_ui(QWidget *parent = nullptr);
    ~vaccin_ui();

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

private:
    Ui::vaccin_ui *ui;
    vaccin vac;

protected:
    void showEvent(QShowEvent *event) override;
};

#endif // VACCIN_UI_H
