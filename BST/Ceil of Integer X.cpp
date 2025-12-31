class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        int ans=-1;
     while(root!=nullptr){
         if(root->data==x) return root->data;
         else if(root->data<x) root= root->right;
         else{
             ans=root->data;
             root=root->left;
             
         }
     }
     return ans;
    }
};
