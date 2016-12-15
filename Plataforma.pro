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
<<<<<<< HEAD
    score.cpp
=======
    misil.cpp
>>>>>>> 73b18137b4c13bab4eef100eb586a499256e4dc9

HEADERS  += \
    player.h \
    info.h \
    game.h \
<<<<<<< HEAD
    score.h
=======
    misil.h
>>>>>>> 73b18137b4c13bab4eef100eb586a499256e4dc9


HEADERS  += \
    player.h \
    cubo.h \
    controlador.h

RESOURCES += \
    music.qrc

