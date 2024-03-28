#include <stdio.h>
#include <stdlib.h>

int* buildArray(int* nums, int numsSize, int* returnSize) {
    int* arr = (int*)malloc(numsSize * sizeof(int)); 
    for (int i = 0; i < numsSize; i++){
        arr[i] = nums[nums[i]];
    }
    *returnSize = numsSize;
    return arr;
}

int main (void){
    int nums [] = {0,2,1,5,3,4}; 
    int returnSize;
    int* result = buildArray(nums, sizeof(nums)/sizeof(nums[0]), &returnSize);
    for(int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    free(result);
    return 0;
}