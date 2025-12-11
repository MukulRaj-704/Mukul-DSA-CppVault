class Solution {
  private:
    void dfs(int node, vector<vector<int>> &adj, vector<int>& ans, vector<int>& visited){
        visited[node]=1;
        ans.push_back(node);
        for(auto it : adj[node]){
            if(visited[it]==0){
                dfs(it, adj, ans, visited);
            }
        }
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> ans;
        vector<int> visited(n,0);
        dfs(0,adj,ans,visited);
        return ans;
    }
};
