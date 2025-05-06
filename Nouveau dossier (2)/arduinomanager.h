#ifndef ARDUINOMANAGER_H
#define ARDUINOMANAGER_H

#include <QObject>
#include <QSerialPort>

class ArduinoManager : public QObject {
    Q_OBJECT
public:
    explicit ArduinoManager(QObject *parent = nullptr);
    void start();
    QString lastFanStatus() const;

signals:
    void fanStatusChanged(const QString &status);

private slots:
    void readData();

private:
    QSerialPort *serial;
    QString fanStatus;
};

#endif // ARDUINOMANAGER_H
