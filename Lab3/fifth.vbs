'Processor Information
On Error Resume Next
Message =""
strComputer = "."
Set objWMIService = GetObject("winmgmts:" _
& "{impersonationLevel=impersonate}!\\" & strComputer & "\root\cimv2")

Set colItems = objWMIService.ExecQuery("Select * from Win32_Processor")

For Each objItem in colItems
Message=Message & "�������: " & objItem.CurrentClockSpeed & vbCrLf
Message=Message & "�����������: " & objItem.DataWidth& vbCrLf
Message=Message & "��������: " & objItem.Description& vbCrLf
Message=Message & "���������: " & objItem.Family& vbCrLf
Message=Message & "������ ���: " & objItem.L2CacheSize& vbCrLf
Message=Message & "������� ��������: " & objItem.LoadPercentage& vbCrLf
Message=Message & "�������������: " & objItem.Manufacturer& vbCrLf
Message=Message & "����� ����������: " & objItem.ProcessorId& vbCrLf
Message=Message &"������: " & objItem.Version & vbCrLf
Next

Set crt = CreateObject("Scripting.FileSystemObject")
Set file = crt.CreateTextFile("D:\5sem\os\3_laba\info_fifth_task.txt")

file.WriteLine(Message)
file.close