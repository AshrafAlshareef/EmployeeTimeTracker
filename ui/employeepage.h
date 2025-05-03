// ui/employeepage.h
#pragma once

/**
 * @file employeepage.h
 * @brief Declares the EmployeePage widget used to manage an employee's work records.
 */

#include <QWidget>

namespace Ui {
class EmployeePage;
}

/**
 * @class EmployeePage
 * @brief Widget for displaying and editing work records for a selected employee.
 */
class EmployeePage : public QWidget {
    Q_OBJECT

public:
    explicit EmployeePage(QWidget *parent = nullptr);
    ~EmployeePage();

private:
    Ui::EmployeePage *ui; ///< UI pointer for the EmployeePage widget
};
