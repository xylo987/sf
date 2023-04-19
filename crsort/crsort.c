#include <stdio.h>

int main() {
    void crsort(int [], int);
    int L[1000] = {};
    int size = 1000;
    int i = 0;
    int v = 1000;
    while (i < size) {
        L[i] = v--;
        i ++;
    }
    crsort(L, size);
    for (i = 0; i < size; i++) {
        printf("%d ", L[i]);
    }
    /*time 0.008*/
    return 0;
}

void crsort(int L[], int size) {
    int n;
    int m = 1;
    int sl = 1;
    int tmp;
    int g;
    while (m < size) {
        n = 0;
        while (n < sl) {
            if (L[m] < L[n]) {
                tmp = L[m];
                g = m;
                while (g > n) {
                    L[g] = L[g-1];
                    g --;
                }
                L[n] = tmp;
                sl ++;
                break;
            }
            n ++;
        }
        m ++;
    }
}
