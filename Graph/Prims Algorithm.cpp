class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        priority_queue<pair<int, pair<int,int>>,
                vector<pair<int, pair<int,int>>>,greater<pair<int, pair<int,int>>>>pq;
                vector<int> visited(V,0);
                vector<vector<pair<int,int>>>adj(V);
                pq.push({0,{0,-1}});
                //visited[0]=0;
                int sum=0;
                for(auto it: edges){
                    adj[it[0]].push_back({it[1],it[2]});
                    adj[it[1]].push_back({it[0],it[2]});
                }
                while(!pq.empty()){
                    int dt=pq.top().first;
                    int node=pq.top().second.first;
                    int parent=pq.top().second.second;
                    pq.pop();
                    if(visited[node]==0){
                        visited[node]=1;
                        sum+=dt;
                        for(auto it : adj[node]){
                            int vt=it.first;
                            int wt= it.second;
                            if(!visited[vt]){
                                pq.push({wt,{vt,node}});
                            }
                            
                        }
                    }
                }
                return sum;
    }
};
