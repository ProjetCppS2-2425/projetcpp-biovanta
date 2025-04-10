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


private:
    Ui::vaccin_ui *ui;
    vaccin vac;

protected:
    void showEvent(QShowEvent *event) override;
};

#endif // VACCIN_UI_H
