#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    // constructor
    node(int data){
        this->data= data;
        this->next= NULL;
    }
};

void insertfirst(node* &head,int d){
    //new node create;
    node* temp= new node(d);
    temp->next= head;
    head=temp;
}

void insertlast(node* &head,int d){
    node* nn= new node(d);
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=nn;
    nn->next=NULL;
}

void insertmiddle(node* &head,int d,int i){
    node* nn= new node(d);
    int c=0;
    node* temp=head;

    //insert at first
    if(i==0){
        insertfirst(head,d);
        return;
    }
    while(c!=i-1){
        temp=temp->next;
        c++;
    }

    //insert at last
    if(temp->next==NULL){
        insertlast(head,d);
        return;
    }
    nn->next=temp->next;
    temp->next=nn;
}

void deletenode(node* &head,int pos){
    node* p=head;
    if(pos==0){
        head=head->next;
        free(p);
        return;
    }
    int c=0;
    node* q=p->next;
    while(c!=pos-1){
        p=p->next;
        q=q->next;
        c++;
    }
    p->next=q->next;
    free(q);

    if(q->next==NULL){
        p->next=NULL;
        free(q);
        return;
    }
    
}

void display(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    node* n1= new node(10);
    //cout<<n1->data<<endl;
    //cout<<n1->next<<endl;
    
    //head pointed to n1
    node* head=n1;
    //display(head);
    insertfirst(head,15);
    //display(head);

    insertlast(head,11);
    //display(head);

    insertlast(head,16);
    //display(head);

    insertmiddle(head,20,4);
    display(head);
    
    deletenode(head,3);
    display(head);
    return 0;

}