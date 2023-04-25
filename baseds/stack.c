#include <stdio.h>
#include <stdlib.h>

const int SIZE = 10;

enum TrueOrFalse {
    True = 1,
    False = 0
};

struct Stack {
    int top;
    int *arr;
    int size; 
};

void init(struct Stack *s) {
    s -> top = -1;
    s -> size = SIZE;
    s -> arr = NULL;
    s -> arr = (int *)malloc(s -> size * sizeof(int));
    if (s -> arr == NULL) {
        printf("内存申请失败");
        exit(-1);
    }
}

enum TrueOrFalse empty(struct Stack *s) {
    if (s -> top == -1)
        return True;
    else
        return False;
}

enum TrueOrFalse push(struct Stack *s, int element) {
    if ((s -> size - 1) == s -> top) {
        int *arr = (int *)malloc(sizeof(int) * s -> size + SIZE);
        int i;
        for (i = 0; i < s -> size; i++) {
            *(arr + sizeof(int) * i) = 1;
        }
    }
    else {
        if (True == empty(s)) {
            *(s -> arr) = element;
        }
        else {
            *(s -> arr + sizeof(int) * (s -> top + 1)) = element;
        }
        s -> top ++;
    }
    return True;
}

int pop(struct Stack *s) {
    if (empty(s) == False) {
        int ele;
        ele = *(s -> arr + (s -> top * sizeof(int)));
        *(s -> arr + (s -> top * sizeof(int))) = 0;
        s -> top --;
        return ele;
    }
    else {
        printf("栈已空");
        exit(-1);
    }
}

void clear(struct Stack *s) {
    free(s -> arr);
    s = NULL;
}

int main() {
    struct Stack s;
    init(&s);
    int e0 = 100;
    int e1 = 101;
    int e2 = 102;
    push(&s, e0);
    push(&s, e1);
    push(&s, e2);

    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));

    clear(&s);
    return 0;
}
