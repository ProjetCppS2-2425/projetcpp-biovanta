#ifndef GEMINIAPI_H
#define GEMINIAPI_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>



class GeminiAPI : public QObject
{
    Q_OBJECT
public:
    explicit GeminiAPI(QObject *parent = nullptr);
    void askGemini(const QString &userInput);

signals:
    void responseReady(const QString &reply);

private slots:
    void handleNetworkReply(QNetworkReply *reply);

private:
    QNetworkAccessManager *networkManager;
    const QString apiKey = "AIzaSyCXc-EaUyQHBX_1p4MoQjxclj4nOHcnk3k"; // Remplace par ta clé réelle
};

#endif // GEMINIAPI_H
