QT       += core gui
QT+= sql
QT += printsupport
QT += core gui sql printsupport
QT += core gui sql printsupport widgets

QT += charts
QT += charts sql
QT += network  # Ensure network module is linked
QT += core gui network printsupport  # Required modules
QT += core gui network printsupport
QT += concurrent
QT += serialport
QT += core gui serialport

QT += uitools
FORMS += equipement1.ui \
    mainwindow.ui
    FORMS +=
    QT += widgets uitools


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    84.cpp \
    ai_report_generator.cpp \
    arduino1.cpp \
    chercheur.cpp \
    chercheur_1.cpp \
    equipement.cpp \
    equipement1.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    84.h \
    ai_report_generator.h \
    arduino1.h \
    chercheur.h \
    chercheur_1.h \
    equipement.h \
    equipement1.h \
    mainwindow.h

FORMS += \
    chercheur_1.ui \
    equipement1.ui
    equipement1.ui



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
