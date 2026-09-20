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

    node* t;
    node* last;

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

int delete_node(node* &p,int index){

    if(p==NULL || index<0){
        return -1;
    }

    node* q=NULL;
    int x;

    if(index==0){

        q=p;
        x=p->data;
        p=p->next;

        delete q;

        return x;
    }

    q=p;

    for(int i=0;i<index-1 && q->next!=NULL;i++){
        q=q->next;
    }

    if(q->next==NULL){
        return -1;
    }

    node* t=q->next;

    x=t->data;
    q->next=t->next;

    delete t;

    return x;
}

int main(){

    int LL[]={10,20,30,40,50};

    create(LL,5);

    cout<<"Original Linked List: ";
    display(head);

    cout<<"Deleted element: "
        <<delete_node(head,2)<<endl;

    cout<<"Linked List after deletion: ";
    display(head);

    cout<<"Deleted element: "
        <<delete_node(head,0)<<endl;

    cout<<"Linked List after deletion: ";
    display(head);

    return 0;
}