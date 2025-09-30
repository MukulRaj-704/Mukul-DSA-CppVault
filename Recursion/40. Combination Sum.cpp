class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidate, int target) {
        vector<vector<int>> result;
        sort(candidate.begin(), candidate.end());
        vector<int>ans;
        int index=0;
        helper(0,target,ans,result,candidate);
        return result;
    }
    void helper(int index, int target, vector<int>&arr, vector<vector<int>>&res,vector<int>&candidate){
        if(target == 0){
            res.push_back(arr);
            return ;
        }
        if(target<0){
            return ;
            
        }
        int n = candidate.size();
        for(int i=index;i<n;i++){
             if (i > index && candidate[i] == candidate[i - 1]) continue;
            arr.push_back(candidate[i]);
            helper(i+1,target-candidate[i],arr,res,candidate);
            arr.pop_back();
        }
    }
};
