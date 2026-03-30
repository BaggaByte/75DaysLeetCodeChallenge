
#include <stdbool.h>
#include <stdlib.h>


typedef struct {
    int *data;
    int top;
} Stack;

Stack* createStack(int capacity) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->data = (int*)malloc(capacity * sizeof(int));
    s->top = -1;
    return s;
}

void stackPush(Stack* s, int x) {
    s->data[++(s->top)] = x;
}

int stackPop(Stack* s) {
    return s->data[(s->top)--];
}

int stackPeek(Stack* s) {
    return s->data[s->top];
}

bool stackEmpty(Stack* s) {
    return s->top == -1;
}

typedef struct {
    Stack* s1; // For pushing
    Stack* s2; // For popping/peeking
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
   
    obj->s1 = createStack(100);
    obj->s2 = createStack(100);
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    stackPush(obj->s1, x);
}

int myQueuePop(MyQueue* obj) {
    if (stackEmpty(obj->s2)) {
        while (!stackEmpty(obj->s1)) {
            stackPush(obj->s2, stackPop(obj->s1));
        }
    }
    return stackPop(obj->s2);
}

int myQueuePeek(MyQueue* obj) {
    if (stackEmpty(obj->s2)) {
        while (!stackEmpty(obj->s1)) {
            stackPush(obj->s2, stackPop(obj->s1));
        }
    }
    return stackPeek(obj->s2);
}

bool myQueueEmpty(MyQueue* obj) {
    return stackEmpty(obj->s1) && stackEmpty(obj->s2);
}

void myQueueFree(MyQueue* obj) {
    free(obj->s1->data);
    free(obj->s1);
    free(obj->s2->data);
    free(obj->s2);
    free(obj);
}