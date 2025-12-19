// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        vector<int>dist(100000,1e9);
        queue<pair<int,int>>q;
        q.push({0,start});
        dist[start]=0;
        int MOD=100000;
        while(!q.empty()){
            int step = q.front().first;
            int node = q.front().second;
            q.pop();
            if (node == end) return step;
            for(auto it : arr){
                int num = (node*it)%MOD;
                if(step+1<dist[num]){
                    dist[num]=step+1;
                   
                    q.push({step+1,num});
                }
            }
            
        }
        return -1;
    }
};
