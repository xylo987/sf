def mpsort(L):
    _len = len(L)
    tmp = None
    count = 0
    while count < _len - 1:
        n = 0
        while n < _len - 1 - count:
            if L[n] > L[n+1]:
                tmp = L[n]
                L[n] = L[n+1]
                L[n+1] = tmp
            n += 1
        count += 1


L = [n for n in range(1000)]
L.reverse()
mpsort(L)
print(L)
