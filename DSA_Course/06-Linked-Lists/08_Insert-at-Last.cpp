#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
}* head=NULL;

void display(node* p){
    while(p){
        cout<<p->data<<"\t";
        p=p->next;
    }
    cout<<endl;
}

void insert_at_last(int x){

    node* t=new node;

    t->data=x;
    t->next=NULL;

    if(head==NULL){
        head=t;
        return;
    }

    node* p=head;

    while(p->next){
        p=p->next;
    }

    p->next=t;
}

void create(int LL[],int n){

    head=NULL;

    for(int i=0;i<n;i++){
        insert_at_last(LL[i]);
    }
}

int main(){

    int LL[]={1,2,3,4,5};

    create(LL,5);

    cout<<"Linked List created using insertion at last: ";
    display(head);

    insert_at_last(6);
    insert_at_last(7);

    cout<<"After inserting at last: ";
    display(head);

    return 0;
}