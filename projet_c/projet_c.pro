QT       += core gui sql printsupport charts


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets charts

CONFIG += c++17 console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Client.cpp \
    connection.cpp \
    history.cpp \
    main.cpp \
    mainwindow.cpp \
    qtstat.cpp \
    todo.cpp

HEADERS += \
    Client.h \
    connection.h \
    history.h \
    mainwindow.h \
    qtstat.h \
    todo.h

FORMS += \
    history.ui \
    mainwindow.ui \
    qtstat.ui \
    todo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
