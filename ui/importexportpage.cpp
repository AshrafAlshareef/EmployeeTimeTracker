// ui/importexportpage.cpp
#include "importexportpage.h"
#include "ui_importexportpage.h"

/**
 * @brief Constructs the ImportExportPage and initializes the UI.
 */
ImportExportPage::ImportExportPage(QWidget *parent)
    : QWidget(parent), ui(new Ui::ImportExportPage) {
    ui->setupUi(this);
}

/**
 * @brief Destructor for ImportExportPage.
 */
ImportExportPage::~ImportExportPage() {
    delete ui;
}
