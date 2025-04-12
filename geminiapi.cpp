#include "geminiapi.h"
#include <QNetworkRequest>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

GeminiAPI::GeminiAPI(QObject *parent)
    : QObject(parent),
      networkManager(new QNetworkAccessManager(this))
{
    connect(networkManager, &QNetworkAccessManager::finished,
            this, &GeminiAPI::handleNetworkReply);
}

void GeminiAPI::askGemini(const QString &userInput)
{
    QUrl url("https://generativelanguage.googleapis.com/v1beta/models/gemini-2.0-flash:generateContent?key=" + apiKey);
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // Construction de la requête JSON
    QJsonObject textPart;
    textPart["text"] = userInput;  // Assurez-vous que le texte est dans un objet "text"

    QJsonObject jsonMessage;
    jsonMessage["role"] = "user";
    jsonMessage["parts"] = QJsonArray{ textPart };  // Ajouter le texte sous forme d'objet dans "parts"

    QJsonObject jsonPayload;
    jsonPayload["contents"] = QJsonArray{ jsonMessage };  // Structure conforme à l'API

    QJsonDocument doc(jsonPayload);
    QByteArray data = doc.toJson();

    // Débogage : Afficher la requête JSON envoyée
    qDebug() << "Request JSON data:" << data;

    networkManager->post(request, data);
}


void GeminiAPI::handleNetworkReply(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray response = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(response);

        QString botReply;

        if (doc.isObject()) {
            QJsonObject obj = doc.object();
            auto contents = obj["candidates"].toArray();
            if (!contents.isEmpty()) {
                auto parts = contents[0].toObject()["content"].toObject()["parts"].toArray();
                if (!parts.isEmpty()) {
                    botReply = parts[0].toObject()["text"].toString();
                }
            }
        }

        emit responseReady(botReply);

    } else {
        emit responseReady("Erreur réseau : " + reply->errorString());
    }

    reply->deleteLater();
}
