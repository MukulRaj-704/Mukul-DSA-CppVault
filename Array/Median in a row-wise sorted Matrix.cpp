class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int k = ((m*n)/2)+1;
        int low = INT_MAX, high = INT_MIN;
        for (int i = 0; i < n; i++) {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][m - 1]);
        }
        int ans =0;
        while(low<=high){
            int mid = low+(high-low)/2;
            int i=0;
            int j=m-1;
            int count=0;
            for (int i = 0; i < n; i++) {
                count += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            }
            
            if (count<k){
                low=mid+1;
                
            }
            else{
                ans = mid;
                high=mid-1;
            }
            
            
        }
        
        return ans;
    }
};
