class Solution {
private:
    bool dfs(int start, vector<int>& visited, vector<int>& pathvis, vector<vector<int>>& graph, vector<int>& check){
        int n = graph.size();
        visited[start]=1;
        pathvis[start]=1;
        for(auto it : graph[start]){
            if(visited[it]==0){
               if( dfs(it,visited,pathvis,graph,check)==true){
                return true;
               }
            }
            else if( pathvis[it]==1) return true;
        }

        check[start]=1;
        pathvis[start]=0;
        return false;

    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> visited(V,0);
        vector<int>pathvis(V,0);
        vector<int>check(V,0);
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                dfs(i,visited, pathvis,graph, check);
            }
        }
        for(int i=0;i<V;i++){
            if(check[i]==1) ans.push_back(i);
        }
        return ans;
    }
};
