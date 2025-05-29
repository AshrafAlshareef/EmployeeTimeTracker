// app/mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "translator.h"
#include "appsettings.h"
#include "employeedataaccessobject.h"
#include "employee.h"
#include <QInputDialog>

#include <workrecorddataaccessobject.h>


/**
 * @brief Constructs the main window and sets up UI elements.
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Load saved language and set initial selection
    QString savedLang = AppSettings::instance().languageCode();


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

    connect(ui->listEmployees, &QListWidget::itemClicked,
            this, &MainWindow::onEmployeeSelected);

    connect(ui->btnAddEmployee, &QPushButton::clicked,
            this, &MainWindow::onAddEmployeeClicked);

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
        AppSettings::instance().setLanguageCode(langCode);
        // No need to call retranslateUi here anymore
    }
    // if using .ui file:
    ui->retranslateUi(this); // FIXME: do i realy need this here
}


void MainWindow::on_actionPreferences_triggered()
{
    // preferencesPage
    if (!preferencesPage) {
        preferencesPage = new PreferencesPage(this);
    }
    centralWidget()->layout()->addWidget(preferencesPage);
    preferencesPage->show();
}



void MainWindow::loadEmployees() {
    QList<QVariantMap> employees = EmployeeDataAccessObject::fetchEmployees();
    for (const QVariantMap &emp : employees) {
        int id = emp["id"].toInt();
        QString name = emp["name"].toString();
        // Add to UI (e.g., list widget or table)
        ui->listEmployees->addItem(QString("%1 - %2").arg(id).arg(name));
    }
}



void MainWindow::onEmployeeSelected(QListWidgetItem *item) {
    if (!item) return;

    // Extract ID (format: "123 - John Doe")
    QString text = item->text();
    int id = text.section(" - ", 0, 0).toInt();
    QString name = text.section(" - ", 1);

    // Build employee object
    Employee emp(id, name);

    // Load work records
    QList<QVariantMap> rawRecords = WorkRecordDataAccessObject::fetchRecordsForEmployee(id);
    for (const QVariantMap &rec : rawRecords) {
        WorkRecord wr;
        wr.id = rec["id"].toInt();
        wr.startTime = rec["start_time"].toDateTime();
        wr.endTime = rec["end_time"].toDateTime();
        emp.addWorkRecord(wr);
    }

    // Create or update EmployeePage
    if (!employeePage) {
        employeePage = new EmployeePage(this);
        centralWidget()->layout()->addWidget(employeePage);
    }
    employeePage->setEmployee(emp);
    employeePage->show();
}


void MainWindow::onAddEmployeeClicked()
{
    // addEmployeePage
    if (!addEmployeePage) {
        addEmployeePage = new AddEmployeePage(this);
    }
    centralWidget()->layout()->addWidget(addEmployeePage);
    addEmployeePage->show();


    // bool ok;
    // QString name = QInputDialog::getText(this, tr("Add Employee"),
    //                                      tr("Employee Name:"), QLineEdit::Normal,
    //                                      "", &ok);
    // if (ok && !name.trimmed().isEmpty())
    // {
    //     int id = -1;
    //     bool success = EmployeeDataAccessObject::insertEmployee(name.trimmed(), &id);
    //     if (success) {
    //         ui->listEmployees->addItem(QString("%1 - %2").arg(id).arg(name));
    //     } else {
    //         qWarning() << "Failed to insert employee.";
    //     }
    // }
}
