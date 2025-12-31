class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val1) {
        if (root == nullptr)
            return new TreeNode(val1);
        TreeNode* curr = root;
        TreeNode* temp =NULL;
        while(curr!=nullptr){
            if(curr->val<val1){
                if(curr->right==nullptr){
                    curr->right=new TreeNode(val1);
                    break;
                }
                curr=curr->right;
            }
            else if(curr->val>val1){
                if(curr->left==nullptr){
                    curr->left=new TreeNode(val1);
                    break;
                }
                curr=curr->left;
            }
        }
        return root;
    }
};
