@echo off
echo === Setting up Qt environment ===

REM CALL Qt's environment setup script (adjust this path!)
CALL "C:\Qt\6.8.0\mingw_64\bin\qtenv2.bat"

echo === Updating and compiling translations ===

REM Navigate to your project directory
cd /d %~dp0

REM Update and compile translations
lupdate EmployeeTimeTracker.pro
lrelease translations\translations.pro

echo === Done ===
pause
