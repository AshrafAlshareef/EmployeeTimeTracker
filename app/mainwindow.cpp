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
    _languageCombo->addItem("🌐 English", "en");
    _languageCombo->addItem("🌐 Arabic", "ar");

    // Create widget action for menu bar
    QWidgetAction *langAction = new QWidgetAction(this);
    langAction->setDefaultWidget(_languageCombo);
    ui->menuLanguage->addAction(langAction);

    // Set initial language selection
    int index = _languageCombo->findData(savedLang);
    if (index != -1) _languageCombo->setCurrentIndex(index);

    connect(_languageCombo, &QComboBox::currentIndexChanged, this, [=](int index) {
        QString langCode = _languageCombo->itemData(index).toString();
        extern Translator translator;
        translator.loadLanguage(langCode);
        AppSettings settings;
        settings.setLanguageCode(langCode);
    });
}

/**
 * @brief Destructor for MainWindow.
 */
MainWindow::~MainWindow() {
    delete ui;
}
