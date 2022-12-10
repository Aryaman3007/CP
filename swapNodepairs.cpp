#include<bits/stdc++.h>
using namespace std;

node* SwapPairs(node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* prev=head;
    node* curr=head->next;
    node* nxt=curr->next;
    curr->next=prev;
    prev=curr;
    curr=nxt;
    head->next=swapPairs(nxt);
    return prev;
}