TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += network core

SOURCES += main.cpp \
    client.cpp \
    a.cpp \
    worker.cpp \
    worker.cpp \
    a.cpp

HEADERS += \
    client.h \
    a.h \
    worker.h \
    worker.h
