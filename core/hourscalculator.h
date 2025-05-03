// core/hourscalculator.h
#pragma once

/**
 * @file hourscalculator.h
 * @brief Provides utility functions to calculate total working time from employee records.
 *
 * This class offers static methods to calculate:
 * - Daily working time for a specific date
 * - Weekly working time based on ISO week number
 * - Monthly working time given a month and year
 */

#include <QList>
#include <QDate>
#include "employee.h"

/**
 * @class HoursCalculator
 * @brief Utility class for working hours calculation based on work records.
 */
class HoursCalculator {
public:
    /**
     * @brief Calculates total seconds worked on a given day.
     * @param records List of work records
     * @param date The day to sum durations for
     * @return Total seconds worked that day
     */
    static int calculateDailySeconds(const QList<WorkRecord> &records, const QDate &date);

    /**
     * @brief Calculates total seconds worked during the ISO week of the given date.
     * @param records List of work records
     * @param weekDate A date within the week to analyze
     * @return Total seconds worked that week
     */
    static int calculateWeeklySeconds(const QList<WorkRecord> &records, const QDate &weekDate);

    /**
     * @brief Calculates total seconds worked in a given month of a year.
     * @param records List of work records
     * @param year The year
     * @param month The month (1-12)
     * @return Total seconds worked that month
     */
    static int calculateMonthlySeconds(const QList<WorkRecord> &records, int year, int month);
};
