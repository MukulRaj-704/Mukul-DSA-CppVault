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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* curr=root;
        if(root==nullptr){
            return root;
        }
        if(root->val==key){
           return helper(root,key);
        }
        while(curr!=nullptr){
            if(curr->val<key){
                if (curr->right && curr->right->val==key){
                 curr->right=helper(curr->right,key);
                 break;}
                
                    curr=curr->right;
                 
            }
            else {
                if(curr->left && curr->left->val==key) {
                    curr->left=helper(curr->left,key);
                    break;
                    
                }
                
                    curr=curr->left;
                
            }
        }
        return root;
    }
    TreeNode* helper(TreeNode* root, int Key){
        if(root->left==nullptr) return root->right;
        if(root->right==nullptr) return root->left;
        TreeNode* rchild = root->right;
        TreeNode* lastright = findchild(root->left);
        lastright->right=rchild;
        return root->left;
    }
    TreeNode* findchild(TreeNode* root){
        if(root->right==NULL) return root;
        return findchild(root->right);
    }
};
