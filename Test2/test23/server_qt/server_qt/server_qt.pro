TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt

QT += network core

SOURCES += main.cpp \
    server.cpp \
    worker.cpp

HEADERS += \
    server.h \
    worker.h
