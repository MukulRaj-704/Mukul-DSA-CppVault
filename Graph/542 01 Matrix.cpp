class Solution {


public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<int,int>,int>>q;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    ans[i][j] = 0; 
                }
            }
        }
        
        while(!q.empty()){
            int r= q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();
            vector<int>drow={-1,0,+1,0};
            vector<int>dcol={0,+1,0,-1};
            for(int i=0;i<4;i++){
                int nr = r+ drow[i];
                int nc = c+ dcol[i];
                if(nr>=0&& nr<n&&nc>=0&&nc<m){
                    if(ans[nr][nc]==-1){
                        ans[nr][nc]=d+1;
                        q.push({{nr,nc},d+1});
                    }
                }
            }
        }
        return ans;
    }
};
