#pragma once

/**
 * @file translator.h
 * @brief Singleton providing runtime language translation capabilities.
 */

#include <QTranslator>
#include <QString>
#include <QObject>

/**
 * @class Translator
 * @brief Singleton for managing translation loading and switching.
 */
class Translator : public QObject {
    Q_OBJECT

public:
    static Translator& instance(); // Singleton accessor

    Q_DISABLE_COPY(Translator) // Disable copy/assignment

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
    Translator(QObject *parent = nullptr); ///< Private constructor

    QTranslator _translator;
    QString _currentLang;
};
