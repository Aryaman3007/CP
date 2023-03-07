#include<bits/stdc++.h>
using namespace std;

ListNode* solve(ListNode* list1, ListNode* list2){ // O(N) + O(M)
    if(list1->next==NULL){
        list1->next=list2;
        return list1;
    }
    ListNode* head1=list1;
    ListNode* next1=list1->next;
    ListNode* head2=list2;
    ListNode* next2=list2->next;
    while(next1!=NULL && head2!=NULL){
        if(head2->val>=head1->val && head2->val <=next1->val){
            head1->next=head2;
            next2=head2->next;
            head2->next=next1;
            head1=head2;
            head2=next2;
        }
        else{
            head1=next1;
            next1=next1->next;
            if(next1==NULL){
                head1->next=head2;
                return list1;
            }
        }
    }
    return list1;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    int n=lists.size();
    if(n==0) return NULL;
    if(n==1) return lists[0];
    ListNode* temp=lists[0];
    for(int i=1;i<n;i++){
        if(temp==NULL && lists[i]==NULL){
            temp=NULL;
        }
        else if(temp==NULL && lists[i]!=NULL){
            temp=lists[i];
        }
        else if(temp!=NULL && lists[i]==NULL){
            continue;
        }
        else if(temp->val<=lists[i]->val){
            temp=solve(temp,lists[i]);
        }
        else{
            temp=solve(lists[i],temp);
        }
    }     
    return temp;          
                    
}