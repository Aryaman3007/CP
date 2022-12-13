#include<bits/stdc++.h>
using namespace std;

void insertatTail(Node* &anshead,Node* &anstail,int d){
    Node* temp=new Node(d);
    if(anshead==NULL){
        anshead=temp;
        anstail=temp;
    }
    else{
        anstail->next=temp;
        anstail=temp;
    }
}

Node* addtwonumbers(Node* l1,Node* l2){
    
    Node* first=l1;
    Node* second=l2;
    Node* anshead=NULL;
    Node* anstail=NULL;
    int carry=0;
    while(first!=NULL && second!=NULL){
        int sum=carry + first->data + second->data;
        int digit=sum%10;
        insertatTail(anshead,anstail,digit);
        carry=sum/10;
        first=first->next;
        second=second->next;
    }
    while(first!=NULL){
        int sum=carry + first->data;
        int digit=sum%10;
        insertatTail(anshead,anstail,digit);
        carry=sum/10;
        first=first->next;
    }
    while(second!=NULL){
        int sum=carry+ second->data;
        int digit=sum%10;
        insertatTail(anshead,anstail,digit);
        carry=sum/10;
        second=second->next;
    }
    if(carry!=0){
        insertatTail(anshead,anstail,carry);
    }
    return anshead;
}