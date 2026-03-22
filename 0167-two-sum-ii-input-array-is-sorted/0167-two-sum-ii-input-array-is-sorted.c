/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    // 1. Allocate memory for the result array (size 2)
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    // 2. Initialize two pointers
    int left = 0;
    int right = numbersSize - 1;

    // 3. Process the array
    while (left < right) {
        int currentSum = numbers[left] + numbers[right];

        if (currentSum == target) {
            // Found the pair! Convert to 1-based indexing
            result[0] = left + 1;
            result[1] = right + 1;
            return result;
        } else if (currentSum < target) {
            // Sum is too small, move left pointer to increase sum
            left++;
        } else {
            // Sum is too large, move right pointer to decrease sum
            right--;
        }
    }

    // Per constraints, exactly one solution exists, 
    // so we will always return from inside the loop.
    return result;
}