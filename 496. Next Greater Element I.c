/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* findNums, int findNumsSize, int* nums, int numsSize, int* returnSize) {
    if(numsSize == 0 || findNumsSize==0){
        *returnSize = 0;
         int *ans = (int*)malloc(sizeof(int)*(*returnSize));
         return ans;
    }
    int table[numsSize];
    int i,j,flag;
    for(i=0;i<numsSize;i++){
        flag=1;
        for(j=i+1;j<numsSize;j++){
            if(nums[j]>nums[i]){
                flag=0;break;
            }
        }
        if(flag) table[i]=-1;
        else table[i]=nums[j];
    }
    *returnSize = findNumsSize;
    int *ans = (int*)malloc(sizeof(int)*(*returnSize));
    for(i=0;i<findNumsSize;i++){
        for(j=0;j<numsSize;j++){
            if(findNums[i]==nums[j]){
                ans[i]=table[j];
                break;
            }
        }
    }
    return ans;
}


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* findNums, int findNumsSize, int* nums, int numsSize, int* returnSize) {
    int* returnArray = NULL;
    int* numsHash = NULL;

    *returnSize = findNumsSize;

    if(findNums != NULL && findNumsSize != 0 &&
       nums != NULL && numsSize != 0) {
        /* initalize the returnArray */
        returnArray = malloc((*returnSize) * sizeof(int));
        if(returnArray == NULL) {
            err(-1, "nextGreaterElement: line 17: malloc: out of space!");
        }

        /* find the max element in the nums */
        int max = 0;
        for(int i = 0; i < numsSize; i++) {
            if(max < nums[i]) {
                max = nums[i];
            }
        }

        /* initialize the numsHash */
        numsHash = malloc((max+1) * sizeof(int));
        if(numsHash == NULL) {
            err(-1, "nextGreaterElement: line 31: malloc: out of space!");
        }

        /* hash the nums' element to numsHash, the key is nums's element, */
        /* the velue is the next greater element, or -1 if does not exist */
        /* nums[numsSize-1] is the last element of nums, don't have next, */
        /* so set it to -1 directly */
        for(int i = 0; i < numsSize-1; i++) {
            numsHash[nums[i]] = -1;
            for(int j = i+1; j < numsSize; j++) {
                if(nums[j] > nums[i]) {
                    numsHash[nums[i]] = nums[j];
                    break;
                }
            }
        }
        numsHash[nums[numsSize-1]] = -1;

        /* find the next greater element */
        for(int i = 0; i < findNumsSize; i++) {
            returnArray[i] = numsHash[findNums[i]];
        }
    }

    return returnArray;
}
