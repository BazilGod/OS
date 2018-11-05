systeminfo > version.txt
find /I "BIOS" version.txt
del version.txt
ver | find "5.1." && echo XP
ver | find "6.1." && echo 7
pause