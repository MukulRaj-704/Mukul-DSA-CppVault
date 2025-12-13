class Solution {
  private:
    bool bfs(int start, vector<int> &visited, vector<vector<int>> &adj){
        visited[start]=1;
        queue<pair<int,int>>q;
        q.push({start,-1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto it : adj[node]){
                if(!visited[it]){
                    visited[it]=1;
                    q.push({it,node});
                }
                else if(it!=parent) return true;
            }
            
        }
    return false;
        
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
      vector<vector<int>> adj(V);
      for(int i=0;i<edges.size();i++){
          if(edges[i].size()<2) continue;
          int u,v;
          u=edges[i][0];
          v=edges[i][1];
          adj[u].push_back(v);
          adj[v].push_back(u);
          
      }
      vector<int>visited(V,0);
       for(int i=0;i<V;i++){
        if(!visited[i]){
          if(bfs(i, visited, adj)) return true;
    }
}
      return false;
    }
};
