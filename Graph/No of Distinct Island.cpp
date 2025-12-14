class Solution {
  private:
    void dfs(int r, int c,int row0, int col0, vector<vector<int>>&visited, vector<vector<int>>& grid,vector<int>&drow, vector<int>& dcol,set<vector<pair<int,int>>>&s, vector<pair<int,int>>& vec){
        visited[r][c]=1;
        int n=grid.size();
        int m=grid[0].size();
        vec.push_back({r-row0, c-col0});
        for(int i=0;i<4;i++){
            int nr = r+drow[i];
            int nc = c+dcol[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]== 1 && visited[nr][nc]==0){
                dfs(nr,nc,row0,col0,visited,grid,drow,dcol,s,vec);
            }
        }
        
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        set<vector<pair<int,int>>>s;
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<int> drow ={-1,0,1,0};
        vector<int> dcol ={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && visited[i][j]==0){
                    vector<pair<int,int>> vec;
                    dfs(i,j,i,j,visited,grid,drow, dcol,s, vec);
                    s.insert(vec);
                }
            }
        }
        return s.size();
    }
};
