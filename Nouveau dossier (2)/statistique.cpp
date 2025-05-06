#include "statistique.h"

statistique::statistique()
{
    // constructeur vide
}

statistique::~statistique()
{
    // destructeur vide
}

QChartView* statistique::genererStatistiques()
{
    int A = v.statistique1(); // unidose
    int B = v.statistique2(); // multidose
    int total = A + B;

    QPieSeries *series = new QPieSeries();

    if (total > 0) {
        QPieSlice* sliceA = series->append("Unidose", A);
        QPieSlice* sliceB = series->append("Multidose", B);

        // Calculs pourcentages
        float pourcentageA = (float)A / total * 100;
        float pourcentageB = (float)B / total * 100;

        // Affichage formaté avec pourcentages
        sliceA->setLabel(QString("Unidose: %1%").arg(QString::number(pourcentageA, 'f', 1)));
        sliceB->setLabel(QString("Multidose: %1%").arg(QString::number(pourcentageB, 'f', 1)));

        // Rendre les labels visibles
        sliceA->setLabelVisible(true);
        sliceB->setLabelVisible(true);
    } else {
        QPieSlice* sliceEmpty = series->append("Aucune donnée", 1);
        sliceEmpty->setLabelVisible(true);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des types de doses de vaccin");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(850, 600);

    return chartView;
}

