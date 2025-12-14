class Solution {
  private:
    bool dfs(int start, vector<int>& visited, vector<int>& pathvis, vector<vector<int>>& adj){
        visited[start]=1;
        pathvis[start]=1;
        for(auto it : adj[start]){
            if(!visited[it]){
               if(dfs(it,visited,pathvis,adj)==true) return true;
            }
            else if( visited[it]==1 && pathvis[it]) return true;
        }
        
        pathvis[start]=0;
        return false;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }

        vector<int> visited(V,0);
        vector<int> pathvis(V,0);
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                if(dfs(i,visited,pathvis,adj)==true){
                    return true;
                }
            }
        }
        return false;
    }
};
