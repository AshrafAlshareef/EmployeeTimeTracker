# EmployeeTimeTracker

✅ Program Overview

A Qt C++ desktop application using QWidgets to track and manage employees' working hours. The application is used by an accountant/admin on the company's main PC. It provides a dashboard layout and supports future multi-language expansion (Arabic and English).

🧩 High-Level Structure
🗂️ Modules / Libraries

1. UI Layer (Qt Designer .ui files + code):

    - Main Dashboard

    - Employee Page (embedded view)

    - Import/Export Windows (dedicated embedded or side panels)

2. Database Layer (Custom Library):

    - MySQL Server connection for main storage

    - SQLite for offline caching & unsaved records

    - Auto-sync from SQLite to MySQL when online

3. Working Hours Logic Library:

    - Track sessions: start, stop

    - Calculate daily, weekly, monthly hours

    - Handle edits and validations

4. Translation System:

    - .ts files using translation keys (e.g., menu.file.import)

    - QTranslator for dynamic UI language switching

🧭 UI Layout and Interaction
📌 Main Window Layout (3-column dashboard)
Column 1	        Column 2	            Column 3
- Employees list	- Employee List View	- Employee Detail / Edit / Add
- [+] Add Employee		
- Language selector	



👤 Employee Page
    - Embedded view only (no modal)

    - Sections:

        - Start Working / Stop Working buttons

        - Working hours totals:

            - Today 
            - This week
            - This month

        - Editable table of working sessions

        - Buttons:
            - Export Records
            - Import Records

🔄 Import/Export Functionality
- Import Window
    - File format: CSV / JSON

    - Import:

        - All Employees

        - Single Employee

    - Preview data before committing to DB

    - Buttons: [Browse...], [Preview Import], [Start Import], [Cancel]

- Export Window
    - File format: CSV / JSON

    - Export:
        -All Employees
        - Selected Employee (via dropdown)

    - Buttons: [Browse location...], [Start Export], [Cancel]

🌐 Language Support

- Dynamic language switching in-app (via menu or sidebar dropdown)

- .ts files for Arabic and English

- All labels/texts tied to translation keys

🔐 Data Safety & Reliability

- Auto-save to SQLite if MySQL is offline

- Background thread to sync data once online

- Import preview protects DB integrity

- All edits user-confirmed and trackable