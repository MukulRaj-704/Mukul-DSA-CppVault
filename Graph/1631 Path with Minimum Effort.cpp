 int n= mat.size();
        int m= mat[0].size();
        priority_queue<pair<pair<int,int>,int>,
              vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>>pq;
        vector<vector<int>>visited(n,vector<int>(m,1e9));
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        visited[0][0]=0;
        pq.push({{0,0},0});
        while(!pq.empty()){
            int r=pq.top().first.first;
            int c=pq.top().first.second;
            int diff=pq.top().second;
            pq.pop();
           
            for(int i=0;i<4;i++){
                int nr=r+drow[i];
                int nc=c+dcol[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int ndiff = max(diff,abs(mat[r][c]-mat[nr][nc]));
                    if(ndiff<visited[nr][nc]){
                    pq.push({{nr,nc},ndiff});
                    visited[nr][nc]=ndiff;
                    }
                }
            }
        }
        return visited[n-1][m-1];
