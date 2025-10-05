class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        return helper(piles,h);
    }
    
    int helper(vector<int>&nums,int h){
    int low=1;
    int ans;
    int high = *max_element(nums.begin(),nums.end());
    while(low<=high){
        int mid = low+(high-low)/2;
        long long hour=0;
        ans=0;
        for(int i=0;i<nums.size();i++){
            hour += ceil((double)nums[i] / mid);

        }
        if(hour<=h){
            high= mid-1;
            
        }
        else{
            low = mid+1;
        }
    }
    return low;
    
    }
       
};
