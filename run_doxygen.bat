@echo off
REM Exécution de Doxygen avec le fichier de configuration Doxyfile

REM Vérifie si Doxygen est installé
where doxygen >nul 2>nul
if %errorlevel% neq 0 (
    echo Doxygen n'est pas installe ou le chemin n'est pas configure.
    pause
    exit /b
)

REM Exécuter Doxygen avec le fichier Doxyfile
doxygen Doxyfile

REM Vérifier si Doxygen a réussi
if %errorlevel% neq 0 (
    echo Une erreur est survenue lors de l'execution de Doxygen.
) else (
    echo Doxygen a ete execute avec succes.
)

pause
