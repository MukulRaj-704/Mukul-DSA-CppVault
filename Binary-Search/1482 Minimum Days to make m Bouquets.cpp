class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
       if ((long long)m*k>n) return -1;

        int low =1;
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid = low + (high-low)/2;
            int bouquets=0;
            int count=0;
            for(int i:bloomDay){
                if (i <= mid) {
                    count++;
                    if (count == k) {
                        bouquets++;
                        count = 0;
                    }
                } 
                else {
                    count = 0;
                }

            }
            if(bouquets >= m)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};
