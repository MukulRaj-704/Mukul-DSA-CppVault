class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto it : edges){
            int u,v;
            u=it[0],
            v=it[1];
            adj[u].push_back(v);
        }
        queue<int>q;
        vector<int> indeg(V,0);
        vector<int> visited(V,0);
        vector<int>ans;
        for(int i=0;i<V;i++){
            for(auto it : adj[i]){
                indeg[it]++;
            }
        }
        
        for(int i=0;i<V;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }

    if(ans.size()==V) return true;
    return false;
    }
};
