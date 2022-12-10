#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this->data=d;
        this->next=NULL;
    }

};

void insertnode(Node* &tail,int element,int d){
    //assuming that the element is in the list;
    //empty list
    if(tail==NULL){
        Node* nn=new Node(d);
        tail=nn;
        nn->next=nn;
    }
    //non-empty list
    else{
        Node* curr=tail;
        while(curr->data!=element){
            curr=curr->next;
        }

        //element found in ths list
        Node* ptr=new Node(d);
        ptr->next=curr->next;
        curr->next=ptr;
    }
}

void deletenode(Node* &tail,int d){

    if(tail== NULL){
        cout<<"Check again"<<endl;
        return;
    }
    else{
        Node* prev=tail;
        Node* curr=prev->next;
        while(curr->data!=d){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;

        if(curr==prev){
            tail=NULL;
        }
        else if(tail==curr){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
    }
}

void print(Node* tail){
    //empty list
    if(tail==NULL){
        cout<<"List is empty";
        return;
    }
    Node* temp=tail;
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!=temp);
    cout<<endl;
}

int main(){

    Node* tail=NULL;
    insertnode(tail,5,3);
    print(tail);
    insertnode(tail,3,6);
    print(tail);
    insertnode(tail,3,7);
    print(tail);
    insertnode(tail,7,9);
    print(tail);
    insertnode(tail,6,11);
    print(tail);

    deletenode(tail,3);
    print(tail);

    return 0;

}