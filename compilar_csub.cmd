@echo off

SET CSUB=decode
SET CDIR=csub

echo Compilando %CSUB%.c
arm-none-eabi-gcc -c -mcpu=cortex-m0 -mfloat-abi=soft -mthumb -ffunction-sections -fPIC -O3 -Wall -Wno-main -I. %CSUB%.c -o %CDIR%\%CSUB%.o
if errorlevel 1 pause & exit /b 1

echo Linkando %CSUB%.o
arm-none-eabi-gcc -nostartfiles -nostdlib -Wl,-T,%CDIR%\arm-gcc-link.ld -o %CDIR%\%CSUB%.elf %CDIR%\%CSUB%.o
if errorlevel 1 pause & exit /b 1

echo Conversion %CSUB% a CSUB para MMBASIC
bin\MMBasic %CDIR%\armcfgenV144.bas %CDIR%/%CSUB%.elf %CDIR%\%CSUB% -j
if errorlevel 1 pause & exit /b 1

echo Abriendo %CSUB%.bas
start notepad.exe %CDIR%\%CSUB%.bas

ping localhost -n 2 > nul
del %CDIR%\%CSUB%.o
del %CDIR%\%CSUB%.elf
del %CDIR%\%CSUB%.bas