
// ui/employeepage.cpp
#include "employeepage.h"
#include "ui_employeepage.h"

/**
 * @brief Constructs the EmployeePage and sets up the UI.
 */
EmployeePage::EmployeePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EmployeePage) {
    ui->setupUi(this);
}

/**
 * @brief Destructor for EmployeePage.
 */
EmployeePage::~EmployeePage() {
    delete ui;
}


void EmployeePage::setEmployee(const Employee &employee)
{
    ui->labelId->setText(QString::number(employee.id()));
    ui->labelName->setText(employee.name());

    ui->tableWorkRecords->setRowCount(employee.workRecords().size());
    int row = 0;
    for (const WorkRecord &rec : employee.workRecords()) {
        ui->tableWorkRecords->setItem(row, 0, new QTableWidgetItem(rec.startTime.toString()));
        ui->tableWorkRecords->setItem(row, 1, new QTableWidgetItem(rec.endTime.toString()));
        ++row;
    }

}
