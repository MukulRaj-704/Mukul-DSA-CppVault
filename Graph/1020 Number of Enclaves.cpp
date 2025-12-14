class Solution {
private:
    void dfs(int r, int c, vector<vector<int>>& visited, vector<vector<int>>&grid){
        int n= grid.size();
        int m = grid[0].size();
        visited[r][c]=1;
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        for(int i=0;i<4;i++){
            int nr= r+drow[i];
            int nc = c+ dcol[i];
            if(nr>=0 && nr<n&& nc>=0&& nc<m && visited[nr][nc]==0&& grid[nr][nc]==1){
            dfs(nr,nc,visited,grid);
        }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n= grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
         for(int j=0;j<m;j++){
            if(grid[0][j]==1 && visited[0][j]==0 ){
                dfs(0,j,visited,grid);
            }
            if(grid[n-1][j]==1&& visited[n-1][j]==0){
                dfs(n-1,j,visited,grid);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][0]==1&& visited[i][0]==0){
                dfs(i,0,visited,grid);
            }
            if(grid[i][m-1]==1 && visited[i][m-1]==0){
                dfs(i,m-1,visited,grid);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&& visited[i][j]==0){
                    count++;
                }
            }
        }
        return count;
    }
};
