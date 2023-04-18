#include <stdio.h>

int main() {
    void mpsort(int [], int);
    int n;
    const int size = 1000;
    int L[size] = {};
    int n1;
    for(n = size - 1,n1 = 0; n >= 0 && n1 < size; n--,n1++){
        L[n1] = n;
    }
    mpsort(L, size);
    for(n = 0; n < size; n++) {
        printf("%d ", L[n]);
    }
    return 0;
}

void mpsort(int L[], int size) {
    int n;
    int count;
    int tmp;
    for (count = 0; count < size - 1; count ++) {
        for (n = 0; n < size - 1 - count; n++) {
            if (L[n] > L[n+1]) {
                tmp = L[n];
                L[n] = L[n+1];
                L[n+1] = tmp;
            }
        }
    }
}
