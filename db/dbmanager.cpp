
// db/dbmanager.cpp
#include "dbmanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

/**
 * @brief Private constructor
 */
DBManager::DBManager() {}

/**
 * @brief Returns the singleton instance
 */
DBManager &DBManager::instance() {
    static DBManager instance;
    return instance;
}

/**
 * @brief Attempts to connect to a MySQL database.
 */
bool DBManager::connectToMySQL(
    const QString &host,
    int port,
    const QString &dbName,
    const QString &user,
    const QString &password
    )
{
    if (QSqlDatabase::contains("main"))
    {
        _db = QSqlDatabase::database("main");
    }
    else
    {
        _db = QSqlDatabase::addDatabase("QMYSQL", "main");
    }

    _db.setHostName(host);
    _db.setPort(port);
    _db.setDatabaseName(dbName);
    _db.setUserName(user);
    _db.setPassword(password);

    _connectedToMySQL = _db.open();
    if (!_connectedToMySQL)
    {
        qWarning() << "MySQL connection failed:" << _db.lastError().text();
    }

    return _connectedToMySQL;
}

/**
 * @brief Uses SQLite as a fallback and creates tables if necessary.
 */
void DBManager::useSQLiteFallback(const QString &sqlitePath) {
    if (QSqlDatabase::contains("main")) {
        _db = QSqlDatabase::database("main");
    } else {
        _db = QSqlDatabase::addDatabase("QSQLITE", "main");
    }

    _db.setDatabaseName(sqlitePath);
    if (!_db.open()) {
        qCritical() << "SQLite fallback failed:" << _db.lastError().text();
        return;
    }

    _connectedToMySQL = false;
    QSqlQuery query(_db);

    // Create tables if they don't exist
    query.exec(R"(
        CREATE TABLE IF NOT EXISTS employees (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL
        )
    )");

    query.exec(R"(
        CREATE TABLE IF NOT EXISTS work_records (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            employee_id INTEGER NOT NULL,
            start_time DATETIME,
            end_time DATETIME,
            FOREIGN KEY(employee_id) REFERENCES employees(id)
        )
    )");
}

/**
 * @brief Returns the active database connection.
 */
QSqlDatabase DBManager::database() const {
    return _db;
}

/**
 * @brief Indicates whether the app is using MySQL.
 */
bool DBManager::isConnectedToMySQL() const {
    return _connectedToMySQL;
}
