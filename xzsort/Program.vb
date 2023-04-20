Imports System

Module Program
    Function xzsort(L as Integer(), size As Integer)
        ' [5,4,3,2,1]
        ' [1, 4,3,2,5] 交换 5,1
        ' [1,2, 3,4,5]      4,2
        ' [1,2,3, 4, 5]      
        ' [1,2,3,4,5 ]
        Dim n as Integer = 0
        Dim m as Integer
        Dim min_id as Integer
        Dim tmp as Integer
        While n < size
            m = n + 1
            While m <= size
                If L(m) < L(n) 
                    min_id = m
                End If
                m = m + 1
            End While
            If min_id <> -1
                tmp = L(n)
                L(n) = L(min_id)
                L(min_id) = tmp    
            End If
            n = n + 1
            min_id = -1
        End While
    End Function

    Sub Main(args As String())
        Dim L(1000) as Integer
        Dim size as Integer = 999
        Dim i as Integer = 1000
        Dim j as Integer = 0
        While j <= size
            L(j) = i
            i = i - 1
            j = j + 1
        End While
        xzsort(L, size)
        i = 0
        While i <= size
            Console.Write(L(i))
            Console.Write(",")
            i = i + 1
        End While
    End Sub
End Module
