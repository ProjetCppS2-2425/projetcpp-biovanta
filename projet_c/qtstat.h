#ifndef QTSTAT_H
#define QTSTAT_H

#include <QDialog>

namespace Ui {
class Qtstat;
}

class Qtstat : public QDialog
{
    Q_OBJECT

public:
    explicit Qtstat(QWidget *parent = nullptr);
    ~Qtstat();

private:
    Ui::Qtstat *ui;
};

#endif // QTSTAT_H
