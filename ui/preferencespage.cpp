#include "preferencespage.h"
#include "ui_preferencespage.h"
#include "../core/appsettings.h"
#include "../translations/translator.h"

PreferencesPage::PreferencesPage(QWidget *parent)
    : QWidget(parent), ui(new Ui::PreferencesPage) {
    ui->setupUi(this);

    AppSettings &settings = AppSettings::instance();

    ui->editHost->setText(settings.databaseHost());
    ui->spinPort->setValue(settings.databasePort());
    ui->editDatabase->setText(settings.databaseName());
    ui->editUser->setText(settings.databaseUser());
    ui->editPassword->setText(settings.databasePassword());
    ui->comboLanguage->setCurrentText(settings.languageCode());

    connect(ui->btnSave, &QPushButton::clicked, this, [this]() {
        AppSettings &settings = AppSettings::instance();

        settings.setDatabaseHost(ui->editHost->text());
        settings.setDatabasePort(ui->spinPort->value());
        settings.setDatabaseName(ui->editDatabase->text());
        settings.setDatabaseUser(ui->editUser->text());
        settings.setDatabasePassword(ui->editPassword->text());

        QString newLang = ui->comboLanguage->currentText();
        if (newLang != settings.languageCode()) {
            settings.setLanguageCode(newLang);
            emit Translator::instance().languageChanged();  // Make sure PreferencesPage declares this signal
        }
    });

    // TODO:
    // Optional: reset to config values, add reset button to UI if needed
    // connect(ui->btnReset, &QPushButton::clicked, this, [this]() { ... });
    // Reset button functionality
}

PreferencesPage::~PreferencesPage() {
    delete ui;
}
