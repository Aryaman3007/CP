#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* prev;
    node* next;

    // constructor
    node(int d){
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }

};

void display(node* head){
    node* p=head;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int getlen(node* head){
    node* p=head;
    int c=0;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}

void insertathead(node* &tail,node* &head,int d){

    //empty list
    if(head==NULL){
        node* temp=new node(d);
        head=temp;
        tail=temp;
    }
    else{
        node* p=head;
        node* nn=new node(d);
        nn->next=p;
        p->prev=nn;
        head=nn;
    }
}

void insertattail(node* &head,node* &tail,int d){
    //empty list
    if(tail==NULL){
        node* temp=new node(d);
        tail=temp;
        head=temp;
    }
    else{
        node* p=tail;
        node* nn=new node(d);
        p->next=nn;
        nn->prev=p;
        tail=nn;
    }
}

void insertatpos(node* &head,node* &tail,int d,int pos){
    node* nn=new node(d);
    node* temp=head;
    int c=0;
    if(pos==0){
        insertathead(tail,head,d);
        return;
    }
    while(c!=pos-1){
        temp=temp->next;
        c++;
    }
    if(temp->next==NULL){
        insertattail(head,tail,d);
        return;
    }
    nn->next=temp->next;
    temp->next=nn;
    temp->next->prev=nn;
    nn->prev=temp;
}

void deletenode(node* &head,node* &tail,int pos){
    //delete first node
    if(pos==0){
        node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        free(temp);
    }
    else{
        //delete any middle node
        int c=0;
        node* curr=head;
        node* prev=NULL;
        while(c<pos){
            prev=curr;
            curr=curr->next;
            c++;
        }
        if(c==pos-1){
            curr->next=NULL;
            tail=prev;
            curr->prev=NULL;
            free(curr);
            return;
        }
        prev->next=curr->next;
        curr->prev=NULL;
        curr->next=NULL;
        free(curr);
    }
}


int main(){
    node * n1=new node(10);
    node* head=n1;
    node* tail=n1;
    insertathead(tail,head,6);
    insertathead(tail,head,12);
    insertattail(head,tail,18);
    insertatpos(head,tail,20,0);
    display(head);
    deletenode(head,tail,4);
    display(head);
    cout<<head->data<<endl<<tail->data<<endl;
    int x=getlen(head);
    cout<<x;
    return 0;
}