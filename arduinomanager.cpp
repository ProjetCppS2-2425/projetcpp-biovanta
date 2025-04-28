#include "arduinomanager.h"
#include <QDebug>

ArduinoManager::ArduinoManager(QObject *parent) : QObject(parent), serial(new QSerialPort(this)) {}

void ArduinoManager::start() {
    serial->setPortName("COM5"); // À adapter selon ton port
    serial->setBaudRate(QSerialPort::Baud9600);
    if (serial->open(QIODevice::ReadOnly)) {
        connect(serial, &QSerialPort::readyRead, this, &ArduinoManager::readData);
        qDebug() << "Connexion Arduino OK";
    } else {
        qDebug() << "Erreur connexion Arduino";
    }
}

void ArduinoManager::readData() {
    while (serial->canReadLine()) {
        QByteArray line = serial->readLine().trimmed();
        QString data(line);

        if (data == "FAN_ON" || data == "FAN_OFF") {
            fanStatus = data;
            emit fanStatusChanged(fanStatus);
        }
    }
}

QString ArduinoManager::lastFanStatus() const {
    return fanStatus;
}
