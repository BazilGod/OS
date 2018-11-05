Set obj = CreateObject("Scripting.FileSystemObject")
Set WshShell = WScript.CreateObject ("WScript.Shell")
Set ObjEnv = WshShell.Environment("User")
ObjEnv("xcopy") = "XCOPY D:\5sem\os\3_laba\new_file.txt D:\5sem\os\3_laba\new_file_2.txt /Q"

WshShell.Run ObjEnv("xcopy")