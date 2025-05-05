QT += core gui widgets sql printsupport multimedia charts

CONFIG += c++17
QT += multimedia charts
QT += core gui widgets
# QR Code library (if using qrencode)

SOURCES += \
    connection.cpp \
    main.cpp \
    qrcodegen.cpp \
    test_biologique.cpp \
    testbio.cpp

HEADERS += \
    connection.h \
    qrcodegen.hpp \
    test_biologique.h \
    testbio.h

FORMS += \
    testbio.ui

# Deployment (optional)
unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
