class Solution {
  private:
  void dfs(int start, vector<int>&visited, vector<vector<int>>& adj,stack<int>&st){
      visited[start]=1;
      
      for(auto it : adj[start]){
          if(visited[it]==0){
              dfs(it,visited,adj,st);
          }
      }
      st.push(start);
  }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto it : edges){
            int u,v;
            u=it[0],
            v=it[1];
            adj[u].push_back(v);
        }
        stack<int> st;
        vector<int> visited(V,0);
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                dfs(i,visited,adj,st);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
