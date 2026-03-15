#include <stdlib.h>

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int i;
    
    
    for(i = 0; i < numsSize; i++) {
        int index = abs(nums[i]) - 1;
        if(nums[index] > 0) {
            nums[index] = -nums[index];
        }
    }

    
    int* result = (int*)malloc(numsSize * sizeof(int));
    int count = 0;

    for(i = 0; i < numsSize; i++) {
        if(nums[i] > 0) {
            result[count++] = i + 1;
        }
    }

    *returnSize = count;
    return result;
}