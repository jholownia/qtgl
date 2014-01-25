#-------------------------------------------------
#
# Project created by QtCreator 2014-01-24T20:55:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtgl
TEMPLATE = app


SOURCES += main.cpp \
    window.cpp \
    basicusagescene.cpp

HEADERS  += \
    window.h \
    abstractscene.h \
    basicusagescene.h

OTHER_FILES += \
    shaders/phong.frag \
    shaders/phong.vert

RESOURCES += \
    resources.qrc

