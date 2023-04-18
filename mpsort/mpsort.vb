Module Program
    Function BubbleSort(ByVal Ar As Array)
        Dim i As Integer
        Dim j As Integer
        Dim Temp                    '不定义变量类型,以自动适应数组Ar的类型
        Dim Flag As Boolean
        Dim n As Integer = Ar.Length - 1
        For i = 1 To n
            Flag = False
            '从第1个元素开始,比较每两个相邻元素的大小,让大元素下沉,小元素上浮
            '经过一轮循环,可使数组中最大元素下沉到数组最底部
            '进入下一轮循环,只对前 n - i 个元素进行相邻比较(已排到后面的不用比较)
            For j = 0 To n - i 
                If Ar(j) > Ar(j + 1) Then 
                    Temp = Ar(j)
                    Ar(j) = Ar(j + 1)
                    Ar(j + 1) = Temp
                    Flag = True         '如果有排序行为，则设为 True
                End If
            Next
            If Flag = False Then   '如未排序,说明已完成整个排序过程,退出
                Exit For
            End If
        Next
    End Function
    
    Sub Main(args As String())
        Dim A(1000) As Integer
        Dim size = 1000
        Dim n = size
        while n > 0
            A(n) = n
            n = n - 1
        End While
        BubbleSort(A)   '结果会是{2,4,5,6,7,9,11}
        For index = 0 To A.GetUpperBound(0)
            Console.WriteLine(A(index))
        Next
        'Dim B() As String= {"DD","GG","CC","FF","JJ","AA","BB"} 
        'BubbleSort(B)   '结果会是{"AA","BB","CC","DD","FF","GG","JJ"}
    End Sub
End Module
