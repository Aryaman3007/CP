#include<bits/stdc++.h>
using namespace std;

Node* rotateRight(Node* head, int k) {

    if (head==NULL){
        return NULL;
    }

    if(head->next==NULL){
        return head;
    }  

    int len=0;
    Node* ptr=head;
    while(ptr!=NULL){
        ptr=ptr->next;
        len++;
    }

    k=k%len;
    while(k--){
        Node* temp=head;
        Node* p=head;
        while(p->next->next!=NULL){
            p=p->next;                
        }
        head=p->next;
        p->next=NULL;
        head->next=temp;
    }
    
    return head;   
}  
    