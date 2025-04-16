#include "ai_report_generator.h"
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QUrlQuery>

namespace {
const QString API_KEY = "AIzaSyCck223vu8EIZcuuoYy0N_xTa0poqda634";
const QString API_URL = "https://generativelanguage.googleapis.com/v1beta/models/gemini-2.0-flash:generateContent";
}

AIReportGenerator::AIReportGenerator(QObject *parent) : QObject(parent) {}

void AIReportGenerator::requestProjectReport(const QString& projectName)
{
    if (projectName.isEmpty()) {
        emit reportGenerated(projectName, "Error: Empty project name");
        return;
    }

    // Verify API key format
    if (!API_KEY.startsWith("AIza")) {
        emit reportGenerated(projectName, "Error: Invalid API key format");
        return;
    }

    // Construct URL with query parameters
    QUrl url(API_URL);
    QUrlQuery query;
    query.addQueryItem("key", API_KEY);
    url.setQuery(query);

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // Build payload with more detailed prompt
    QString prompt = QString(
                         "Génère un rapport technique détaillé en français d'environ 100 mots sur le projet de recherche '%1'. "
                         "Le rapport doit inclure les sections suivantes:\n"
                         "1. Objectifs: Décris les buts principaux du projet\n"
                         "2. Méthodologie: Explique brièvement les méthodes utilisées\n"
                         "3. Résultats attendus: Détaille les résultats anticipés\n"
                         "4. Importance: Explique l'importance scientifique du projet\n"
                         "Utilise un style formel et technique adapté à un rapport scientifique."
                         ).arg(projectName);

    QJsonObject payload;
    QJsonObject content;
    QJsonArray parts;
    QJsonArray contents;

    parts.append(QJsonObject{{"text", prompt}});
    content.insert("parts", parts);
    contents.append(content);
    payload.insert("contents", contents);

    // Debug output
    qDebug() << "API Request URL:" << url.toString();
    qDebug() << "Request Payload:" << QJsonDocument(payload).toJson();

    QNetworkReply* reply = m_networkManager.post(request, QJsonDocument(payload).toJson());

    connect(reply, &QNetworkReply::finished, [this, reply, projectName]() {
        if (reply->error() != QNetworkReply::NoError) {
            qDebug() << "API Error:" << reply->errorString();
            qDebug() << "Response:" << reply->readAll();
            emit reportGenerated(projectName, "API Error: " + reply->errorString());
        } else {
            QString report = parseGoogleResponse(reply);
            emit reportGenerated(projectName, report.isEmpty() ? "Error: Empty response" : report);
        }
        reply->deleteLater();
    });
}

QString AIReportGenerator::parseGoogleResponse(QNetworkReply* reply)
{
    QByteArray response = reply->readAll();
    qDebug() << "Raw API Response:" << response;

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(response, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        qWarning() << "JSON Parse Error:" << parseError.errorString();
        return "Error: Invalid API response";
    }

    if (!doc.isObject()) {
        qWarning() << "API Response is not an object";
        return "Error: Unexpected response format";
    }

    QJsonObject root = doc.object();

    if (root.contains("error")) {
        QString errorMsg = root["error"].toObject()["message"].toString();
        qWarning() << "API Error:" << errorMsg;
        return "API Error: " + errorMsg;
    }

    if (root.contains("candidates")) {
        QJsonArray candidates = root["candidates"].toArray();
        if (!candidates.isEmpty()) {
            QJsonObject content = candidates[0].toObject()["content"].toObject();
            QJsonArray parts = content["parts"].toArray();
            if (!parts.isEmpty()) {
                QString report = parts[0].toObject()["text"].toString();
                // Clean up the response if needed
                report = report.trimmed();
                return report;
            }
        }
    }

    return "Error: Could not parse response";
}
