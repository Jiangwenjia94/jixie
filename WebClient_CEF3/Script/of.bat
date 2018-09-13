@echo off
set "str=HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\App Paths\soffice.exe"
for /f "tokens=2*" %%a in ('reg query "%str%" /v Path 2^>nul') do set "a=%%b"
set "c=program"
set "d=%a%%c%"
cd /d %d%
start soffice -headless -accept="socket,host=127.0.0.1,port=8100;urp;" -nofirststartwizard  
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Run" /v of /d "%~dp0of.bat" /f