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
