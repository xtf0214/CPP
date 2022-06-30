Sub 宏1()
'
' 宏1 宏
'
' 快捷键: Ctrl+Shift+S
'

    For i = 338 To 812
        k = 0
        Range("A" & CStr(i + 2)).Select
        If ActiveCell.FormulaR1C1 = "公办" Then
            Range("A" & CStr(i) & ":A" & CStr(i + 2)).Select
            With Selection
                .HorizontalAlignment = xlCenter
                .VerticalAlignment = xlCenter
                .Orientation = 0
                .AddIndent = False
                .IndentLevel = 0
                .ShrinkToFit = False
                .ReadingOrder = xlContext
                .MergeCells = False
            End With
            Selection.Merge
            k = 3
        End If
        Range("A" & CStr(i + 3)).Select
        If ActiveCell.FormulaR1C1 = "公办" Then
            Range("A" & CStr(i) & ":A" & CStr(i + 3)).Select
            With Selection
                .HorizontalAlignment = xlCenter
                .VerticalAlignment = xlCenter
                .Orientation = 0
                .AddIndent = False
                .IndentLevel = 0
                .ShrinkToFit = False
                .ReadingOrder = xlContext
                .MergeCells = False
            End With
            Selection.Merge
            k = 4
        End If
        i = i + k - 1
    Next i
        
        
    
End Sub
Sub 宏2()
'
' 宏2 宏
'
' 快捷键: Ctrl+a
'
    Range("M392").Select
    ActiveCell.FormulaR1C1 = "=1"
    Range("M393").Select
End Sub
