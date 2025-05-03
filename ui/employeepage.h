#pragma once

#include <QDialog>

namespace Ui {
class EmployeePage;
}

class EmployeePage : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeePage(QWidget *parent = nullptr);
    ~EmployeePage();

private:
    Ui::EmployeePage *ui;
};
