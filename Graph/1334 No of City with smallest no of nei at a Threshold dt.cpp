// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Your code here
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        for(auto it : edges){
            int u,v,w;
            u=it[0];
            v=it[1];
            w=it[2];
            dist[u][v]=w;
            dist[v][u]=w;
        }
          for (int k=0;k<n;k++) {
            for (int i=0;i<n;i++) {
                for (int j=0;j<n;j++) {
                    if (dist[i][k]<INT_MAX&&dist[k][j]<INT_MAX) {
                        dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        int citycnt=n;
        int cityno=-1;
        for(int city=0;city<n;city++){
            int cnt=0;
            for(int nei=0;nei<n;nei++){
                if(dist[city][nei]<=distanceThreshold){
                    cnt++;
                }
            }
                if(cnt<=citycnt){
                    citycnt=cnt;
                    cityno=city;
                
            }
        }
        return cityno;
    }
};
