
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
