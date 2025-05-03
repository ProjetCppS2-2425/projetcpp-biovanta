QT       += core gui quick sql printsupport charts widgets serialport network concurrent uitools

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    ai_report_generator.cpp \
    arduinoE.cpp \
    chercheur.cpp \
    chercheur_1.cpp \
    connection.cpp \
    equipement.cpp \
    equipement1.cpp \
    mainE.cpp \
    menu.cpp

HEADERS += \
    ai_report_generator.h \
    arduinoE.h \
    chercheur.h \
    chercheur_1.h \
    connection.h \
    equipement.h \
    equipement1.h \
    menu.h

FORMS += \
    equipement1.ui \
    chercheur_1.ui \
    menu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
