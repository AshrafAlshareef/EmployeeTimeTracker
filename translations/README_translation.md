## 🌍 Qt Translation System – Developer Guide

This file explains how translations are managed in the Employee Time Tracker application.

---

### 📁 Folder Structure

```
translations/
├── i18n/
│   ├── ar.ts       # Arabic source translations
│   ├── en.ts       # English source translations
│   ├── ar.qm       # Compiled runtime translation (generated)
│   └── en.qm       # Compiled runtime translation (generated)
├── translations.qrc
├── translations.pro
└── README_translation.md
```

---

### 📌 File Roles

| File Type | Description                         | Used in Code | Editable |
|-----------|-------------------------------------|--------------|----------|
| `.ts`     | Source translation (editable)       | ❌           | ✅ Qt Linguist |
| `.qm`     | Compiled translation (runtime only) | ✅           | ❌       |
| `.qrc`    | Embeds `.qm` files into binary      | ✅           | ✅       |
| `.pro`    | Translation project file            | ✅           | ✅       |

---

### 🔧 How to Update Translations

You can either use Qt tools manually or run the batch file.

#### 🛠 Manual (Recommended in Qt Creator terminal or Qt CMD):
```bash
lupdate translations.pro         # Update .ts files from code
lrelease translations.pro        # Compile .ts → .qm
```

#### ▶ Optional Batch File:
Use `run_update_translations.bat` (if present) to run both steps automatically.

---

### ✅ Loading in Code

Example (in `main.cpp` or `Translator` class):
```cpp
QTranslator translator;
translator.load(":/translations/ar.qm");
qApp->installTranslator(&translator);
```

Make sure `.qrc` contains:
```xml
<qresource prefix="/translations">
    <file>i18n/ar.qm</file>
    <file>i18n/en.qm</file>
</qresource>
```

---

This setup ensures all translations are embedded and loaded at runtime safely and cleanly.  
**Only `.qm` files are used in the application runtime.**
