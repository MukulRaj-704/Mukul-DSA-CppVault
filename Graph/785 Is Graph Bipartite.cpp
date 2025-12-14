class Solution {
private:
    bool bfs(int start,vector<int>&visited, vector<vector<int>>& graph){
        int n = graph.size();
        queue<pair<int,int>>q;
        q.push({start,0});
        while(!q.empty()){
            int node = q.front().first;
            int color = q.front().second;
            q.pop();
            for(auto it: graph[node]){
                if(visited[it]==-1){
                    if(color==0){
                        visited[it]=1;
                        q.push({it,1});
                    }
                    else{
                        visited[it]=0;
                        q.push({it,0});
                    }
                }
                else if( color == visited[it]) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
      int v = graph.size();
      vector<int> visited(v,-1);
      //queue<pair<int,int>>q;

      for(int i=0;i<v;i++){
        if(visited[i]==-1){
            //q.push({i,0});
            if(!bfs(i,visited,graph)) return false;
        }
      }  
      return true;
    }
};
