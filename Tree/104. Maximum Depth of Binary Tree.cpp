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
    int maxDepth(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        return 1+max(lh,rh);
    }
};

BACKTRACKING 

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int maxlen=0;
        int count =1;
        helper(root,count,maxlen);
        return maxlen;
    }
private:
    void helper(TreeNode* root, int &count, int &maxlen){
        if(root==NULL) return ;
        maxlen=max(maxlen,count);
        count++;
        if(root->left) helper(root->left,count,maxlen);
        if(root->right) helper(root->right, count,maxlen);
        count--;
    }
};
