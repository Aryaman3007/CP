#include<bits/stdc++.h>
using namespace std;

node* reverse(node* head,int len,int k){

    //base case
    if(head==NULL || len<k){
        return head;
    }

    //step 1: reverse 1st k nodes
    node* prev=NULL;
    node* curr=head;
    node* nxt=NULL;
    int cnt=0;
    while(cnt<k && curr!=NULL){
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
        cnt++;        
    }

    //step 2: Recursive call for all k Groups
    head->next=reverse(nxt,len-k,k);
    return prev;
}

node* reverseKGroups(node* head,int k){
    //get length of the list
    node* p=head;
    int len=0;
    while(p!=NULL){
        p=p->next;
        len++;
    }   
    reverse(head,len,k);
}