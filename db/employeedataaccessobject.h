// db/employeedataaccessobject.h
#pragma once

/**
 * @file employeedataaccessobject.h
 * @brief Provides static methods to access employee records in the database.
 */

#include <QList>
#include <QVariantMap>
#include <QString>

/**
 * @class EmployeeDataAccessObject
 * @brief Handles all employee-related database operations.
 */
class EmployeeDataAccessObject {
public:
    /**
     * @brief Fetches all employees from the database.
     * @return List of QVariantMap, each containing keys: "id", "name"
     */
    static QList<QVariantMap> fetchEmployees();

    /**
     * @brief Inserts a new employee with the given name.
     * @param name Employee name
     * @param insertedId Optional pointer to store inserted record's ID
     * @return true if insert succeeds, false otherwise
     */
    static bool insertEmployee(const QString &name, int *insertedId = nullptr);
};
