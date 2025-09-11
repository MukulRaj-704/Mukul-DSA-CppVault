class Solution {
  public:
    int maxSubarraySum(vector<int>& nums, int k) {
        // code here
         int sum=0;
        int maxsum = 0;
        int l=0;
        int r=0;
        while(r<k){
            sum = sum+ nums[r];
                r++;
        }
        maxsum = sum;
        while(r<nums.size()){
            sum=sum-nums[l];
            l++;
            sum=sum+nums[r];
            maxsum = max(maxsum,sum);
            r++;
        }
        return maxsum;
    }
};
