#include <stdio.h>
#include <stdlib.h>

const int SIZE = 10;
const int NOVALUE = 0;

struct Queue {
    int head;
    int tail;
    int *arr;
    int size;
};

void init(struct Queue *q) {
    q -> head = 0;
    q -> tail = SIZE - 1;
    q -> size = SIZE;
    q -> arr = (int *)malloc(sizeof(int) * q -> size);
    int i;
    for(i = 0; i < q -> size; i++) {
        *(q -> arr + sizeof(int) * i) = NOVALUE;
    }       
}

void enqueue(struct Queue *q, int element) {
    if (q -> tail < q -> size -1) {
        int i;
        for (i = 1; i < q -> tail + 1; i++) {
            *(q -> arr + sizeof(int) * i) = *(q -> arr +  sizeof(int) * (i - 1));
        }
    }
    else {
        int i;
        int new_size = q -> size + SIZE;
        int *arr = (int *)malloc(sizeof(int) * new_size);
        for (i = 1; i < q -> tail + 1; i++) {
            *(arr + sizeof(int) * i) = *(q -> arr + sizeof(int) * (i - 1));
        }
    }
    *(q -> arr) = element;
    q -> tail ++;
}

int dequeue(struct Queue *q) {
    int ele = *(q -> arr + sizeof(int) * q -> tail);
    *(q -> arr + sizeof(int) * (q -> tail - 1)) = NOVALUE;
    q -> tail --;
    return ele;
}

int main() {
    struct Queue *q;
    int i;
    init(q);
    for (i = 0; i< 15; i++) {
        enqueue(q, 1);
    }
    for(i = 0; i < 15; i++ ) {
        printf("%d\n", dequeue(q));
    }

    return 0;
}
