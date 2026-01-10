class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        long long prexor=0;
        long long count=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<n;i++){
            prexor=prexor^arr[i];
            int target=prexor^k;
            if(mp.find(target)!=mp.end()){
                count=count+mp[target];
            }
            mp[prexor]++;
        }
        return count;
    }
};
