char* reverseString(char* s) {
    int length = strlen(s);
    int i,j;
    char temp;
    j=0;
    for(i=length-1;i>=0;i--){
    if(j>i) break;
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    j++;
    }
    return s;
}
