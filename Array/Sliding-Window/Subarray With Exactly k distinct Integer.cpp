class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        return helper(nums,k)-helper(nums,k-1);
    }
    int helper(vector<int>arr, int k){
        int n = arr.size();
        int left=0;int right=0;int count=0;
        unordered_map<int,int>freq;
        for(right=0;right<n;right++){
            freq[arr[right]]++;
            while(freq.size()>k){
                freq[arr[left]]--;
                if(freq[arr[left]]==0){
                    freq.erase(arr[left]);
                }
                left++;
            }
            count+= right-left+1;
        }
        return count;
    }
};
