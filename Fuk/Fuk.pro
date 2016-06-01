#-------------------------------------------------
#
# Project created by QtCreator 2016-04-24T22:22:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Fuk
TEMPLATE = app


SOURCES += main.cpp\
    eigenschaft.cpp \
    fertigkeit.cpp \
    mainform.cpp \
    fertigkeitform.cpp \
    charakter.cpp \
    charaktermanager.cpp \
    charakterform.cpp \
    charakterrepository.cpp

HEADERS  += \
    eigenschaft.h \
    fertigkeit.h \
    mainform.h \
    fertigkeitform.h \
    charakter.h \
    charaktermanager.h \
    eigenschaftexception.h \
    merkmal.h \
    charakterform.h \
    charakterrepository.h \
    global.h

FORMS    += \
    mainform.ui \
    fertigkeitform.ui \
    charakterform.ui
