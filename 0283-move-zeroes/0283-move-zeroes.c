void moveZeroes(int* nums, int numsSize) {
    int insertPos = 0; 
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
           
            if (i != insertPos) {
                nums[insertPos] = nums[i];
                nums[i] = 0; 
            }
            insertPos++;
        }
    }
}