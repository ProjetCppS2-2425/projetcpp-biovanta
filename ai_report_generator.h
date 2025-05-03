#ifndef AI_REPORT_GENERATOR_H
#define AI_REPORT_GENERATOR_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QString>

class AIReportGenerator : public QObject
{
    Q_OBJECT
public:
    explicit AIReportGenerator(QObject *parent = nullptr);
    void requestProjectReport(const QString& projectName);
    void errorOccurred(const QString &errorMessage);

signals:
    void reportGenerated(const QString& projectName, const QString& report);

private:
    QNetworkAccessManager m_networkManager;
    QString parseGoogleResponse(QNetworkReply* reply);
    // In ai_report_generator.h
signals:

    void reportError(const QString& errorMessage);
};

#endif // AI_REPORT_GENERATOR_H
