#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int val;
    node* next;
};

node* head=nullptr;
node* tail=nullptr;

node* createnode(int val1){
    node* temp = new node();
    temp->val= val1;
    temp->next=nullptr;
    return temp;
}

void printlist(node* head){
    node* curr=head;
    if(head==nullptr){
        cout<<"list is empty"<<endl;
        return ;
    }
    while(curr!=nullptr){
        cout<<curr->val<<"->";
        curr=curr->next;
    }
}
int helper(node* head, int k){
    if(head==nullptr){
        cout<<"list has no element"<<endl;
        return -1;
    }
    node* curr=head;
    node* prev=tail;
    int count=1;
    while(curr->next!=curr){
        
        if(count==k){
            if(curr==tail){
                tail=prev;
            }
            if(curr==head){
                head=curr->next;
            }
            node* temp = curr;
            prev->next=curr->next;
            curr=temp->next;
            temp->next=nullptr;
            delete temp;
            count=1;
        }
        else{
            prev=curr;
            curr=curr->next;
            count++;
        }
    }
    return curr->val;
}

int main(){
    int n;
    cout<<"enter no of people"<<endl;
    cin>>n;
    int k;
    cout<<"enter kth person that you want to eliminate"<<endl;
    cin>>k;
    for(int i=1;i<=n;i++){
        node* temp= createnode(i);
        if(head==nullptr){
            head=tail=temp;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }
    
    printlist(head);
    tail->next=head;
    int res =helper(head, k);
    cout<<"last element is "<<res<<endl;
    return 0;
}
