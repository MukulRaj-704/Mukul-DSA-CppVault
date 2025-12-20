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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int>mapNode;
        for(int i=0;i<n;i++){
            for(int j=1;j < accounts[i].size();j++){// start j from one because we need to find overlappin
                string mail =  accounts[i][j];          // of mail and the   first is name 
                if(mapNode.find(mail)==mapNode.end()){
                    mapNode[mail]=i;
                }
                else{
                    ds.unionByRank(i,mapNode[mail]);
                }

            }
        }

        vector<vector<string>>mergemail(n);
        for (auto &it : mapNode) {
            string mail = it.first;
            int parent = ds.findParent(it.second);
            mergemail[parent].push_back(mail);
        }

        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mergemail[i].empty()) continue;
            sort(mergemail[i].begin(),mergemail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it :mergemail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
