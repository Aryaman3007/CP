#include<bits/stdc++.h>
using namespace std;

Node* segregate(Node *head) {
    map<int,int> m;
    Node*p=head;
    while(p!=NULL){
        m[p->data]++;
        p=p->next;
    }
    int a=m[0];
    int b=m[1];
    int c=m[2];
    Node* temp=head;
    int cnt=0;
    while(temp!=NULL){
        if(cnt<a){
            temp->data=0;
        }
        else if(cnt>=a && cnt<a+b){
            temp->data=1;
        }
        else{
            temp->data=2;
        }
        cnt++;
        temp=temp->next;        
    }
    return head;
}