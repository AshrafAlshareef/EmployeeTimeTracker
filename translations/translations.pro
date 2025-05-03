TEMPLATE = lib
TARGET = translations
CONFIG += staticlib

TRANSLATIONS += i18n/en.ts \
                i18n/ar.ts

HEADERS += translator.h

SOURCES += translator.cpp

RESOURCES += Translations.qrc
