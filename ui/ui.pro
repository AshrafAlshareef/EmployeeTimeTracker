TEMPLATE = lib
TARGET = ui
CONFIG += staticlib

QT += widgets

# Safely extract just 'debug' or 'release'
contains(CONFIG, debug, debug|release) {
    DESTDIR = $$OUT_PWD/debug
} else {
    DESTDIR = $$OUT_PWD/release
}


HEADERS += employeepage.h \
           importexportpage.h \
           preferencespage.h \

SOURCES += employeepage.cpp \
           importexportpage.cpp \
           preferencespage.cpp \

FORMS += employeepage.ui \
         importexportpage.ui \
         preferencespage.ui \
