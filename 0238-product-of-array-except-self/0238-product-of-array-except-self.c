/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    // 1. Set the return size and allocate memory for the result array
    *returnSize = numsSize;
    int* res = (int*)malloc(numsSize * sizeof(int));
    
    // 2. Calculate Prefix Products
    // res[i] will store the product of all elements to the left of i
    res[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        res[i] = res[i - 1] * nums[i - 1];
    }
    
    // 3. Calculate Suffix Products on the fly
    // We use a variable 'right' to track the product of all elements to the right of i
    int right = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        // Multiply the prefix product (already in res[i]) by the suffix product
        res[i] = res[i] * right;
        // Update the suffix product for the next element to the left
        right *= nums[i];
    }
    
    return res;
}