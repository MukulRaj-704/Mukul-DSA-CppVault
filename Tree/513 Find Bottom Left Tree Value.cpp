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
    int findBottomLeftValue(TreeNode* root) {
          vector<int>ans;
        right(root,0,ans);
        int sol = ans.back();
        return sol;
    }
    void right(TreeNode* node,int level,vector<int>&result){
        if(node==nullptr){
            return ;
        }
        
        if(level==result.size()){
            result.push_back(node->val);
        }
        if(node->left){
            right(node->left,level+1,result);
        }
        if(node->right){
            right(node->right,level+1,result);
        }
       
    }
};
