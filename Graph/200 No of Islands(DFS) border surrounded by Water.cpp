class Solution {
private:
    void dfs(int r, int c, vector<vector<int>>&visited, vector<vector<char>>&grid, int drow[], int dcol[]){
        visited[r][c]=1;
        int n=grid.size();
        int m = grid[0].size();
        for (int k = 0; k < 4; k++) {
            int nr = r + drow[k];
            int nc = c + dcol[k];
            if (nr>=0&& nr<n&&nc>= 0 && nc < m &&grid[nr][nc] == '1' && visited[nr][nc] == 0){
                dfs(nr,nc,visited,grid,dcol,drow);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int n= grid.size();
        int m=grid[0].size();
        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,+1,0,-1};
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    count++;
                    dfs(i,j,visited,grid,drow,dcol);
                }
            }
        }
        return count;
    }
};
