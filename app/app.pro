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

contains(CONFIG, debug, debug|release) {
    BUILD_TYPE = debug
} else {
    BUILD_TYPE = release
}

LIBS += -L$$OUT_PWD/../core/$$BUILD_TYPE -lcore \
        -L$$OUT_PWD/../db/$$BUILD_TYPE -ldb \
        -L$$OUT_PWD/../ui/$$BUILD_TYPE -lui \
        -L$$OUT_PWD/../translations/$$BUILD_TYPE -ltranslations

