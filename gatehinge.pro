#-------------------------------------------------
#
# Project created by QtCreator 2016-11-29T01:49:49
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gatehinge
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
        routehandler.cpp \
    settingsdialog.cpp

HEADERS  += mainwindow.h\
            routehandler.h \
    settingsdialog.h

FORMS    += mainwindow.ui \
    settingsdialog.ui
