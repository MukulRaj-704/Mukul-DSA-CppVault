class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidate, int target) {
        vector<vector<int>> result;
        vector<int>ans;
        int index=0;
        helper(index,target,ans,result,candidate);
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
            arr.push_back(candidate[i]);
            helper(i,target-candidate[i],arr,res,candidate);
            arr.pop_back();
        }
    }
};
