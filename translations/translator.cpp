// translations/translator.cpp
#include "translator.h"
#include <QApplication>

Translator::Translator(QObject *parent) : QObject(parent) {}

bool Translator::loadLanguage(const QString &langCode) {
    QString file = ":/i18n/" + langCode + ".qm";
    if (_translator.load(file)) {
        qApp->installTranslator(&_translator);
        _currentLang = langCode;
        emit languageChanged();
        return true;
    }
    return false;
}

QString Translator::currentLanguage() const {
    return _currentLang;
}
