/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char arr1[]="Fizz";
char arr2[]="Buzz";
char arr3[]="FizzBuzz";
char** fizzBuzz(int n, int* returnSize) {
    char** ans = (char**) malloc(sizeof(char*) * n);
    int arr1_len,arr2_len,arr3_len;
    arr1_len=strlen(arr1) + 1;
    arr2_len=strlen(arr2) + 1;
    arr3_len=strlen(arr3) + 1;
    int i;
    for(i=1;i<=n;i++){
        if(i%15==0){
            ans[i-1] = (char*)malloc(sizeof(char)*arr3_len);
            snprintf(ans[i-1],arr3_len,"%s",arr3);
        }
        else if(i%5==0){
            ans[i-1] = (char*)malloc(sizeof(char)*arr2_len);
            snprintf(ans[i-1],arr2_len,"%s",arr2);
        }
        else if(i%3==0){
            ans[i-1] = (char*)malloc(sizeof(char)*arr1_len);
            snprintf(ans[i-1],arr1_len,"%s",arr1);
        }
        else{
            ans[i-1] = (char*)malloc(sizeof(int));
            snprintf(ans[i-1],20,"%d",i);
        }
    }
    *returnSize=n;
    return ans;
}
