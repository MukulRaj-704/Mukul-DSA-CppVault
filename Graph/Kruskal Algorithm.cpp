class DisjointSet{
  private:
    vector<int> rank, parent;
  public:
    DisjointSet(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }
    
    int findParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }
    
    void unionByRank(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        
        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }
        else if(rank[pv] < rank[pu]){
            parent[pv] = pu;
        }
        else{
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};
class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>>& edges) {
        // code here
        sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b){return a[2] < b[2];});
        int mstwt = 0;
        DisjointSet ds(V);
        
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            if(ds.findParent(u) != ds.findParent(v)){
                mstwt += wt;
                ds.unionByRank(u, v);
            }
        }
        return mstwt;
    }
};
