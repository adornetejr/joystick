#-------------------------------------------------
#
# Project created by QtCreator 2017-08-22T19:47:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = joystick
TEMPLATE = app

CONFIG += c++11

INCLUDEPATH += manual-control \
               manual-control/joystick-master \
               communication

LIBS += -lboost_system -lopencv_core
LIBS += -L$$PWD/manual-control/joystick-master/ -ljoystick

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
           mainwindow.cpp \
           manual-control/manualwindow.cpp \
           manual-control/playersdialog.cpp \
           manual-control/manualcontrol.cpp \
           communication/serialmessage.cpp \
           communication/ai2robotmessage.cpp

HEADERS += mainwindow.h \
           manual-control/manualwindow.h \
           manual-control/playersdialog.h \
           manual-control/manualcontrol.h \
           communication/serialcommunicator.h \
           communication/serialmessage.h \
           communication/ai2robotmessage.h

FORMS += mainwindow.ui \
         manual-control/manualwindow.ui \
         manual-control/playersdialog.ui
