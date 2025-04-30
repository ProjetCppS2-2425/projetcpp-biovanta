#include "arduino.h"
#include <QDebug>

arduino::arduino()
{
    data="";
    arduino_port_name="";
    arduino_is_available=false;
    serial=new QSerialPort;
}

QString arduino::getarduino_port_name()
{
    return arduino_port_name;
}

QSerialPort *arduino::getserial()
{
    return serial;
}
int arduino::connect_arduino()
{
    qDebug() << "=== Recherche des ports série disponibles ===";

    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()) {
        qDebug() << "Port trouvé:" << serial_port_info.portName()
                 << "Description:" << serial_port_info.description()
                 << "Fabricant:" << serial_port_info.manufacturer()
                 << "Vendor ID:" << (serial_port_info.hasVendorIdentifier() ?
                                         QString::number(serial_port_info.vendorIdentifier(), 16) : "N/A")
                 << "Product ID:" << (serial_port_info.hasProductIdentifier() ?
                                          QString::number(serial_port_info.productIdentifier(), 16) : "N/A");

        if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()) {
            if(serial_port_info.vendorIdentifier() == arduino_uno_vendor_id &&
                serial_port_info.productIdentifier() == arduino_uno_producy_id) {
                arduino_is_available = true;
                arduino_port_name = serial_port_info.portName();
                qDebug() << "Arduino trouvé sur port:" << arduino_port_name;
            }
        }
    }

    if(arduino_is_available) {
        serial->setPortName(arduino_port_name);
        if(serial->open(QSerialPort::ReadWrite)) {
            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort::Data8);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
            serial->setFlowControl(QSerialPort::NoFlowControl);
            qDebug() << "Connexion établie avec succès sur" << arduino_port_name;
            return 0;
        }
        qDebug() << "Échec d'ouverture du port" << arduino_port_name;
        return 1;
    }

    qDebug() << "Aucun Arduino détecté. Vérifiez :";
    qDebug() << "- Que la carte est bien branchée";
    qDebug() << "- Que les drivers sont installés";
    qDebug() << "- Que les IDs dans arduino.h correspondent à votre carte";

    return -1;
}
int arduino::close_arduino()

{

    if(serial->isOpen()){
        serial->close();
        return 0;
    }
    return 1;


}


QByteArray arduino::read_from_arduino()
{
    if(serial->isReadable()){
        data=serial->readAll(); //récupérer les données reçues

        return data;
    }
}


int arduino::write_to_arduino( QByteArray d)

{

    if(serial->isWritable()){
        serial->write(d);  // envoyer des donnés vers Arduino
    }else{
        qDebug() << "Couldn't write to serial!";
    }


}
