// app/main.cpp
/**
 * @file main.cpp
 * @brief Entry point for the Employee Time Tracker application.
 */

#include <QApplication>
#include <QDebug>
#include <QDir>
#include "mainwindow.h"
#include "translator.h"
#include "appsettings.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    app.setApplicationName("EmployeeTimeTracker");
    app.setOrganizationName("MyCompany");

    // Load saved language from settings
    AppSettings settings;
    QString langCode = settings.languageCode();

    // Attempt to load translation
    bool ok = Translator::instance().loadLanguage(langCode);
    qDebug() << "Attempted to load language:" << langCode;
    qDebug() << "Translation load success:" << ok;
    if (!ok) {
        qWarning("Failed to load translation file!");
    }

    // Optional: List embedded translation resources
    qDebug() << "Available translation files in :/translations/i18n/:";
    const QStringList files = QDir(":/translations/i18n").entryList();
    for (const QString &file : files) {
        qDebug() << " -" << file;
    }

    MainWindow w;

    // Force UI update on startup (if any widget is connected to languageChanged)
    emit Translator::instance().languageChanged();

    // debug test
    qDebug() << QCoreApplication::translate("MainWindow", "ADD_EMPLOYEE");

    w.show();
    return app.exec();
}
