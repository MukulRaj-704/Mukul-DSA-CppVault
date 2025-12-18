// User function Template for C++
class Solution {
  private:
    void toposort(int start, vector<int>&visited, 
                    vector<vector<pair<int,int>>>&adj,stack<int>&st){
                        visited[start]=1;
                        for(auto it: adj[start]){
                            int node = it.first;
                            if(visited[node]==0){
                                toposort(node,visited,adj,st);
                            }
                        }
                        st.push(start);
                    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<int>visited(V,0);
        stack<int>st;
        vector<vector<pair<int,int>>>adj(V);
        vector<int>dist(V,INT_MAX);
        for(auto it: edges){
            int a,b,w;
            a=it[0];
            b=it[1];
            w=it[2];
            adj[a].push_back({b,w});
        }
        for(int i=0;i<V;i++){
            if(visited[i]==0){
            toposort(i,visited,adj,st);
            }
        }
        dist[0]=0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(dist[node]!=INT_MAX){
                for(auto it: adj[node]){
                    int vt=it.first;
                    int wt=it.second;
                    int dt = dist[node]+wt;
                    if(dt<dist[vt]){
                        dist[vt]=dt;
                        }
                    }
                }
            }
        for(int i=0;i<V;i++){
            if(dist[i]==INT_MAX) dist[i]=-1;
            }
        return dist;
    }
};
