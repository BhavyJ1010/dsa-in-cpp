#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* create(int A[],int n){

    if(n<=0){
        return NULL;
    }

    node* head=new node;
    head->data=A[0];
    head->next=NULL;

    node* last=head;

    for(int i=1;i<n;i++){

        node* t=new node;

        t->data=A[i];
        t->next=NULL;

        last->next=t;
        last=t;
    }

    return head;
}

bool check_loop(node* p){

    node* slow=p;
    node* fast=p;

    while(fast!=NULL && fast->next!=NULL){

        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            return true;
        }
    }

    return false;
}

int main(){

    int A[]={1,2,3,4,5,6,7};

    node* head=create(A,7);

    // Create a loop:
    // 7 -> 4
    node* loop_start=head->next->next->next;
    node* last=head;

    while(last->next){
        last=last->next;
    }

    last->next=loop_start;

    if(check_loop(head)){
        cout<<"Given Linked List contains a loop."<<endl;
    }
    else{
        cout<<"Given Linked List does not contain a loop."<<endl;
    }

    return 0;
}