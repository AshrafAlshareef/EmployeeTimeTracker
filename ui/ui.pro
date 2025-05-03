TEMPLATE = lib
TARGET = ui
CONFIG += staticlib

HEADERS += employeepage.h \
           preferencespage.h \
           importexportpage.h

SOURCES += employeepage.cpp \
           preferencespage.cpp \
           importexportpage.cpp

FORMS += employeepage.ui \
         preferencespage.ui \
         importexportpage.ui
