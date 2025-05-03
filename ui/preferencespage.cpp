// ui/preferencespage.cpp
#include "preferencespage.h"
#include "ui_preferencespage.h"

/**
 * @brief Constructs the PreferencesPage and sets up the UI.
 */
PreferencesPage::PreferencesPage(QWidget *parent)
    : QWidget(parent), ui(new Ui::PreferencesPage) {
    ui->setupUi(this);
}

/**
 * @brief Destructor for PreferencesPage.
 */
PreferencesPage::~PreferencesPage() {
    delete ui;
}
