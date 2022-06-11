QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    airlinenew.cpp \
    airload.cpp \
    airmanager.cpp \
    airupdate.cpp \
    choose.cpp \
    collect.cpp \
    landload.cpp \
    landmanager.cpp \
    landtruck.cpp \
    loadedit.cpp \
    main.cpp \
    mainwindow.cpp \
    postman.cpp \
    receive.cpp \
    send.cpp

HEADERS += \
    airlinenew.h \
    airload.h \
    airmanager.h \
    airupdate.h \
    choose.h \
    collect.h \
    dbconnect.h \
    landload.h \
    landmanager.h \
    landtruck.h \
    loadedit.h \
    mainwindow.h \
    postman.h \
    receive.h \
    send.h

FORMS += \
    airlinenew.ui \
    airload.ui \
    airmanager.ui \
    airupdate.ui \
    choose.ui \
    collect.ui \
    landload.ui \
    landmanager.ui \
    landtruck.ui \
    loadedit.ui \
    mainwindow.ui \
    postman.ui \
    receive.ui \
    send.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

