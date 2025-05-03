
// core/hourscalculator.cpp
#include "hourscalculator.h"

/**
 * @brief Calculates total seconds worked on a given day.
 */
int HoursCalculator::calculateDailySeconds(const QList<WorkRecord> &records, const QDate &date) {
    int total = 0;
    for (const WorkRecord &rec : records) {
        if (rec.startTime.date() == date && rec.endTime.isValid()) {
            total += rec.startTime.secsTo(rec.endTime);
        }
    }
    return total;
}

/**
 * @brief Calculates total seconds worked in the ISO week of the given date.
 */
int HoursCalculator::calculateWeeklySeconds(const QList<WorkRecord> &records, const QDate &weekDate) {
    int total = 0;
    int week = weekDate.weekNumber();
    for (const WorkRecord &rec : records) {
        if (rec.startTime.date().weekNumber() == week && rec.endTime.isValid()) {
            total += rec.startTime.secsTo(rec.endTime);
        }
    }
    return total;
}

/**
 * @brief Calculates total seconds worked in the given month and year.
 */
int HoursCalculator::calculateMonthlySeconds(const QList<WorkRecord> &records, int year, int month) {
    int total = 0;
    for (const WorkRecord &rec : records) {
        QDate date = rec.startTime.date();
        if (date.year() == year && date.month() == month && rec.endTime.isValid()) {
            total += rec.startTime.secsTo(rec.endTime);
        }
    }
    return total;
}
