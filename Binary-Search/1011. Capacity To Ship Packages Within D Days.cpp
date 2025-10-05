class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        return helper(weights, days);
    }
    int helper(vector<int>& nums, int days){
        int low=*max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid = low+(high-low)/2;
            int day=1;
            int sum=0;
            for(int i = 0;i<nums.size();i++){
               
                if(sum+nums[i]>mid){
                    day++;
                    sum=0;
                   
                }
                sum+=nums[i];
            }
            if(day<=days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
