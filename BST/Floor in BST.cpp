class Solution {
  public:
    int floor(Node* root, int x) {
        // code here
        int ans=-1;
        while(root!=nullptr){
            if(root->data==x) return root->data;
            else if( root->data<x) {
                ans=root->data;
                root=root->right;
            }
            else{
                root=root->left;
            }
        }
        return ans;
    }
};
