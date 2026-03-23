#include <stdlib.h>


int compare(const void* a, const void* b) {
    int int_a = *((int*)a);
    int int_b = *((int*)b);
    
    // Avoid integer overflow that can happen with (int_a - int_b)
    if (int_a < int_b) return -1;
    if (int_a > int_b) return 1;
    return 0;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0; // Initialize the number of found triplets to 0
    if (numsSize < 3) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    // 1. Sort the array to easily handle duplicates and use two pointers
    qsort(nums, numsSize, sizeof(int), compare);

    // Initial allocation capacity for the results
    int capacity = 1024;
    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));

    // 2. Iterate through the array
    for (int i = 0; i < numsSize - 2; i++) {
        // Optimization: If the current number is strictly positive, 
        // the sum can never reach 0 since the array is sorted.
        if (nums[i] > 0) break;

        // Skip duplicate elements for the first number of our triplet
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        // 3. Set up two pointers
        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            
            if (sum == 0) {
                // Resize arrays if we hit our capacity limit
                if (*returnSize == capacity) {
                    capacity *= 2;
                    result = (int**)realloc(result, capacity * sizeof(int*));
                    *returnColumnSizes = (int*)realloc(*returnColumnSizes, capacity * sizeof(int));
                }
                
                // Allocate memory for the triplet
                result[*returnSize] = (int*)malloc(3 * sizeof(int));
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                
                // Record the column size (always 3 for this problem)
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                // Skip duplicates for the second and third numbers
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                // Move both pointers inward
                left++;
                right--;
            } 
            else if (sum < 0) {
                // Sum is too small, move left pointer right to increase sum
                left++;
            } 
            else {
                // Sum is too large, move right pointer left to decrease sum
                right--;
            }
        }
    }
    
    return result;
}