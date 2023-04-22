Imports System

Module Program
    Function kssort(L as Integer(), p as Integer, r As Integer)
        If p < r
            Dim q as Integer = partition(L, p, r)
            kssort(L, p, q - 1)
            kssort(L, q + 1, r)
        End If
    End Function

    Function partition(L as Integer(), p as Integer, r as Integer)
        Dim i as Integer = p - 1
        Dim j as Integer = p
        Dim x as Integer = L(r)
        While j < r
            If L(j) <= x
                i = i + 1                            
                exchange(L, i, j)
            End If
            j = j + 1
        End While
        exchange(L, i + 1 , r)
        print(L)
        Return i + 1
    End Function   

    Function exchange(L as Integer(), i as Integer, j as Integer)                                                     
        Dim tmp as Integer = L(i)
        L(i) = L(j)
        L(j) = tmp
    End Function

    Function print(L as Integer()) 
        Dim i = 0
        While i < L.Length
            If i = L.length - 1
                Console.Write(L(i))
            Else
                Console.Write(L(i))
                Console.Write(",")
            End If
            i = i + 1
        End While
        Console.WriteLine()
    End Function
    
    Sub Main(args As String())
        Dim r as Integer = 9
        Dim L(r) as Integer
        Dim i as Integer = 0
        Dim v as Integer = 10
        While v > 0 
            L(i) = v
            i = i + 1
            v = v - 1
        End While

        kssort(L, 0, r)
        print(L)
    End Sub
End Module