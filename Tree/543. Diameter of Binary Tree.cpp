#############################################################################################
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
###############################################################################################
BRUTE APPROACH
class Solution {
public:
int maxi=0;
    int diameterOfBinaryTree(TreeNode* root) {
        findmax(root);
        return maxi;
    }
    int findmax(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int lh=findmax(root->left);
        int rh = findmax(root->right);
        maxi = max(maxi,lh+rh);
       // findmax(root->left);
       // findmax(root->right);
  return 1+max(lh,rh);  }
};
