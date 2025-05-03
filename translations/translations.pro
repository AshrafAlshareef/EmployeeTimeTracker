TEMPLATE = lib
TARGET = translations
CONFIG += staticlib

QT += core gui widgets

# Safely extract just 'debug' or 'release'
contains(CONFIG, debug, debug|release) {
    DESTDIR = $$OUT_PWD/debug
} else {
    DESTDIR = $$OUT_PWD/release
}


HEADERS += translator.h
SOURCES += translator.cpp

TRANSLATIONS += i18n/en.ts \
                i18n/ar.ts

RESOURCES += translations.qrc
