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
    // translator.loadLanguage(translator.currentLanguage());
    // Choose language manually (could be from settings)
    QString langCode = "ar";  // or "en"

    // Load from resource file (thanks to translations.qrc)
    if (translator.loadLanguage(langCode))
    {
        qWarning("Translation file not loaded!");
    }

    MainWindow w;
    w.show();

    return app.exec();
}
