// User function Template for C++
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        int ans=n;
        auto it= lower_bound(arr.begin(),arr.end(),x);
        if(it!=arr.end()) {
            ans= it-arr.begin();
            return ans;
        }
        return -1;
    }
};
