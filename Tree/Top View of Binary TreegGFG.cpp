/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int> result;
        if (!root) return result;
        queue<pair<Node*, int>> todo;
        map<int, Node*> nodes;
        todo.push({root, 0});
        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            Node* node = p.first;
            int x = p.second;
            if (nodes.find(x) == nodes.end()) {
                nodes[x] = node;
            }
            if (node->left) {
                todo.push({node->left, x - 1});
            }
            if (node->right) {
                todo.push({node->right, x + 1});
            }
        }
        for (auto& it : nodes) {
            result.push_back(it.second->data);
        }
        return result;
    }
};
