TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS += core \
           db \
           ui \
           translations \
           app

# Define dependency relationships
core.depends =

db.depends = core
ui.depends = core
translations.depends = core

app.depends = core db ui translations

# You can optionally include them directly too, if you want to generate from here:
# TRANSLATIONS += translations/i18n/ar.ts \
#                 translations/i18n/en.ts
