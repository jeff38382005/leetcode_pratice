/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int maps[]={2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3};
int get_line(char ch){
    if(ch >= 'a' && ch <= 'z')
    return maps[ch-'a'];
    else
    return maps[ch-'A'];
}
char** findWords(char** words, int wordsSize, int* returnSize) {
    char ** ans = (char**)malloc(sizeof(char *) * wordsSize);
    *returnSize = 0;
    int i,j,check,row_num;
    for (i=0;i<wordsSize;i++){
        int word_length=strlen(words[i]);
        check = 1;
        row_num=get_line(words[i][0]);
        for(j=1;j<word_length;j++){
            if(row_num!=get_line(words[i][j]))
            {check=0;break;}
        }
        if(check){
            ans[*returnSize] = malloc(sizeof(char) * (word_length + 1));
            snprintf(ans[*returnSize], word_length + 1, "%s", words[i]);
            (*returnSize)++;
        }
    }
    return ans;
}
