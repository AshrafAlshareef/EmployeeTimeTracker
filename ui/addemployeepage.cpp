#include "addemployeepage.h"
#include "ui_addemployeepage.h"

#include <QMessageBox>
#include <../db/employeedataaccessobject.h>

AddEmployeePage::AddEmployeePage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddEmployeePage)
{
    ui->setupUi(this);

    connect(ui->btnConfirmAdd, &QPushButton::clicked,
            this, &AddEmployeePage::onConfirmAddClicked);

}

AddEmployeePage::~AddEmployeePage()
{
    delete ui;
}

void AddEmployeePage::onConfirmAddClicked() {
    QString firstName = ui->editFirstName->text().trimmed();
    QString lastName  = ui->editLastName->text().trimmed();

    if (firstName.isEmpty() || lastName.isEmpty()) {
        QMessageBox::warning(this, tr("Missing Data"),
                             tr("First name and last name are required."));
        return;
    }

    QString middleName = ui->editMiddleName->text().trimmed();
    QString fullName = QString("%1 %2 %3").arg(firstName, middleName, lastName).simplified();

    QString phone = ui->editTelephone->text().trimmed();
    QString idNumber = ui->editIdNumber->text().trimmed();
    QDate birthDate = ui->editBirthDate->date();

    int insertedId = -1;
    if (EmployeeDataAccessObject::insertEmployee(fullName, &insertedId)) {
        QMessageBox::information(this, tr("Success"),
                                 tr("Employee '%1' added with ID %2.")
                                     .arg(fullName).arg(insertedId));
        // Optionally: clear form
        ui->editFirstName->clear();
        ui->editMiddleName->clear();
        ui->editLastName->clear();
        ui->editTelephone->clear();
        ui->editIdNumber->clear();
    }
    else
    {
        QMessageBox::critical(this, tr("Error"),
                              tr("Failed to insert employee."));
    }
}
