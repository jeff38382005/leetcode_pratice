int getSum(int a, int b) {
    int sum=0,c;
    sum=a|b;
    c=a&b;
    while(c!=0){
      a=sum^c;
      b=c<<1;
      sum=a|b;
      c=a&b;
    }
    return sum;
}
