#pragma once

#include <QDialog>

namespace Ui {
class PreferencesPage;
}

class PreferencesPage : public QDialog
{
    Q_OBJECT

public:
    explicit PreferencesPage(QWidget *parent = nullptr);
    ~PreferencesPage();

private:
    Ui::PreferencesPage *ui;
};
