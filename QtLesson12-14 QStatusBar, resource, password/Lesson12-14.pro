#-------------------------------------------------
#
# Project created by QtCreator 2017-01-06T12:43:47
#
#-------------------------------------------------

QT       += core gui

QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LoginPass
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    secdialog.cpp

HEADERS  += mainwindow.h \
    secdialog.h

FORMS    += mainwindow.ui \
    secdialog.ui

OTHER_FILES += \
    display.png

RESOURCES += \
    resource.qrc
