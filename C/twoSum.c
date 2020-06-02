/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i, j;
    *returnSize = 0;
    int *res = (int *)malloc(sizeof(int) * 2);
    if(res == NULL) {
        return NULL;
    }
    for (i = 0; i < numsSize - 1; i++) {
        for (j = i + 1; j < numsSize; j++) {
            if (target == nums[i] + nums[j]) {
                res[0] = i;
                res[1] = j;

                *returnSize = 2;
                return res;
            }
        }
    }
    return res;
}

