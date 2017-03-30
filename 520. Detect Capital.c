bool detectCapitalUse(char* word) {
    int len = strlen(word);
    int i,flag1,flag2;
    for(i=0;i<len;i++){
        if(i==0){
            flag1=(int)word[i]-'a';
        }
        else if(i==1){
            flag2=(int)word[i]-'a';
            if(flag1>=0 && flag2>=0) flag1 = -1;
            else if(flag1 < 0 && flag2 >=0) flag1 = -1;
            else if(flag1 < 0 && flag2 < 0) flag1 = 1;
            else return false;
        }
        else{
            if(flag1 < 0 && (int)word[i]-'a' < 0) return false;
            if(flag1 > 0  && (int)word[i]-'a' >= 0) return false;
        }
    }
    return true;
}

bool detectCapitalUse(char* word) {
    int count = 0, first = 0;

    for (int i = 0; i < strlen(word); i++) {
        if (i == 0 && isupper(word[i])) {
            first = 1;
            count++;
        }
        else if (isupper(word[i])) {
            count++;
        }
    }

    if (count == strlen(word) || count == 0) return true;
    else if (first == 1 && count == 1) return true;
    else return false;
}
