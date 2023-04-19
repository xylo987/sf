def f(l):
    n = 0
    m = 1
    sl = 1

    while m < len(l):
        n = 0
        while n < sl:
            if l[m] < l[n]:
                g = m
                tmp = l[m] 
                while g > n:
                    l[g] = l[g-1]
                    g -= 1
                l[n] = tmp
                sl += 1
                break
            n += 1        
        m += 1
    return l

L = [x for x in range(1000)]
L.reverse()
print(f(L))

#time 0.124
