#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
}* head=NULL;

void create(int LL[], int n){
    node* t,*last;

    head=NULL;

    if(n<=0){
        return;
    }

    head=new node;
    head->data=LL[0];
    head->next=NULL;
    last=head;

    for(int i=1;i<n;i++){
        t=new node;
        t->data=LL[i];
        t->next=NULL;
        last->next=t;
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

node* insert(node* p,int index,int x){

    if(index<0){
        return p;
    }

    if(index==0){

        node* t=new node;

        t->data=x;
        t->next=p;

        return t;
    }

    node* q=p;

    for(int i=0;q!=NULL && i<index-1;i++){
        q=q->next;
    }

    if(q==NULL){
        return p;
    }

    node* t=new node;

    t->data=x;
    t->next=q->next;
    q->next=t;

    return p;
}

int main(){

    int LL[]={1,2,3,4,5};

    create(LL,5);

    cout<<"Original Linked List: ";
    display(head);

    head=insert(head,0,10);
    head=insert(head,3,20);
    head=insert(head,7,30);

    cout<<"After insertion: ";
    display(head);

    return 0;
}