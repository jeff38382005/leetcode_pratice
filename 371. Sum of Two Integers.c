int getSum(int a, int b) {
    int sum;
    int over;
    sum = a | b;
    over = a & b;
    while(over!=0){
        int temp,temp2;;
        temp = sum ^ over;
        temp2 = over << 1;
        sum = temp | temp2;
        over = temp & temp2;
    }
    return sum;
}
