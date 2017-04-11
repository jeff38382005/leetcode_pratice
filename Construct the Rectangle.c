/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructRectangle(int area, int* returnSize) {
    int i;
    int width;
    int length;
    int min,max,max_min,t_min,t_max;
    max_min=99999999;
    for(i=1;i<=sqrt(area);i++){
        if(area%i==0){
            t_min = i;
            t_max = area/i;
            if(t_max-t_min < max_min){
                max_min = t_max-t_min;
                min = i;
                max = area/i;
            }
        }
    }
    *returnSize = 2;
    int *ans;
    ans = (int*)malloc(sizeof(int)*2);
    ans[0] = max;
    ans[1] = min;
    return ans;
}
