#include <stdlib.h>
#include <math.h>


typedef struct Node {
    int val;
    int min;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} MinStack;


MinStack* minStackCreate() {
    MinStack* stack = (MinStack*)malloc(sizeof(MinStack));
    stack->top = NULL;
    return stack;
}

void minStackPush(MinStack* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    
   
    if (obj->top == NULL) {
        newNode->min = val;
    } else {
        int currentMin = obj->top->min;
        newNode->min = (val < currentMin) ? val : currentMin;
    }
    
    newNode->next = obj->top;
    obj->top = newNode;
}

void minStackPop(MinStack* obj) {
    if (obj->top == NULL) return;
    
    Node* temp = obj->top;
    obj->top = obj->top->next;
    free(temp);
}

int minStackTop(MinStack* obj) {
    return obj->top->val;
}

int minStackGetMin(MinStack* obj) {
    return obj->top->min;
}

void minStackFree(MinStack* obj) {
    while (obj->top != NULL) {
        minStackPop(obj);
    }
    free(obj);
}