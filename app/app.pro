QT += core gui widgets sql

TARGET = EmployeeTimeTracker
TEMPLATE = app

INCLUDEPATH += ../core ../db ../ui ../translations

SOURCES += main.cpp \
           mainwindow.cpp \
           ../translations/translator.cpp

HEADERS += mainwindow.h \
           ../translations/translator.h

FORMS += mainwindow.ui

RESOURCES += ../translations/translations.qrc
