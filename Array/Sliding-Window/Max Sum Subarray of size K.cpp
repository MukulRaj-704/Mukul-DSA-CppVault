class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int sum=0;
        int maxsum=0;
        if(k>n) return -1;
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        maxsum=sum;
        for(int i=k;i<n;i++){
            sum-=arr[i-k];
            sum+=arr[i];
            maxsum=max(sum,maxsum);
        }
        return maxsum;
    }
};
