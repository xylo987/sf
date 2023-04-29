#include <stdio.h>
#include <stdlib.h>

const int SIZE = 10;
const int NOVALUE = 0;

struct Queue {
    int tail;
    int *arr;
    int size;
};

void init(struct Queue *q) {
    q -> tail = -1;
    q -> size = SIZE;
    q -> arr = (int *)malloc(sizeof(int) * q -> size);
    if (q -> arr == NULL){
        printf("内存申请失败");
        exit(-1);
    }
    int i;
    for(i = 0; i < q -> size; i++) {
        *(q -> arr + sizeof(int) * i) = NOVALUE;
    }       
}

void enqueue(struct Queue *q, int element) {
    int i;
    if (q -> tail < q -> size -1) {
        for (i = q -> tail + 1; i > 0; i--) {
            *(q -> arr + sizeof(int) * i) = *(q -> arr +  sizeof(int) * (i - 1));
        }
    }
    else {
        int new_size = q -> size + SIZE;
        int *arr = (int *)malloc(sizeof(int) * new_size);
        for (i = q -> tail + 1; i > 0; i--) {
            *(arr + sizeof(int) * i) = *(q -> arr + sizeof(int) * (i - 1));
        }
        q -> size = new_size;
        free(q -> arr);
        q -> arr = arr;
    }
    *(q -> arr) = element;
    q -> tail ++;
}

int dequeue(struct Queue *q) {
    if (q -> tail == -1) {
        printf("queue is empty");
        exit(-1);
    }
    else {
        int ele = *(q -> arr + sizeof(int) * q -> tail);
        if (q -> tail >= 0)
            *(q -> arr + sizeof(int) * q -> tail) = NOVALUE;

        q -> tail --;
        return ele;
    }
}

void clear(struct Queue *q) {
    free(q -> arr);
    q = NULL;
}

int main() {
    struct Queue q;
    int i, size;
    size = 13;
    init(&q);
    for (i = 0; i < size; i++) {
        enqueue(&q, i);
    }
    for(i = 0; i < size; i++) {
        printf("%d\n", dequeue(&q));
    }
    return 0;
}
