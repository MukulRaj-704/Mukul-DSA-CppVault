class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int first=-1;
        int last=-1;
        int n=nums.size();
        int low=0;
        int high=n-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if( nums[mid]>=target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        if (low == n || nums[low] != target)
            return {-1, -1};
        first=low;
        low=0;
        high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        last=high;
        return {first,last};
    }
};
