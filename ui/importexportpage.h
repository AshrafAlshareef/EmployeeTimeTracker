// ui/importexportpage.h
#pragma once

/**
 * @file importexportpage.h
 * @brief Declares the ImportExportPage widget for managing data import and export.
 */

#include <QWidget>

namespace Ui {
class ImportExportPage;
}

/**
 * @class ImportExportPage
 * @brief Widget for importing/exporting employee data in different formats.
 */
class ImportExportPage : public QWidget {
    Q_OBJECT

public:
    explicit ImportExportPage(QWidget *parent = nullptr);
    ~ImportExportPage();

private:
    Ui::ImportExportPage *ui; ///< Pointer to the UI
};
