#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int* answer = (int*)calloc(temperaturesSize, sizeof(int));
    int* stack = (int*)malloc(temperaturesSize * sizeof(int));
    int top = -1; 
    
    for (int i = 0; i < temperaturesSize; i++) {
        while (top >= 0 && temperatures[i] > temperatures[stack[top]]) {
            int prev_index = stack[top]; 
            answer[prev_index] = i - prev_index; 
            top--; 
        }
        
        top++;
        stack[top] = i;
    }
    
    *returnSize = temperaturesSize; 
    free(stack); 
    
    return answer;
}