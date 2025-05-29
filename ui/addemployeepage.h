#pragma once

#include <QWidget>

namespace Ui {
class AddEmployeePage;
}

class AddEmployeePage : public QWidget
{
    Q_OBJECT

public:
    explicit AddEmployeePage(QWidget *parent = nullptr);
    ~AddEmployeePage();

private slots:
    void onConfirmAddClicked();

private:
    Ui::AddEmployeePage *ui;
};
