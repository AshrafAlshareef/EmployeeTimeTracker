TEMPLATE = lib
TARGET = db
CONFIG += staticlib

HEADERS += dbmanager.h \
           employeedataaccessobject.h \
           workrecorddataaccessobject.h

SOURCES += dbmanager.cpp \
           employeedataaccessobject.cpp \
           workrecorddataaccessobject.cpp
