class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int ans;
        int high = *max_element(nums.begin(), nums.end());
        while(low<=high){
            int mid = low+(high-low)/2;
            int divisorsum =0;
            for(int i : nums){
                divisorsum += ceil((double)i/mid);
            }
            if(divisorsum<=threshold){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
            
        }
        return low;
    }
    
};
