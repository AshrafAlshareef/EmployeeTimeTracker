// core/employee.cpp
#include "employee.h"

/**
 * @brief Default constructor initializes the ID to -1.
 */
Employee::Employee() : _id(-1) {}

/**
 * @brief Constructs an employee with a given ID and name.
 * @param id The employee ID
 * @param name The employee name
 */
Employee::Employee(int id, const QString &name)
    : _id(id), _name(name) {}

int Employee::id() const { return _id; }
QString Employee::name() const { return _name; }

void Employee::setId(int newId) { _id = newId; }
void Employee::setName(const QString &newName) { _name = newName; }

void Employee::addWorkRecord(const WorkRecord &record) {
    _records.append(record);
}

QList<WorkRecord> Employee::workRecords() const {
    return _records;
}
