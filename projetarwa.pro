QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets sql charts printsupport

CONFIG += c++17
QT += charts
QT += network

QT += serialport


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduinomanager.cpp \
    chatbot.cpp \
    connection.cpp \
    geminiapi.cpp \
    main.cpp \
    mainwindow.cpp \
    statistique.cpp \
    vaccin.cpp \
    vaccin_ui.cpp

HEADERS += \
    arduinomanager.h \
    chatbot.h \
    connection.h \
    geminiapi.h \
    mainwindow.h \
    statistique.h \
    vaccin.h \
    vaccin_ui.h

FORMS += \
    mainwindow.ui \
    statistique.ui \
    vaccin_ui.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
