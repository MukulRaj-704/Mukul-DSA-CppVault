class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it :times){
            int a,b,w;
            a=it[0];
            b=it[1];
            w=it[2];
            adj[a].push_back({b,w});
        }
        // we apply dijkstra's algorithm to fine the minimum time 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int>dist(n+1,INT_MAX);
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            int dt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(dt>dist[node]) continue;
            for(auto it: adj[node]){
                int vt=it.first;
                int wt=it.second;
                int ndt = dt+wt;
                if(ndt<dist[vt]){
                    pq.push({ndt,vt});
                    dist[vt]=ndt;
                }

            }
        }
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
