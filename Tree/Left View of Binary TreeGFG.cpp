/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
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
        if(node->left){
            right(node->left,level+1,result);
        }
        if(node->right){
            right(node->right,level+1,result);
        }
       
    }
};
