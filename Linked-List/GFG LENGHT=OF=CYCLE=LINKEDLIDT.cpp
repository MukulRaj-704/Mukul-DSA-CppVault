/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node* slow=head;
        Node* fast = head;
        Node* curr=NULL;
        int count=0;
        while(fast!=nullptr && fast->next!=nullptr){
            slow= slow->next;
            fast= fast->next->next;
            if(slow== fast){
                curr=slow->next;
                count=1;
                while(curr!=slow){
                curr=curr->next;
                
                    count++;
                }
                break;
                
            }
        }
        return count;
    }
};
