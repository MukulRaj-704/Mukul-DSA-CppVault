class DisjointSet{
  public:
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extcab=0;
        for(auto it : connections){
            int u=it[0];
            int v=it[1];
            if(ds.findParent(u)==ds.findParent(v)){
                extcab++;
            }
            else{
                ds.unionByRank(u,v);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) count++;
        }
        if(extcab>=count-1) return count-1;
        return -1;
    }
};
