#include "employeepage.h"
#include "ui_employeepage.h"

EmployeePage::EmployeePage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EmployeePage)
{
    ui->setupUi(this);
}

EmployeePage::~EmployeePage()
{
    delete ui;
}
