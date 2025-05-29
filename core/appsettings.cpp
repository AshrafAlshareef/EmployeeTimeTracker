// core/appsettings.cpp
#include "appsettings.h"

AppSettings::AppSettings() : _settings("MyCompany", "EmployeeTimeTracker") {}

AppSettings& AppSettings::instance()
{
    static AppSettings _instance;
    return _instance;
}

QString AppSettings::databaseHost() const { return _settings.value("db/host", "localhost").toString(); }
int AppSettings::databasePort() const { return _settings.value("db/port", 3306).toInt(); }
QString AppSettings::databaseName() const { return _settings.value("db/name", "employees").toString(); }
QString AppSettings::databaseUser() const { return _settings.value("db/user", "root").toString(); }
QString AppSettings::databasePassword() const { return _settings.value("db/password", "").toString(); }
QString AppSettings::languageCode() const { return _settings.value("app/lang", "en").toString(); }

void AppSettings::setDatabaseHost(const QString &value) { _settings.setValue("db/host", value); }
void AppSettings::setDatabasePort(int value) { _settings.setValue("db/port", value); }
void AppSettings::setDatabaseName(const QString &value) { _settings.setValue("db/name", value); }
void AppSettings::setDatabaseUser(const QString &value) { _settings.setValue("db/user", value); }
void AppSettings::setDatabasePassword(const QString &value) { _settings.setValue("db/password", value); }
void AppSettings::setLanguageCode(const QString &value) { _settings.setValue("app/lang", value); }
