/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node *flatten(Node *root) {
        // code here
        if(root==nullptr || root->next==nullptr) return root;
        
        root->next=flatten(root->next);
        root=merge(root,root->next);
        return root;
    }
    Node *merge(Node*a, Node*b){
        if(a==NULL) return b;
        if(b==NULL) return a;
        Node* result;
        if(a->data<b->data){
            result=a;
            result->bottom=merge(a->bottom,b);
        }
        else{
            result=b;
            result->bottom=merge(a,b->bottom);
        }
        result->next=NULL;
        return result;
    }
};
