cmake_minimum_required(VERSION 3.16)
project(EmployeeTimeTracker LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt libraries
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Sql LinguistTools)

# Translation files
set(TRANSLATION_TS
    translations/i18n/en.ts
    translations/i18n/ar.ts
)

qt6_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TRANSLATION_TS})

# UI files
set(UI_FILES
    mainwindow.ui
    ui/employeewidget.ui
    ui/employeeform.ui
)

# Source files
set(SOURCES
    main.cpp
    mainwindow.cpp
    ui/employeewidget.cpp
    ui/employeeform.cpp
    core/employee.cpp
    core/hourscalculator.cpp
    db/database.cpp
    translations/translator.cpp
)

# Header files
set(HEADERS
    mainwindow.h
    ui/employeewidget.h
    ui/employeeform.h
    core/employee.h
    core/hourscalculator.h
    db/database.h
    translations/translator.h
)

qt6_wrap_ui(WRAP_UI ${UI_FILES})

add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    ${WRAP_UI}
    ${QM_FILES}
)

# Link Qt modules
target_link_libraries(${PROJECT_NAME}
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Sql
)

# Define output directories
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
