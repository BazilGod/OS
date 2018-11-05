@echo off

FOR %%A IN (a,c,d) DO dir %%A:*.*

FOR %%f IN (*.txt) DO type %%f 
pause