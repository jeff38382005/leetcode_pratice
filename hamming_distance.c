/*My origin version*/


int hammingDistance(int x, int y) {
    int y_arr[100]={0};
    int x_arr[100]={0};
    int y_len=0;
    int x_len=0;
    int yo=y;
    int xo=x;
    int i,count;
    while(y>0){
            y_arr[y_len]=y%2;
            y_len++;
            y=y/2;
    }
    while(x>0){
        x_arr[x_len]=x%2;
        x_len++;
        x=x/2;
    }
    count = 0;
    if(xo>yo){
        for(i=0;i<x_len;i++){
            if(y_arr[i]!=x_arr[i])
            count++;
        }
    }
    else{
        for(i=0;i<y_len;i++){
            if(y_arr[i]!=x_arr[i])
            count++;
        }
    }
    return count;
}

//Leet code answer

int hammingDistance(int x, int y) {

    int tmpInt=x^y;
    int dis=0;

    while(tmpInt)
    {
        if((tmpInt>>1)<<1 != tmpInt)
        {
            ++dis;
        }

        tmpInt>>=1;
    }

    return dis;
}
