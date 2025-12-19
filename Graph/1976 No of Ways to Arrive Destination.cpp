class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int,int>>> adj(n);
        for(auto it :  roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        vector<long long>dist(n,LLONG_MAX);
        vector<int> ways(n, 0);
        priority_queue<pair<long long, int>,vector<pair<long long, int>>,
                greater<pair<long long, int>>>pq;
                   
        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;
        
        while(!pq.empty()){
            long long dt = pq.top().first;
            long long node = pq.top().second;
            pq.pop();
            if(dt>dist[node]) continue;
            for(auto it : adj[node]){
                int vt = it.first;
                long long wt = it.second;
                long long ndt = dt+wt;
                if (ndt < dist[vt]) {
                    dist[vt] = ndt;
                    ways[vt] = ways[node];
                    pq.push({ndt, vt});
                }
                else if (ndt == dist[vt]) {
                    ways[vt] = (ways[vt] + ways[node])%MOD;
                }
            }
        }
        return ways[n-1];
    }
};
