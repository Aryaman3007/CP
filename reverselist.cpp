#include<bits/stdc++.h>
using namespace std;

//using iteration
node* reverselist(node* head){
    node* prev=NULL;
    node* curr=head;
    node*forward;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    head=prev;
    return head;
}

//using recursion
void reverse(node* &head,node* curr,node* prev){
    //base case
    if(curr==NULL){
        head=prev;
        return;
    }
    node* forward= curr->next;
    reverse(head,forward,curr);
    curr->next=prev;
}

node* reverseList(node* head) {
    node* curr=head; 
    node* prev=NULL; 
    reverse(head,curr,prev);
    return head;
}
