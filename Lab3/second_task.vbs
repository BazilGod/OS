Set obj = CreateObject("Scripting.FileSystemObject")
Set WshShell = WScript.CreateObject ("WScript.Shell")
Set ObjEnv = WshShell.Environment("User")
ObjEnv("new_file") = "notepad.exe D:\5sem\os\3_laba\new_file.txt" 
WshShell.Run ObjEnv("new_file")

