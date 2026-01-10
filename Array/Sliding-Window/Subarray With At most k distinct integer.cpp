class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<int,int>freq;
        int left=0;int right=0; int count=0;
        for(right=0;right<n;right++){
            freq[arr[right]]++;
            while(freq.size()>k){
                freq[arr[left]]--;
                if(freq[arr[left]]==0){
                    freq.erase(arr[left]);
                    
                }
                left++;
            }
            count = count+(right-left+1);
        }
        return count;
    }
};
