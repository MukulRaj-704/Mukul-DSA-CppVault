class Solution {
  private:
    void dfs(int r, int c, vector<vector<int>>&visited, vector<vector<char>>& grid,vector<int>&drow, vector<int>& dcol){
        visited[r][c]=1;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<8;i++){
            int nr = r+drow[i];
            int nc = c+dcol[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='L' && visited[nr][nc]==0){
                dfs(nr,nc,visited,grid,drow,dcol);
            }
        }
        
    }
  public:
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<int> drow ={-1,-1,0,1,1,1,0,-1};
        vector<int> dcol ={0,1,1,1,0,-1,-1,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='L' && visited[i][j]==0){
                    count++;
                    dfs(i,j,visited,grid,drow, dcol);
                }
            }
        }
        return count;
    }
};
