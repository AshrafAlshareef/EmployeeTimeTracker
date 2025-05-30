
// db/employeedataaccessobject.cpp
#include "employeedataaccessobject.h"
#include "dbmanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDateTime>

QList<QVariantMap> EmployeeDataAccessObject::fetchEmployees() {
    QSqlDatabase db = DBManager::instance().database();
    QList<QVariantMap> employees;

    QSqlQuery query("SELECT id, name FROM employees", db);
    if (!query.exec()) {
        qWarning() << "Failed to fetch employees:" << query.lastError().text();
        return employees;
    }

    while (query.next()) {
        QVariantMap emp;
        emp["id"] = query.value("id");
        emp["name"] = query.value("name");
        employees.append(emp);
    }

    if (employees.isEmpty()) {
        employees.append({{"id", -1}, {"name", "Alice Example"}});
        employees.append({{"id", -2}, {"name", "Bob Example"}});
    }

    return employees;
}

bool EmployeeDataAccessObject::insertEmployee(const QString &name, int *insertedId) {
    QSqlDatabase db = DBManager::instance().database();
    QSqlQuery query(db);

    query.prepare("INSERT INTO employees (name) VALUES (:name)");
    query.bindValue(":name", name);

    if (!query.exec()) {
        qWarning() << "Insert employee failed:" << query.lastError().text();
        return false;
    }

    if (insertedId) {
        *insertedId = query.lastInsertId().toInt();
    }

    return true;
}

bool EmployeeDataAccessObject::insertEmployee(
    const QString &name, const QString &phone, const QString &idNumber,
    const QDate &birthDate, int *insertedId)
{
    QSqlQuery query(DBManager::instance().database());
    query.prepare(R"(
        INSERT INTO employees (name, phone, id_number, birth_date)
        VALUES (:name, :phone, :idnum, :birth)
    )");
    query.bindValue(":name", name);
    query.bindValue(":phone", phone);
    query.bindValue(":idnum", idNumber);
    query.bindValue(":birth", birthDate.toString(Qt::ISODate));

    if (!query.exec()) return false;
    if (insertedId) *insertedId = query.lastInsertId().toInt();
    return true;
}
