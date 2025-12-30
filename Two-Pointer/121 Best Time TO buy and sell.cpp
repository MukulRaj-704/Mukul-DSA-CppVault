class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit=0;
        int sum=0;
        int low=0;
        int high = 1;
        while(high<n){
            sum=prices[high]-prices[low];
            profit=max(profit,sum);
            if(sum<0){
                sum = 0;
                low=high;
            }
            
            
                high=high+1;
        }
        return profit;
    }
};
