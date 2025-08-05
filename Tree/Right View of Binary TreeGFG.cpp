/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should return  right view of tree
class Solution {
  public:
    // Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root) {
        // Your Code here
        vector<int>ans;
        right(root,0,ans);
        return ans;
    }
    void right(Node* node,int level,vector<int>&result){
        if(node==nullptr){
            return ;
        }
        
        if(level==result.size()){
            result.push_back(node->data);
        }
        if(node->right){
            right(node->right,level+1,result);
        }
        if(node->left){
            right(node->left,level+1,result);
        }
    }
};
