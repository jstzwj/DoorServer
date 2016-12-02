#-------------------------------------------------
#
# Project created by QtCreator 2016-11-30T23:08:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = doorpass
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    database/sqlite3.c \
    netconnection.cpp \
    messagerecord.cpp \
    message.cpp \
    dialogabout.cpp \
    dialoguser.cpp \
    dialogdepartment.cpp \
    dialogcontroller.cpp

HEADERS  += mainwindow.h \
    database/sqlite3.h \
    netconnection.h \
    messagerecord.h \
    message.h \
    dialogabout.h \
    dialoguser.h \
    dialogdepartment.h \
    dialogcontroller.h

FORMS    += mainwindow.ui \
    dialogabout.ui \
    dialoguser.ui \
    dialogdepartment.ui \
    dialogcontroller.ui

QT += axcontainer
QT += network
