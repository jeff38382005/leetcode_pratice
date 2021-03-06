int singleNumber(int A[], int n) {
    int result = 0;
    for (int i = 0; i<n; i++)
    {
		result ^=A[i];
    }
	return result;
}
//general
int singleNumber(int* nums, int numsSize) {
    // idea : iterate over all elements in array for every bit, get sum of all 1s,
    // bits with sum not multiple of 3, are 1's bit in the single occurance element
    // e.g. , 5,5,5,2 - 101 101 101 010 - 313 - answer is 3%3,1%3,3%3 - 010

    int x, res = 0;

    for(int i = 0; i < sizeof(int)*8; i++){
        x = 1 << i;
        int sum = 0;
        for(int j = 0; j < numsSize; j++){
            if(x & nums[j]) sum++;
        }

        if(sum % 3) res = res | x;
    }

    return res;
}
