class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n= nums.size();
      int low,mid,high;
      low=0;high =n-1;mid=0;
      while(mid<=high){
        if(nums[mid]==0){
            swap(nums[mid],nums[low]);
            low++;
            mid++;
        }
        else if(nums[mid]==1){
            mid++;
        }
        else{
            swap(nums[mid],nums[high]);
            
            high--;
        }
      }
    }
};
