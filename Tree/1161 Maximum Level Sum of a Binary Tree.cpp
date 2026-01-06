/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        TreeNode* curr=root;
        queue<pair<TreeNode*,int>>q;
        q.push({curr,1});
        int maxi=INT_MIN;
        int ans=1;
        while(!q.empty()){
            int size=q.size();
                int sum=0;
                int level=0;
                for(int i=0;i<size;i++){

                    TreeNode* temp=q.front().first;
                     level=q.front().second;
                    q.pop();
                    sum+=temp->val;
                    if(temp->left) q.push({temp->left,level+1});
                    if(temp->right) q.push({temp->right,level+1});
                }
                if(maxi<sum){
                    maxi=sum;
                    ans=level;
                }
            }
        
        return ans;
    }
};
