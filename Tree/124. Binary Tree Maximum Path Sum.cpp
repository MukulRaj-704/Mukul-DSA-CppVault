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
int maxi=INT_MIN;
    int maxPathSum(TreeNode* root) {
        findmax(root);
        return maxi;
    }
    int findmax(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int lh = max(0,findmax(root->left));
        int rh = max(0,findmax(root->right));
        maxi = max(maxi,lh+rh+root->val);
        return root->val + max(lh,rh);
    }
};
