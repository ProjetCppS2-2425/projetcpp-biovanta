#ifndef STATISTIQUE_H
#define STATISTIQUE_H

#include <QObject>
#include <QVector>
#include <QPointF>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include "vaccin.h"



    class statistique
{
public:
    statistique();  // constructeur
    ~statistique();

    QChartView* genererStatistiques(); // méthode pour générer le graphique

private:
    vaccin v;
};

#endif // STATISTIQUE_H
