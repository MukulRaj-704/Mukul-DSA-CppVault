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
    vector<int> bottomView(Node *root) {
        // Your Code Here
        map<int,int>nodes;
        queue<pair<Node*,int>>todo;
        todo.push({root,0});
        
        while(!todo.empty()){
            auto p = todo.front();
            todo.pop();
            Node* node = p.first;
            int x = p.second;
            nodes[x]= node->data;
            if(node->left){
                todo.push({node->left,x-1});
                
            }
            if(node->right){
                todo.push({node->right,x+1});
            }
        }
        vector<int>result;
        for(auto it : nodes){
            result.push_back(it.second);
        }
        return result;
    }
};
