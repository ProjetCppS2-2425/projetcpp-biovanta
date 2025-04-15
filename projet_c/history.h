#ifndef HISTORY_H
#define HISTORY_H

#include <QDialog>

namespace Ui {
class History;
}

class History : public QDialog
{
    Q_OBJECT

public:
    explicit History(QWidget *parent = nullptr);
    ~History();
    QString path;

private:
    Ui::History *ui;
public slots:
    void on_ajouter_performed();
};

#endif // HISTORY_H
