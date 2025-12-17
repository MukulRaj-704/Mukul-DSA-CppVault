class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m =grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;
        int count=0;
        vector<vector<int>>visited(m,vector<int>(n,0));
        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,+1,0,-1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'&& visited[i][j]==0){
                    visited[i][j]=1;
                    count++;
                    q.push({i,j});
        
                    while(!q.empty()){
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();
           
                
                    for(int k=0;k<4;k++){
                        int nr=r+drow[k];
                        int nc=c+dcol[k];
                        if(nr>=0&&nr<m&&nc>=0&&nc<n&& visited[nr][nc]==0&&grid[nr][nc]=='1'){
                            visited[nr][nc]=1;
                            q.push({nr,nc});
                            }
                        }
                    }

                }
            }
        }
        return count;
    }
};
