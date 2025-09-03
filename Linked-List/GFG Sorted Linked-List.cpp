/*
class Node
{
  public:
    int data;
    Node * next;
    Node (int x)
    {
        data=x;
        next=NULL;
    }

};
*/

class Solution {
  public:
    bool isSorted(Node* head) {
        // code here
        if(head==nullptr || head->next==nullptr) return true;
        Node* temp = head;
        bool ascending = false;
        while(temp->next!=nullptr){
        if(temp->data<temp->next->data){
            ascending = true;
            break;
        }
        else if(temp->data>temp->next->data){
            ascending = false;
            break;
        }
        temp=temp->next;
        }
        temp=head;
        if(ascending){
            while(temp->next!=nullptr){
                if(temp->data>temp->next->data){
                    return false;
                }
                temp=temp->next;
            }
            
        }
        else{
            while(temp->next!=nullptr){
            if(temp->data<temp->next->data){
                return false;
            }
            temp=temp->next;
        }
    }
        return true;
    }
};
