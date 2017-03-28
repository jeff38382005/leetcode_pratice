int islandPerimeter(int** grid, int gridRowSize, int gridColSize) {
    int i,j,ans,count;
    ans = 0;
    for(i=0;i<gridRowSize;i++){
        for(j=0;j<gridColSize;j++){
            if(grid[i][j]==1){
                count = 0;
                if(i-1 >= 0) count = count+grid[i-1][j];
                if(j-1 >= 0) count = count+grid[i][j-1];
                if(i+1 < gridRowSize) count = count+grid[i+1][j];
                if(j+1 < gridColSize) count = count+grid[i][j+1];
                ans = ans + 4 - count;
            }
        }
    }
    return ans;
}


void dfs(int** grid,int rowsize,int colsize, int *ans, int row, int col){
    if(row<0 || col < 0 || row >= rowsize || col >= colsize || grid[row][col]!=1)
    return;
    grid[row][col] = -1;
    if(row-1<0 || grid[row-1][col] == 0) *ans=*ans+1;
    if(col-1<0 || grid[row][col-1] == 0) *ans=*ans+1;
    if(row+1 == rowsize || grid[row+1][col] == 0) *ans=*ans+1;
    if(col+1 == colsize || grid[row][col+1] == 0) *ans=*ans+1;
    dfs(grid,rowsize,colsize,ans,row-1,col);
    dfs(grid,rowsize,colsize,ans,row,col-1);
    dfs(grid,rowsize,colsize,ans,row+1,col);
    dfs(grid,rowsize,colsize,ans,row,col+1);
}
int islandPerimeter(int** grid, int gridRowSize, int gridColSize) {
    int i,j,count;
    int ans;
    ans = 0;
    for(i=0;i<gridRowSize;i++){
        for(j=0;j<gridColSize;j++){
            if(grid[i][j]==1){
                dfs(grid,gridRowSize,gridColSize,&ans,i,j);
                return ans;
            }
        }
    }
    return ans;
}
