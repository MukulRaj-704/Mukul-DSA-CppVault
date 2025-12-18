class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>
> pq;

        vector<int>dist(V,INT_MAX);
        vector<vector<pair<int,int>>>adj(V);
        pq.push({0,src});
        dist[src]=0;
        for(auto it: edges){
            int a,b,w;
            a=it[0];
            b=it[1];
            w=it[2];
            adj[a].push_back({b,w});
            adj[b].push_back({a,w});
        }
        while(!pq.empty()){
            int dt=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if (dt > dist[node]) continue;

            for(auto it:adj[node]){
                int vt=it.first;
                int wt=it.second;
                int ndt=dt+wt;
                if(ndt<dist[vt]){
                    dist[vt]=ndt;
                    pq.push({ndt,vt});
                }
                
            }
            
        }
        return dist;
    }
};
