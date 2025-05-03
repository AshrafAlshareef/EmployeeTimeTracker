// db/dbmanager.h
#pragma once

/**
 * @file dbmanager.h
 * @brief Singleton class for managing database connections (MySQL and SQLite fallback).
 *
 * This class ensures a consistent interface for the application to interact with either
 * a MySQL database or a local SQLite fallback, and sets up necessary tables on fallback.
 */

#include <QSqlDatabase>
#include <QString>

/**
 * @class DBManager
 * @brief Provides a singleton interface to connect to MySQL or SQLite databases.
 */
class DBManager {
public:
    /**
     * @brief Returns the singleton instance of DBManager.
     */
    static DBManager &instance();

    /**
     * @brief Connects to a MySQL database.
     * @param host Hostname or IP address
     * @param port Port number
     * @param dbName Database name
     * @param user Username
     * @param password Password
     * @return true if connection succeeded; false otherwise
     */
    bool connectToMySQL(const QString &host, int port,
                        const QString &dbName,
                        const QString &user,
                        const QString &password);

    /**
     * @brief Initializes SQLite fallback database and creates required tables if missing.
     * @param sqlitePath Path to local SQLite file
     */
    void useSQLiteFallback(const QString &sqlitePath);

    /**
     * @brief Returns the current QSqlDatabase instance.
     * @return Active QSqlDatabase connection
     */
    QSqlDatabase database() const;

    /**
     * @brief Returns true if currently connected to MySQL.
     * @return True if using MySQL, false if using SQLite
     */
    bool isConnectedToMySQL() const;

private:
    DBManager(); ///< Private constructor for singleton

    QSqlDatabase _db; ///< Internal database connection
    bool _connectedToMySQL = false; ///< Tracks connection mode
};
