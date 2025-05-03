// ui/preferencespage.h
#pragma once

/**
 * @file preferencespage.h
 * @brief Declares the PreferencesPage widget for user settings.
 */

#include <QWidget>

namespace Ui {
class PreferencesPage;
}

/**
 * @class PreferencesPage
 * @brief Widget for editing application preferences like language and database connection.
 */
class PreferencesPage : public QWidget {
    Q_OBJECT

public:
    explicit PreferencesPage(QWidget *parent = nullptr);
    ~PreferencesPage();

private:
    Ui::PreferencesPage *ui; ///< Pointer to the UI definition
};
