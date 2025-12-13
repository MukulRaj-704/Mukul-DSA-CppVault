class Solution {
  private:
    bool dfs(int start, vector<int> &visited, vector<vector<int>> &adj, int parent){
        visited[start]=1;
            for(auto it : adj[start]){
                if(!visited[it]){
                    
                    if(dfs(it,visited,adj,start))
                    return true;
                }
                else if(it!=parent) return true;
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
        int parent=-1;
        if(dfs(i, visited, adj,-1)) return true;
    }
}
      return false;
    }
};
