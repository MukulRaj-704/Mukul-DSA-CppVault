// User function Template for C++
class Solution {
    void dfs(int r,int c, vector<vector<int>>&visited, vector<vector<int>>&matrix,
    int drow[], int dcol[]){
        int n =matrix.size();
        int m= matrix[0].size();
        visited[r][c]=1;
        for(int i=0;i<4;i++){
            int nr= r+drow[i];
            int nc = c+dcol[i];
            if(nr>=0&& nr<n && nc>=0 && nc<m && visited[nr][nc]==0 && matrix[nr][nc]==1){
                dfs(nr,nc,visited,matrix,drow,dcol);
            }
        }
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        vector<vector<int>>matrix(n,vector<int>(m,0));
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        vector<int>ans;
        for(auto it : operators){
            int count=0;
            vector<vector<int>>visited(n,vector<int>(m,0));
            int a,b;
            a=it[0];
            b=it[1];
            matrix[a][b]=1;
            //matrix[b][a]=1;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(matrix[i][j]==1 && visited[i][j]==0){
                        count++;
                        dfs(i,j,visited,matrix,drow,dcol);
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
