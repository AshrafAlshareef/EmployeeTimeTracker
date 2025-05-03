// translations/translator.h
#pragma once

/**
 * @file translator.h
 * @brief Provides runtime language translation capabilities for the application.
 */

#include <QTranslator>
#include <QString>
#include <QLocale>
#include <QObject>

/**
 * @class Translator
 * @brief Loads and installs Qt translation files at runtime.
 */
class Translator : public QObject {
    Q_OBJECT

public:
    explicit Translator(QObject *parent = nullptr);

    /**
     * @brief Loads and applies a .qm file by language code (e.g., "en", "ar").
     * @param langCode Language code to load
     * @return true if loaded successfully
     */
    bool loadLanguage(const QString &langCode);

    /**
     * @brief Gets the currently loaded language code.
     * @return QString code like "en"
     */
    QString currentLanguage() const;

signals:
    /**
     * @brief Emitted when a new translation is loaded.
     */
    void languageChanged();

private:
    QTranslator _translator;
    QString _currentLang;
};
