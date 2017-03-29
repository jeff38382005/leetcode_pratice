/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
     int * ans = (int*)malloc(sizeof(int) * numsSize);
     memset(ans,0,sizeof(ans));

     int i;
     for(i=0;i<numsSize;i++){
         ans[nums[i]]++;
     }
     ans[0]=1;
     for(i=0;i<numsSize;i++){
         if(ans[i]==0){
             ans[ans[0]]=i;
             ans[0]++;
         }
     }
     *returnSize = ans[0]-1;
     return &ans[1];
}
