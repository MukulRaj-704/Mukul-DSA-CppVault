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
    bool isBalanced(TreeNode* root) {
        return maxDepth(root)!=-1;
    }
     int maxDepth(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        if(lh==-1 || rh==-1){
            return -1;
        }
        if(abs(lh-rh)>1){
            return -1;
        }
        return 1+max(lh,rh);
    }
};


BACKTRACKING 

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        int maxlen=0;
        int count =1;
        return helper(root,count,maxlen)!=-1;
        
    }
    private:
    int helper(TreeNode* root, int &count, int &maxlen){
        if(root==NULL) return 0;
        maxlen=max(maxlen,count);
        count++;
        int lh=helper(root->left,count,maxlen);
        int rh= helper(root->right, count,maxlen);
        count--;
        if(lh==-1 || rh==-1){
            return -1;
        }
        if(abs(lh-rh)>1){
            return -1;
        }
        return 1+max(lh,rh);
    }
};
