#include "translator.h"
#include <QApplication>

Translator::Translator(QObject *parent) : QObject(parent) {}

Translator& Translator::instance() {
    static Translator instance;
    return instance;
}

bool Translator::loadLanguage(const QString &langCode) {
    QString file = ":/translations/i18n/" + langCode + ".qm";
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
