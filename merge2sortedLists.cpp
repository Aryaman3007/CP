#include<bits/stdc++.h>
using namespace std;

Node* solve(Node* list1,Node* list2){

    //If list1 has only 1 element
    if(list1->next==NULL){
        list1->next=list2;
        return list1;
    }
    Node* curr1=list1;
    Node* next1=list1->next;
    Node* curr2=list2;
    Node* next2=list2->next;

    //While till next1 is not null and List2 is not empty
    while(next1!=NULL && curr2!=NULL){
        
        //Add a node between the list
        if(curr1->data<=curr2->data && next1->data>=curr2->data){
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next2;

            //update the pointers
            curr1=curr2;
            curr2=next2;
        }
        else{
            
            //Move the curr1 and next1 pointers if a node is not added
            curr1=next1;
            next1=next1->next;

            //check if next1 is null or not 
            if(next1==NULL){
                curr1->next=curr2;
                return list1;
            }
        }
    }
    return list1;
}

Node* Merge2List(Node* list1,Node* list2){
    if(list1==NULL){
        return list2;
    }
    else if(list2==NULL){
        return list1;
    }
    if(list->data>list2->data){
        return solve(list2,list1);
    }
    else{
        return solve(list1,list2);
    }
}