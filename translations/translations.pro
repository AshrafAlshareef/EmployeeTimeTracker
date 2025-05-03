TEMPLATE = lib
TARGET = translations
CONFIG += staticlib

QT += core gui widgets

HEADERS += translator.h
SOURCES += translator.cpp

TRANSLATIONS += i18n/en.ts \
                i18n/ar.ts

RESOURCES += translations.qrc
