// core/employee.h
#pragma once

/**
 * @file employee.h
 * @brief Defines the Employee class and WorkRecord struct for representing employee information and working sessions.
 */

#include <QString>
#include <QDateTime>
#include <QList>

/**
 * @struct WorkRecord
 * @brief Represents a single working session with start and end times.
 */
struct WorkRecord {
    int id = -1;               ///< Unique identifier of the work record
    QDateTime startTime;       ///< Start time of the session
    QDateTime endTime;         ///< End time of the session
};

/**
 * @class Employee
 * @brief Represents an employee and a list of their working records.
 */
class Employee {
public:
    Employee();
    Employee(int id, const QString &name);

    int id() const;                     ///< Returns the employee ID
    QString name() const;              ///< Returns the employee name

    void setId(int newId);             ///< Sets the employee ID
    void setName(const QString &newName); ///< Sets the employee name

    void addWorkRecord(const WorkRecord &record); ///< Adds a work record
    QList<WorkRecord> workRecords() const;        ///< Returns all work records

private:
    int _id;                   ///< Employee ID
    QString _name;             ///< Employee name
    QList<WorkRecord> _records; ///< List of work records
};
