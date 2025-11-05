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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>res;
        if (!root) return res;
        q.push(root);
        bool flag=false;// right to left 
        while(!q.empty()){
            int n = q.size();
            vector<int> ans;
            for(int i=0;i<n;i++){
                TreeNode* curr = q.front();
                q.pop();
                ans.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            if(flag==true){
                reverse(ans.begin(),ans.end());
                
            }
            res.push_back(ans);
            flag = !flag;

        }

        return res;
    }
};
