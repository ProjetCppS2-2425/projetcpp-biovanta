#ifndef STATISTIQUE_H
#define STATISTIQUE_H

#include <QDialog>
#include <QVector>
#include <QPointF>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include "vaccin.h"



namespace Ui {
class statistique;
}

class statistique : public QDialog
{
    Q_OBJECT

protected:
    void paintEvent(QPaintEvent *);

public:
    explicit statistique(QWidget *parent = nullptr);
    ~statistique();

private slots:
    void on_pushButton_11_clicked();

private:
    Ui::statistique *ui;
    QVector<QPointF> dataPoints;
    QChartView *chartView;
    QLineSeries *series;
    vaccin v;
};

#endif // STATISTIQUE_H
