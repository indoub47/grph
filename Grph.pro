#-------------------------------------------------
#
# Project created by QtCreator 2017-10-19T18:15:38
#
#-------------------------------------------------

# uzkomentuota mano pagal testapp
#QT += core gui

# prideta mano pagal testapp
QT -= gui

# sitas reikalingas testavimui
QT += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Grph
TEMPLATE = app

# prideta mano pagal testapp
CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    apar.cpp \
    daywork.cpp \
    div.cpp \
    json/fromjson.cpp \
    linija.cpp \
    main.cpp \
	mainwindow.cpp \
    oper.cpp \
    poolmanager.cpp \
    roster.cpp \
    segm.cpp \
    swork.cpp \
    team.cpp \
    teamtask.cpp \
    testobjects.cpp

HEADERS += \
    apar.h \
    daywork.h \
    div.h \
    json/fromjson.h \
    linija.h \
	mainwindow.h \
    oper.h \
    poolmanager.h \
    roster.h \
    segm.h \
    swork.h \
    team.h \
    teamtask.h

DISTFILES += \
    json/storage.json

FORMS += \
        mainwindow.ui
