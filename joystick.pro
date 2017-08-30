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

LIBS += -lboost_system -lopencv_core -pthread
LIBS += -L$$PWD/manual-control/joystick-master/ -ljoystick

DEFINES += QT_DEPRECATED_WARNINGS

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
