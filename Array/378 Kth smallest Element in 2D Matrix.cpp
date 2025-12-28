class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        int n=mat.size();
        int low=mat[0][0];
        int high=mat[n-1][n-1];
        while(low<=high){
            int mid=low+(high-low)/2;
            int count=0;
            int i=0;int j=n-1;
            while(i<n && j>=0){
                if(mat[i][j]>mid){
                    j--;
                }
                else{
                    i++;
                    count=count+j+1;
                }
            }
            
            if(count<k) low=mid+1;
            else high = mid-1;
        }
        return low;
    }
};
