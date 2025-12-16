class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        queue<pair<int,int>>q;
        vector<int>visited(V,0);
        vector<int>distance(V,INT_MAX);
        vector<vector<int>>adj(V);
        for(auto it : edges){
            int u,v;
            u=it[0];
            v= it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        q.push({src,0});
        visited[src]=1;
        distance[src]=0;
        while(!q.empty()){
            int node = q.front().first;
            int dist=q.front().second;
            q.pop();
            for(auto it : adj[node]){
                if(visited[it]==0){
                    visited[it]=1;
                    distance[it]=dist+1;
                    q.push({it,dist+1});
                }
                else if(distance[it]>dist+1){
                    distance[it]=dist+1;
                    q.push({it,dist+1});
                }
            }
        }
        for(int i=0;i<V;i++){
            if(distance[i]==INT_MAX){
                distance[i]=-1;
            }
        }
        return distance;
    }
};
