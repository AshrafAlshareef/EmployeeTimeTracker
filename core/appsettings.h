// core/appsettings.h
#pragma once

#include <QString>
#include <QSettings>

/**
 * @class AppSettings
 * @brief Singleton class for centralized access to application settings.
 */
class AppSettings {
public:
    static AppSettings& instance();  // Singleton accessor

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
    AppSettings();  // Private constructor
    Q_DISABLE_COPY(AppSettings)  // Disable copy constructor and assignment
    QSettings _settings; ///< Internal settings object (INI or platform-specific)

};

