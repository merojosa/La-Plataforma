#-------------------------------------------------
#
# Project created by QtCreator 2016-12-13T12:44:56
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Plataforma
TEMPLATE = app


SOURCES += main.cpp \
    player.cpp \
    info.cpp \
    cubo.cpp \
    controlador.cpp \
    game.cpp \
    score.cpp

HEADERS  += \
    player.h \
    info.h \
    game.h \
    score.h


HEADERS  += \
    player.h \
    cubo.h \
    controlador.h

RESOURCES += \
    music.qrc

