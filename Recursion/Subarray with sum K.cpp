class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int index = 0;
       
        return  helper(nums,k,0);
    }
    int helper(vector<int>&nums, int target, int index){
            if(index>=nums.size()){
                return 0;

            }
            int count=0;
            int sum=0;
            for(int i = index;i<nums.size();i++){
               sum=sum+nums[i];
               if(sum==target) count++;
            }
            return count+ helper(nums,target,index+1);
    }
};
