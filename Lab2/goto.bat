chcp 1251
@echo off
:n
set /p DEPT1="[Warning]: ttttt?  [y/n]"
if /i not defined DEPT1 (cls& goto n)
if /i "%DEPT1%"=="y" (echo yes& goto d)
if /i "%DEPT1%"=="n" (echo yes& goto n)
Echo Дружок-пирожок тобой неправильно сделан выбор & pause& cls& goto n
:d
set /p DEPT2="[Warning]: y![y]"
if /i not defined DEPT2 (cls& goto n)
if /i "%DEPT2%"=="y" (echo yes& goto m)
:m
pause