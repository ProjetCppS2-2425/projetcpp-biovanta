QT       += core gui
QT+= sql
QT += core gui printsupport
QT += core gui sql printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QT += charts
QT += charts sql
QT += printsupport
QT += core gui sql printsupport
QT += core gui sql printsupport widgets
QT += core gui widgets sql
QT += charts
QT += charts sql
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
QT += sql printsupport
SOURCES += \
    connection.cpp \
    main.cpp \
    mainwindow.cpp \
    test_biologique.cpp

HEADERS += \
    connection.h \
    mainwindow.h \
    test_biologique.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
QT += core gui sql printsupport  # Required for QPrinter
QT += core gui sql printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
