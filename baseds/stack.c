#include <stddef.h>
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

struct Stack * init() {
    struct Stack s, *s1;
    s.top = -1;
    s.size = SIZE;
    s.arr = NULL;
    s.arr = (int *)malloc(s.size * sizeof(int));
    if (s.arr == NULL) {
        printf("内存申请失败");
        exit(-1);
    }
    s1 = &s;
    return s1;
}

enum TrueOrFalse empty(struct Stack *s) {
    if (s -> top == -1)
        return True;
    else
        return False;
}

enum TrueOrFalse push(struct Stack *s, int *element) {
    if ((s -> size - 1) == s -> top) {
    }
    else {
        if (True == empty(s)) {
            s -> arr = element;
        }
        else {
            s -> arr ++;
            s -> arr = element;
        }
        s -> top ++;
    }
    return True;
}

int *pop(struct Stack *s) {
    if (empty(s) == False) {
        int *ele = s -> arr;
        s -> arr = s -> arr - sizeof(int);
        s -> top --;
        return ele;
    }
    else {
        printf("栈已空");
        exit(-1);
    }
}

int main() {
    struct Stack *s = init();
    int element = 100;
    int e1 = 101;
    enum TrueOrFalse tf = push(s, &element);
    push(s, &e1);
    printf("push return: %d\n", tf);
    printf("%d\n", empty(s));
    printf("%d\n", *pop(s));
    printf("%d\n", *pop(s));
    return 0;
}
