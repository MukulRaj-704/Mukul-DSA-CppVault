/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
OPTIMAL APPROACH
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *temp1=head;
        ListNode *temp2=head;
        while(temp2!=NULL&& temp2->next!=NULL){
            temp1=temp1->next;
            temp2=temp2->next->next;
        }
        return temp1;
    }

};

#################################################################################
BRUTE APPROACH 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count =1;
        ListNode* temp=head;
        while(temp->next!=nullptr){
            count++;
            temp = temp->next;

        }
        int middle = count/2;
        int pos =0;
        temp = head;
        while(pos<middle){
            temp=temp->next;
            pos++;
        }
        return temp;
    }

};
