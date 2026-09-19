#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
}* head=NULL;

void create(int LL[],int n){

    head=NULL;

    if(n<=0){
        return;
    }

    node* last=NULL;

    for(int i=0;i<n;i++){

        node* t=new node;

        t->data=LL[i];
        t->next=NULL;

        if(head==NULL){
            head=t;
        }
        else{
            last->next=t;
        }

        last=t;
    }
}

void display(node* p){

    while(p){
        cout<<p->data<<"\t";
        p=p->next;
    }

    cout<<endl;
}

node* insert_sorted(node* p,int x){

    node* t=new node;

    t->data=x;
    t->next=NULL;

    if(p==NULL || x<=p->data){
        t->next=p;
        return t;
    }

    node* q=p;

    while(q->next!=NULL && q->next->data<x){
        q=q->next;
    }

    t->next=q->next;
    q->next=t;

    return p;
}

int main(){

    int LL[]={1,3,5,7,9};

    create(LL,5);

    cout<<"Original sorted Linked List: ";
    display(head);

    head=insert_sorted(head,0);
    head=insert_sorted(head,6);
    head=insert_sorted(head,10);

    cout<<"After sorted insertion: ";
    display(head);

    return 0;
}