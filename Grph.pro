#-------------------------------------------------
#
# Project created by QtCreator 2017-10-19T18:15:38
#
#-------------------------------------------------

QT += core gui
QT += testlib
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Grph
TEMPLATE = app

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
        mainwindow.cpp \
    operatorius.cpp \
    aparatas.cpp \
    meistrija.cpp \
    segmentas.cpp \
    linija.cpp \
    team.cpp \
    sidework.cpp \
    teamtask.cpp \
    daywork.cpp \
    roster.cpp \
    testobjects.cpp

HEADERS += \
        mainwindow.h \
    operatorius.h \
    aparatas.h \
    meistrija.h \
    segmentas.h \
    linija.h \
    team.h \
    sidework.h \
    teamtask.h \
    daywork.h \
    roster.h

FORMS += \
        mainwindow.ui
