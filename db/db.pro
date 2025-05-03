TEMPLATE = lib
TARGET = db
CONFIG += staticlib

HEADERS += dbmanager.h \
           employeedao.h \
           workrecorddao.h

SOURCES += dbmanager.cpp \
           employeedao.cpp \
           workrecorddao.cpp
