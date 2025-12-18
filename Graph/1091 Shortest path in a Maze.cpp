class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>>q;
        int n=grid.size();
        vector<vector<int>>visited(n,vector<int>(n,INT_MAX));
        if(grid[0][0]==1) return -1;
        if(grid[n-1][n-1]==1) return -1;
        q.push({0,{0,0}});
        int drow[]={-1,-1,0,1,1,1,0,-1};
        int dcol[]={0,1,1,1,0,-1,-1,-1};
        while(!q.empty()){
            int dt = q.front().first;
            int r= q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            if(r==n-1 && c==n-1) return dt+1;
            for(int i=0;i<8;i++){
                int nr=r+drow[i];
                int nc=c+dcol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n && visited[nr][nc]==INT_MAX && grid[nr][nc]==0){
                    q.push({dt+1,{nr,nc}});
                    visited[nr][nc]=dt+1;
                }
            }
        }
        if(visited[n-1][n-1]==INT_MAX) return -1;
        return visited[n-1][n-1];
    }
};
