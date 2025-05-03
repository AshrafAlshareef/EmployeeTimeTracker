#pragma once

#include <QDialog>

namespace Ui {
class ImportExportPage;
}

class ImportExportPage : public QDialog
{
    Q_OBJECT

public:
    explicit ImportExportPage(QWidget *parent = nullptr);
    ~ImportExportPage();

private:
    Ui::ImportExportPage *ui;
};
