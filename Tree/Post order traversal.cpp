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
    vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    stack<TreeNode*> st;
    TreeNode* curr = root;
    TreeNode* lastVisited = nullptr;

    while (!st.empty() || curr) {
        if (curr) {
            st.push(curr);
            curr = curr->left;
        } else {
            TreeNode* peek = st.top();
            if (peek->right && lastVisited != peek->right) {
                curr = peek->right;
            } else {
                result.push_back(peek->val);
                lastVisited = peek;
                st.pop();
            }
        }
    }

    return result;
    }
};
