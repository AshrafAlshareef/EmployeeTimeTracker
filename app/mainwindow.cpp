// app/mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "translator.h"
#include "appsettings.h"


/**
 * @brief Constructs the main window and sets up UI elements.
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Load saved language and set initial selection
    AppSettings settings;
    QString savedLang = settings.languageCode();


    // Create and configure language combo box
    _languageCombo = new QComboBox(this);
    _languageCombo->addItem(tr("🌐 English"), "en");
    _languageCombo->addItem(tr("🌐 Arabic"), "ar");


    // Create widget action for menu bar
    QWidgetAction *langAction = new QWidgetAction(this);
    langAction->setDefaultWidget(_languageCombo);
    ui->menuLanguage->addAction(langAction);

    // Set initial language selection
    int index = _languageCombo->findData(savedLang);
    if (index != -1) _languageCombo->setCurrentIndex(index);

    connect(_languageCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onLanguageChanged);

    connect(&Translator::instance(), &Translator::languageChanged, this, [=]() {
        ui->retranslateUi(this);
    });
}

/**
 * @brief Destructor for MainWindow.
 */
MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onLanguageChanged(int index)
{
    QString langCode = _languageCombo->itemData(index).toString();
    if (Translator::instance().loadLanguage(langCode)) {
        AppSettings settings;
        settings.setLanguageCode(langCode);
        // No need to call retranslateUi here anymore
    }
    // if using .ui file:
    // ui->retranslateUi(this);
}
