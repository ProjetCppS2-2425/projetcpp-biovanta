QT       += core gui quick sql printsupport charts widgets serialport network concurrent uitools

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    Client.cpp \
    ai_report_generator.cpp \
    arduinoE.cpp \
    chercheur.cpp \
    chercheur_1.cpp \
    client1.cpp \
    connection.cpp \
    equipement.cpp \
    equipement1.cpp \
    history.cpp \
    mainE.cpp \
    qtstat.cpp \
    todo.cpp \
    vaccin.cpp \
    geminiapi.cpp \
    chatbot.cpp \
    arduinomanager.cpp \
    statistique.cpp \
    menu.cpp \
    Client.cpp \
    test_biologique.cpp \
    testbio.cpp \
    qrcodegen.cpp \
    vaccin1.cpp


HEADERS += \
    Client.h \
    ai_report_generator.h \
    arduinoE.h \
    chercheur.h \
    chercheur_1.h \
    client1.h \
    connection.h \
    equipement.h \
    equipement1.h \
    history.h \
    qtstat.h \
    todo.h \
    vaccin.h \
    geminiapi.h \
    chatbot.h \
    arduinomanager.h \
    statistique.h \
    menu.h \
    Client.h \
    test_biologique.h \
    testbio.h \
    qrcodegen.hpp \
    vaccin1.h


FORMS += \
    client1.ui \
    equipement1.ui \
    chercheur_1.ui \
    projet_c/history.ui \
    qtstat.ui \
    todo.ui \
    vaccin1.ui \
    vaccin_ui.ui \
    statistique.ui \
    testbio.ui \
    menu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
