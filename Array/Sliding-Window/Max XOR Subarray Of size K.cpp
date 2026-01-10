class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        if (k > arr.size()) return 0;

        int n = arr.size();
        int maxi=INT_MIN;
        int mxor=0;
        for(int i=0;i<k;i++){
            mxor^=arr[i];
        }
        maxi=mxor;
        for(int i=k;i<n;i++){
            mxor^=arr[i-k];
            mxor^=arr[i];
            maxi=max(maxi,mxor);
        }
        return maxi;
    }
};
