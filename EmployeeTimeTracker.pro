QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EmployeeTimeTracker
TEMPLATE = app

# UI, sources, headers
SOURCES += \
    main.cpp \
    mainwindow.cpp \
    ui/employeewidget.cpp \
    ui/employeeform.cpp \
    core/employee.cpp \
    core/hourscalculator.cpp \
    db/database.cpp \
    translations/translator.cpp

HEADERS += \
    mainwindow.h \
    ui/employeewidget.h \
    ui/employeeform.h \
    core/employee.h \
    core/hourscalculator.h \
    db/database.h \
    translations/translator.h

FORMS += \
    mainwindow.ui \
    ui/employeewidget.ui \
    ui/employeeform.ui

# Resource file (icons, translations)
RESOURCES += translations/translations.qrc

# Translations
TRANSLATIONS += \
    translations/i18n/en.ts \
    translations/i18n/ar.ts

# Enable C++17 or newer
CONFIG += c++17

# MySQL and SQLite support
QTPLUGIN += qsqlite qsqlmysql

# Installation folders (optional)
DESTDIR = bin
OBJECTS_DIR = build/obj
MOC_DIR = build/moc
RCC_DIR = build/rcc
UI_DIR = build/ui
