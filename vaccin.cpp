#include "vaccin.h"
#include "connection.h"
#include<QSqlError>
#include <QDebug>
#include <QUrl>
#include <QUrlQuery>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QCoreApplication>
#include <QMessageBox>

vaccin::vaccin() {
    id_vaccin = "";
    nom_vaccin = "";
    type_vaccin = "";
    nombres_doses = "";
    temperature_conservation = 0.0;
    date_expiration = QDate();
}

vaccin::vaccin(QString id, QString nom, QString type, float temperature, QString doses, QDate expiration) {
    id_vaccin = id;
    nom_vaccin = nom;
    type_vaccin = type;
    temperature_conservation = temperature;
    nombres_doses = doses;
    date_expiration = expiration;
}

bool vaccin::Ajouter()
{

    QSqlQuery query;
    QString temperature_conservation_string=QString::number(temperature_conservation);

    query.prepare("INSERT INTO VACCIN (id_vaccin,nom_vaccin,type_vaccin,temperature_conservation,nombres_doses,date_expiration) "
                  "VALUES (:id_vaccin,:nom_vaccin,:type_vaccin,:temperature_conservation,:nombres_doses,:date_expiration)");
    query.bindValue(":id_vaccin",id_vaccin);
    query.bindValue(":nom_vaccin",nom_vaccin);
    query.bindValue(":type_vaccin",type_vaccin);
    query.bindValue(":temperature_conservation",temperature_conservation_string);
    query.bindValue(":nombres_doses",nombres_doses);
    query.bindValue(":date_expiration",date_expiration);

    return query.exec();

}

QSqlQueryModel* vaccin::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM VACCIN");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Vaccin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Vaccin"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type Vaccin"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Température de Conservation"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nombres de Doses"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date d'Expiration"));

    return model;
}

bool vaccin::Supprime(QString id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM VACCIN WHERE id_vaccin = :id_vaccin");
    query.bindValue(":id_vaccin", id);

    return query.exec();
}

bool vaccin::modifier()
{
    QSqlQuery query;
    QString temperature_conservation_string = QString::number(temperature_conservation);

    query.prepare("UPDATE VACCIN SET nom_vaccin = :nom_vaccin, type_vaccin = :type_vaccin, "
                  "temperature_conservation = :temperature_conservation, nombres_doses = :nombres_doses, "
                  "date_expiration = :date_expiration WHERE id_vaccin = :id_vaccin");

    query.bindValue(":id_vaccin", id_vaccin);
    query.bindValue(":nom_vaccin", nom_vaccin);
    query.bindValue(":type_vaccin", type_vaccin);
    query.bindValue(":temperature_conservation", temperature_conservation_string);
    query.bindValue(":nombres_doses", nombres_doses);
    query.bindValue(":date_expiration", date_expiration);

    return query.exec();
}

QSqlQueryModel *vaccin:: afficher_choix_ASC(QString choix)
{
    QSqlQueryModel * model =new QSqlQueryModel();

    if(choix=="nom_vaccin")
    {
        model->setQuery("SELECT * FROM VACCIN  ORDER BY nom_vaccin ASC ;");
    }else if(choix=="temperature_conservation")
    {
        model->setQuery("SELECT * FROM VACCIN  ORDER BY temperature_conservation ASC;");
    }else if(choix=="date_expiration")
    {
        model->setQuery("SELECT * FROM VACCIN  ORDER BY date_expiration ASC;");
    }else if (choix=="choisir")
    {
        model->setQuery("SELECT * FROM VACCIN ");
    }
    return model;
}

QSqlQueryModel *vaccin:: afficher_choix_DSC(QString choix)
{
    QSqlQueryModel * model =new QSqlQueryModel();

    if(choix=="nom_vaccin")
    {
        model->setQuery("SELECT * FROM VACCIN  ORDER BY nom_vaccin DESC;");
    }else if(choix=="temperature_conservation")
    {
        model->setQuery("SELECT * FROM VACCIN  ORDER BY temperature_conservation DESC;");
    }else if(choix=="date_expiration")
    {
        model->setQuery("SELECT * FROM VACCIN ORDER BY date_expiration DESC;");
    }else if (choix=="choisir")
    {
        model->setQuery("SELECT * FROM VACCIN ");
    }
    return model;
}

