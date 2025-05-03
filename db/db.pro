TEMPLATE = lib
TARGET = db
CONFIG += staticlib

QT += sql


HEADERS += dbmanager.h \
           employeedataaccessobject.h \
           workrecorddataaccessobject.h

SOURCES += dbmanager.cpp \
           employeedataaccessobject.cpp \
           workrecorddataaccessobject.cpp
