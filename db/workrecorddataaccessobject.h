// db/workrecorddataaccessobject.h
#pragma once

/**
 * @file workrecorddataaccessobject.h
 * @brief Provides static methods for accessing and managing employee work records.
 */

#include <QList>
#include <QVariantMap>
#include <QDateTime>

/**
 * @class WorkRecordDataAccessObject
 * @brief Manages work session database operations for employees.
 */
class WorkRecordDataAccessObject {
public:
    /**
     * @brief Retrieves all work records for a specific employee.
     * @param employeeId ID of the employee
     * @return List of work record maps
     */
    static QList<QVariantMap> fetchRecordsForEmployee(int employeeId);

    /**
     * @brief Starts a work session by inserting a start time.
     * @param employeeId ID of the employee
     * @return true on success
     */
    static bool insertStartTime(int employeeId);

    /**
     * @brief Ends the most recent open work session.
     * @param employeeId ID of the employee
     * @return true on success
     */
    static bool insertStopTime(int employeeId);

    /**
     * @brief Updates the end time for a specific work record.
     * @param id ID of the work record
     * @param endTime New end time to be saved
     * @return true on success
     */
    static bool updateEndTime(int id, const QDateTime &endTime);
};
