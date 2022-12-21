#include<bits/stdc++.h>
using namespace std;

Node* reverse(Node* head){
    Node* prev=NULL;
    Node* curr=head;
    Node* forward;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}

Node* reverseList(Node* head, int left, int right){
    if(left==right){
        return head;
    }

    Node* prev=NULL;
    Node* prev_prev=NULL;
    Node* end=NULL;
    Node* end_next=NULL;

    Node* curr=head;
    int i=0;
    while(curr!=head && i<=right){
        if(i<left){
            prev_prev=curr;
        }
        if(i==left){
            prv=curr;
        }
        if(i==right){
            end=curr;
            end_next=curr->next;
        }
        curr=curr->next;
        i++;
    }

    end->next=NULL;
    end=reverse(prev);
    if(prev_prev!=NULL){
        prev_prev->next=end;
    }
    else{
        head=end;
    }
    prev->next=end_next;

    return head;

}