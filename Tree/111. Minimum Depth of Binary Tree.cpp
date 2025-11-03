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
    int minDepth(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
       if(root->left==nullptr){
        return 1+minDepth(root->right);
       } 
       if(root->right==nullptr){
        return 1+minDepth(root->left);
        }
        return 1+min( minDepth(root->left),minDepth(root->right));
    }
};

BACKTRACKING 

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        int count =1;
        int minlen =INT_MAX;
        helper(root,minlen,count);
        return minlen;
    }
    void helper(TreeNode*root, int &minlen, int &count){
        if(root==nullptr) return ;
        if (root->left == nullptr && root->right == nullptr) {
            minlen = min(minlen, count);
            return;
        }
        count++;
        if(root->left) helper(root->left,minlen,count);
        if(root->right) helper(root->right,minlen,count);
        count--;
    }
};
