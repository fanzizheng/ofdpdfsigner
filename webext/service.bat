
@echo off

setlocal
set "CURRENT_DIR=%cd%"

if "x%1x" == "xx" goto displayUsage
if "x%1x" == "x-installx" goto install
if "x%1x" == "x-uninstallx" goto remove 


:install
rem if "x%2x" == "xx" goto displayUsage
rem set SERVICEPATH=%2
rem if not exist "%SERVICEPATH%\webext.exe" goto noServiceFile
rem sc create webext binPath="%SERVICEPATH%\webext.exe"
if not exist "%CURRENT_DIR%\webext.exe" goto noServiceFile
sc create webext binPath="%CURRENT_DIR%\webext.exe"
rem sc create webext binPath="%SERVICEPATH%"
sc config webext start= AUTO
net start webext
echo.
echo install service ok 
exit /b 1

:noServiceFile
echo.
echo not exist "%CURRENT_DIR%\webext.exe"
exit /b 1


:remove 
net stop webext
sc delete webext
echo.
echo remove service ok 
exit /b 1

:displayUsage
echo.
echo Usage: service.bat -install [path\webext.exe] / -uninstall 
exit /b 1