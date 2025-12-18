class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
       
        vector<vector<pair<int,int>>>adj(V);
        vector<int>dist(V,INT_MAX);
        set<pair<int,int>>st;
        st.insert({0,src});
        dist[src]=0;
        for(auto it: edges){
            int a,b,w;
            a=it[0];
            b=it[1];
            w=it[2];
            adj[a].push_back({b,w});
            adj[b].push_back({a,w});
        }
        while(!st.empty()){
            auto bt = *(st.begin());
            int dt=bt.first;
            int node=bt.second;
            st.erase(bt);
            if (dt > dist[node]) continue;

            for(auto it:adj[node]){
                int vt=it.first;
                int wt=it.second;
                int ndt=dt+wt;
                if(ndt<dist[vt]){
                    if(dist[vt]!=INT_MAX){
                        st.erase({dist[vt],vt});
                    }
                    
                    dist[vt]=ndt;
                    st.insert({ndt,vt});
                    
                }
                
            }
            
        }
        return dist;
    }
};
