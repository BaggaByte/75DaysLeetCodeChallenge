#include <stdio.h>

double findMaxAverage(int* nums, int numsSize, int k) {
    
    double current_sum = 0;
    for (int i = 0; i < k; i++) {
        current_sum += nums[i];
    }

    double max_sum = current_sum;

    
    for (int i = k; i < numsSize; i++) {
        
        current_sum += nums[i] - nums[i - k];
        
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }


    return max_sum / k;
}