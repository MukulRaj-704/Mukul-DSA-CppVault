OPTIMAL APPROACH 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * temp1 = head;
        ListNode * temp2=NULL;
        ListNode * curr=NULL;   

        while(temp1!=NULL){
            temp2= temp1->next;
            temp1->next=curr;
            curr=temp1;
            temp1=temp2;
        }
        
        return curr;
    }
};

############################################################
BRUTE APPROACH
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<int> mystack;
        ListNode* temp = head;
        while(temp!=NULL){
            mystack.push(temp->val);
            temp=temp->next;
        }
        temp= head;
        while(temp!=NULL){
            temp->val = mystack.top();
            mystack.pop();
            temp=temp->next;
        }
        return head;
    }
};
