Dim FSO, file
Set FSO = CreateObject("Scripting.FileSystemObject")
Set file = FSO.CreateTextFile("1.bat", true)
file.WriteLine ("@echo off")
file.WriteLine ("set n=0 1 2 3 4 5 6 7 8 9 ")
file.WriteLine ("set f=7")
file.WriteLine ("for %%x in (%n%) do (")
file.WriteLine ("for %%y in (%f%) do (")
file.WriteLine ("color %%x%%y")
file.WriteLine ("  timeout 2 >nul")
file.WriteLine ("    )")
file.WriteLine (")")
file.Close
WScript.CreateObject("Wscript.Shell").Run "1.BAT", 1, vbTrue