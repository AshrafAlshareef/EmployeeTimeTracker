

// db/workrecorddataaccessobject.cpp
#include "workrecorddataaccessobject.h"
#include "dbmanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

QList<QVariantMap> WorkRecordDataAccessObject::fetchRecordsForEmployee(int employeeId) {
    QList<QVariantMap> records;
    QSqlQuery query(DBManager::instance().database());

    query.prepare("SELECT id, start_time, end_time FROM work_records WHERE employee_id = :id ORDER BY start_time DESC");
    query.bindValue(":id", employeeId);

    if (!query.exec()) return records;

    while (query.next()) {
        QVariantMap rec;
        rec["id"] = query.value("id");
        rec["start_time"] = query.value("start_time");
        rec["end_time"] = query.value("end_time");
        records.append(rec);
    }
    return records;
}

bool WorkRecordDataAccessObject::insertStartTime(int employeeId) {
    QSqlQuery query(DBManager::instance().database());

    query.prepare("INSERT INTO work_records (employee_id, start_time) VALUES (:id, :start)");
    query.bindValue(":id", employeeId);
    query.bindValue(":start", QDateTime::currentDateTime());

    return query.exec();
}

bool WorkRecordDataAccessObject::insertStopTime(int employeeId) {
    QSqlQuery query(DBManager::instance().database());

    query.prepare("UPDATE work_records SET end_time = :end WHERE employee_id = :id AND end_time IS NULL");
    query.bindValue(":id", employeeId);
    query.bindValue(":end", QDateTime::currentDateTime());

    return query.exec();
}

bool WorkRecordDataAccessObject::updateEndTime(int id, const QDateTime &endTime) {
    QSqlQuery query(DBManager::instance().database());

    query.prepare("UPDATE work_records SET end_time = :end WHERE id = :id");
    query.bindValue(":end", endTime);
    query.bindValue(":id", id);

    return query.exec();
}
