Imports System

Module Program
    Function crsort(L as Integer(), size as Integer) 
        Dim n as Integer
        Dim m as Integer = 1
        Dim sl as Integer = 1
        Dim tmp as Integer
        Dim g as Integer
        While m < size
            n = 0
            While n < sl
                If L(m) < L(n)
                    tmp = L(m)
                    g = m
                    While g > n
                        L(g) = L(g-1)
                        g = g - 1
                    End While
                    L(n) = tmp
                    sl = sl + 1
                    Exit While
                End If
                n = n + 1
            End While
            m = m + 1
        End While
    End Function

    Sub Main(args As String())
        Dim L(999) as Integer 
        Dim i as Integer = 0
        Dim size as Integer = 1000
        Dim v as Integer = 1000
        While i < size
            L(i) = v
            v = v - 1
            i = i + 1
        End While
        crsort(L, size)
        i = 0
        While i < size
            Console.WriteLine(L(i))
            i = i + 1
        End While
        'time 0.087
    End Sub
End Module
