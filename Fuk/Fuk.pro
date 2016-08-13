#-------------------------------------------------
#
# Project created by QtCreator 2016-04-24T22:22:20
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Fuk
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
    eigenschaft.cpp \
    fertigkeit.cpp \
    mainform.cpp \
    fertigkeitform.cpp \
    charakter.cpp \
    charaktermanager.cpp \
    charakterform.cpp \
    charakterrepository.cpp \
    credits.cpp \
    overview.cpp \
    startlogo.cpp \
    global.cpp \
    customview.cpp \
    textdocumentitem.cpp

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
    global.h \
    credits.h \
    overview.h \
    startlogo.h \
    customview.h \
    textdocumentitem.h

FORMS    += \
    mainform.ui \
    fertigkeitform.ui \
    charakterform.ui \
    credits.ui \
    overview.ui \
    startlogo.ui

RESOURCES += \
    images.qrc

win32{
    RC_FILE = Fuk.rc
}

macx {
    ICON = FUK_Logo_Version_1_Transparent_256.png.icns
}
