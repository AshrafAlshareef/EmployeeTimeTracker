#include "importexportpage.h"
#include "ui_importexportpage.h"

ImportExportPage::ImportExportPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ImportExportPage)
{
    ui->setupUi(this);
}

ImportExportPage::~ImportExportPage()
{
    delete ui;
}
