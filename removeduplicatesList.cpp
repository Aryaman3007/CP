#include<bits/stdc++.h>
using namespace std;

//Sorted List
node* removeduplicates(node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* curr=head;
    while(curr!=NULL && curr->next!=NULL){
        if(curr->val==curr->next->val){
            node* temp=curr->next->next;
            node* todelete=curr->next;
            delete todelete;
            curr->next=temp;
        }
        else{
            curr=curr->next;
        }
    }
    return head;
}

//Unsorted List TC- O(n^2)
node* deleteduplicate(node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* curr=head;
    while(curr!=NULL && curr->next!=NULL){
        node* temp=curr;
        while(temp->next!=NULL){
            if(temp->next->data==curr->data){
                node* temp1=temp->next;
                temp->next=temp1->next;
                delete(temp1);
            }
            else{
                temp=temp->next;
            }
        }
        curr=curr->next;
    }
    return head;
}