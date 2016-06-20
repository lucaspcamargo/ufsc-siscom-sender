#-------------------------------------------------
#
# Project created by QtCreator 2016-06-06T19:26:32
#
#-------------------------------------------------

QT       += core gui
QT       += network #for sockets connection

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = siscom-sender
TEMPLATE = app


SOURCES += main.cpp\
        senderwindow.cpp \
    helpdialog.cpp \
    selectfile.cpp \
    udpclass.cpp \
    tcpsocket.cpp

HEADERS  += senderwindow.h \
    helpdialog.h \
    selectfile.h \
    udpclass.h \
    tcpsocket.h

FORMS    += senderwindow.ui \
    helpdialog.ui \
    selectfile.ui

RESOURCES += \
    resources.qrc
