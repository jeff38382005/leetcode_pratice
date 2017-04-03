char findTheDifference(char* s, char* t) {
    int ss[26]={0};
    int tt[26]={0};
    int s_length = strlen(s);
    int t_length = s_length+1;
    int i;
    char ans;
    for(i=0;i<s_length;i++)
        ss[s[i]-'a'] +=1;
    for(i=0;i<t_length;i++)
        tt[t[i]-'a'] +=1;
    for(i=0;i<26;i++){
        if(ss[i]!=tt[i]){
            ans = i + 'a';
            break;
        }
    }
    return ans;
}

char findTheDifference(char* s, char* t) {
    int a = 0, b = 0;
    int i=0, j=0;
    while (s[i])
    {
        a ^= s[i];
        b ^= t[i];
        i++;
    }
    b ^= t[i];
    return a^b;
}
