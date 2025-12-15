class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites){
            int u,v;
            u=it[0],
            v=it[1];
            adj[v].push_back(u);
        }
        queue<int>q;
        vector<int> indeg(numCourses,0);
        vector<int> visited(numCourses,0);
        vector<int>ans;
        for(int i=0;i<numCourses;i++){
            for(auto it : adj[i]){
                indeg[it]++;
            }
        }
        int V=numCourses;
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

    if(ans.size()==V) return ans;
    return {};
    }
    
};