QSqlQueryModel *vaccin::afficher_type_vaccin(QString ch)
{
    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("SELECT * FROM VACCIN where type_vaccin= '"+ch+"' ");
    return model ;
}
QSqlQueryModel *vaccin::afficher_nom_vaccin(QString ch)
{
    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("SELECT * FROM VACCIN where nom_vaccin= '"+ch+"' ");
    return model ;
}
QSqlQueryModel *vaccin:: afficher_temperature_conservation(QString ch)
{
    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("SELECT * FROM VACCIN where temperature_conservation= '"+ch+"' ");

    return model ;

}

QSqlQueryModel *vaccin:: afficher_id_vaccin(QString ch)
{
    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("SELECT * FROM VACCIN where id_vaccin= '"+ch+"' ");

    return model ;

}



//Statistiques
int vaccin::statistique1(){
    connection c;
    c.createconnect();
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from VACCIN where NOMBRES_DOSES = 'unidose' ") ;
    while(requete.next())
    {
        count++ ;
    }
    qDebug() << "Nombre de vaccins unidose:" << count;
    return count ;
}

int vaccin::statistique2(){
    connection c;
    c.createconnect();
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from VACCIN where nombres_doses like 'multidose' ") ;
    while(requete.next())
    {
        count++ ;
    }

    return count ;
}

vaccin* vaccin::readvaccin(QString val)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM VACCIN WHERE id_vaccin = :val"); //correct column name
    query.bindValue(":val", val); // correctly using the bind variable

    if (query.exec()) {
        if (query.next()) { //  Only one expected row
            setIdVaccin(query.value(0).toString());
            setNomVaccin(query.value(1).toString());
            setTypeVaccin(query.value(2).toString());
            setTemperatureConservation(query.value(3).toFloat());
            setNombresDoses(query.value(4).toString());
            setDateExpiration(query.value(5).toDate());
        } else {
            // No result: return nullptr
            return nullptr;
        }
    } else {
        qWarning() << "Query failed:" << query.lastError().text();
        return nullptr;
    }

    return this;
}


void vaccin::sendSMS(const QString& phoneNumber, const QString& message ) {
    // Twilio Account SID, Auth Token, and Twilio phone number
    QString accountSid = "AC7508f4d0886aedb6ee88594fc15210b2";
    QString authToken = "5c7ef8ea1965482ce72573dc27eb03f1";
    QString twilioPhoneNumber = "+19472175897";

    // Twilio API endpoint
    QUrl apiUrl("https://api.twilio.com/2010-04-01/Accounts/AC7508f4d0886aedb6ee88594fc15210b2/Messages.json");

    // Create a request
    QNetworkRequest request(apiUrl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setRawHeader("Authorization", "Basic " + QByteArray((accountSid + ":" + authToken).toUtf8()).toBase64());

    // Prepare POST data
    QUrlQuery postData;
    postData.addQueryItem("To", phoneNumber);
    postData.addQueryItem("From", twilioPhoneNumber);
    postData.addQueryItem("Body", message);

    // Create a network manager and send the request
    QNetworkAccessManager* manager = new QNetworkAccessManager();
    QNetworkReply* reply = manager->post(request, postData.toString(QUrl::FullyEncoded).toUtf8());

    // Handle the reply
    QObject::connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QMessageBox::information(nullptr, "SMS envoye", "SMS envoyé avec succès.");
        } else {
            QMessageBox::critical(nullptr, "SMS erreur", "Échec de l'envoi du SMS. Erreur: " + reply->errorString());
        }

        // Clean up
        reply->deleteLater();
        manager->deleteLater();
    });
}


