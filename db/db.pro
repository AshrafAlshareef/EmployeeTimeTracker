TEMPLATE = lib
TARGET = db
CONFIG += staticlib

QT += sql

# Safely extract just 'debug' or 'release'
contains(CONFIG, debug, debug|release) {
    DESTDIR = $$OUT_PWD/debug
} else {
    DESTDIR = $$OUT_PWD/release
}


HEADERS += dbmanager.h \
           employeedataaccessobject.h \
           workrecorddataaccessobject.h

SOURCES += dbmanager.cpp \
           employeedataaccessobject.cpp \
           workrecorddataaccessobject.cpp
