class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int levelSize = que.size();  
            vector<int> currentLevel;
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = que.front();
                que.pop();
                currentLevel.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(currentLevel);
        }
        return result;
    }
};
