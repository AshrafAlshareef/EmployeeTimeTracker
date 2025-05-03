// core/appsettings.h
#pragma once

/**
 * @file appsettings.h
 * @brief Provides persistent application-level settings such as database config and UI preferences.
 */

#include <QString>
#include <QSettings>

/**
 * @class AppSettings
 * @brief Centralized access to application settings stored in QSettings.
 */
class AppSettings {
public:
    AppSettings();

    QString databaseHost() const;
    int databasePort() const;
    QString databaseName() const;
    QString databaseUser() const;
    QString databasePassword() const;

    QString languageCode() const;

    void setDatabaseHost(const QString &value);
    void setDatabasePort(int value);
    void setDatabaseName(const QString &value);
    void setDatabaseUser(const QString &value);
    void setDatabasePassword(const QString &value);

    void setLanguageCode(const QString &value);

private:
    QSettings _settings; ///< Internal settings object (INI or platform-specific)
};
