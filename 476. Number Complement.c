int findComplement(int num) {
    int a[100];
    int i; int num_length=0; int count=2; int ans=0;
    while(num>0){
        a[num_length]=(num%2+1)%2;
        num_length++;
        num=num/2;
    }
    for(i=1;i<num_length;i++){
        ans = ans + a[i]*count;
        count = count * 2;
    }
    ans = ans + a[0];
    return ans;
}
int findComplement(long num) {
    long i;
    for(i=1;i<=num;i*=2) num^=i;
    return num;
}
