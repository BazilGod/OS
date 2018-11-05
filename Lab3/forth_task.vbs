Set fso=WScript.CreateObject("Scripting.FileSystemObject")
Set shell = WScript.CreateObject("WScript.Shell")
Set ObjEnv = Shell.Environment("Process")

Set file=fso.CreateTextFile("D:\5sem\os\3_laba\start_excel.bat")
file.WriteLine("start Excel.exe")
file.Close
ObjEnv("start_bat") = "D:\5sem\os\3_laba\start_excel.bat"

shell.Run ObjEnv("start_bat")

