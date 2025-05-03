TEMPLATE = lib
TARGET = core
CONFIG += staticlib

# Safely extract just 'debug' or 'release'
contains(CONFIG, debug, debug|release) {
    DESTDIR = $$OUT_PWD/debug
} else {
    DESTDIR = $$OUT_PWD/release
}


HEADERS += employee.h \
           appsettings.h \
           hourscalculator.h

SOURCES += employee.cpp \
           appsettings.cpp \
           hourscalculator.cpp

