
// app/mainwindow.h
#pragma once

/**
 * @file mainwindow.h
 * @brief Declares the main application window for managing employees and their records.
 */

#include <AddEmployeePage.h>
#include <QMainWindow>
#include <QComboBox>
#include <QWidgetAction>
#include <QListWidgetItem>
#include <preferencespage.h>
#include <employeepage.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @class MainWindow
 * @brief Main dashboard window containing UI navigation and employee management.
 */
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onLanguageChanged(int index);
    void on_actionPreferences_triggered();
    void onEmployeeSelected(QListWidgetItem *item);
    void onAddEmployeeClicked();

private:
    Ui::MainWindow *ui; ///< Pointer to the UI
    QComboBox *_languageCombo = nullptr; ///< Language selector combo box
    PreferencesPage *preferencesPage = nullptr;
    EmployeePage *employeePage = nullptr;
    AddEmployeePage *addEmployeePage = nullptr;

    void loadEmployees();
};
