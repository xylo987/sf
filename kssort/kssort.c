#include <stdio.h>

int main() {
    void kssort(int [], int, int);
    void print(int [], int);
    void init(int [], int, int);
    const int size = 1000;
    int L[size];
    init(L, size, 1000);
    kssort(L, 0, size - 1);
    print(L, size);
    return 0;
}

void init(int L[], int size, int v) {
    int i;
    for (i = 0; i < size; i ++) {
        L[i] = v--;
    }
}

void print(int L[], int size) {
    int i;
    for (i = 0; i < size; i ++) {
        if (i == size - 1)
            printf("%d", L[i]);
        else
            printf("%d,", L[i]);
    }
}

void kssort(int L[], int p, int r) {
    int partition(int [], int ,int);
    int q;
    if (p < r) {
        q = partition(L, p, r);
        kssort(L, p, q - 1);
        kssort(L, q + 1, r);
    }
}

int partition(int L[], int p, int r) {
    void exchange(int [], int ,int);
    int i = p - 1;
    int j;
    int x = L[r];
    for (j = p; j < r; j++) {
        if (L[j] < L[r]) {
            i ++;
            exchange(L, i, j);
        }
    }
    i ++;
    exchange(L, i, r);
    return i;
}

void exchange(int L[], int i, int j) {
    int tmp = L[i];
    L[i] = L[j];
    L[j] = tmp;
}
