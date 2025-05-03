// app/main.cpp
/**
 * @file main.cpp
 * @brief Entry point for the Employee Time Tracker application.
 */

#include <QApplication>
#include "mainwindow.h"
#include "translator.h"

Translator translator; ///< Global translator instance

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    app.setApplicationName("EmployeeTimeTracker");
    app.setOrganizationName("MyCompany");

    // Load last used language
    translator.loadLanguage(translator.currentLanguage());

    MainWindow w;
    w.show();

    return app.exec();
}
