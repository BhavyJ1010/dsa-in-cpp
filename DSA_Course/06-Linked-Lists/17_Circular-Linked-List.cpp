#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
}*head=NULL;

void create(int A[],int n){

    if(n==0){
        head=NULL;
        return;
    }

    node* t,*last;

    head=new node;

    head->data=A[0];
    head->next=head;

    last=head;

    for(int i=1;i<n;i++){

        t=new node;

        t->data=A[i];
        t->next=head;

        last->next=t;
        last=t;
    }
}

void display(node* p){

    if(head==NULL)
        return;

    do{
        cout<<p->data<<" ";
        p=p->next;

    }while(p!=head);

    cout<<endl;
}

void RDisplay(node* p,node* start,bool firstCall=true){

    if(head==NULL)
        return;

    if(!firstCall && p==start)
        return;

    cout<<p->data<<" ";

    RDisplay(p->next,start,false);
}

int length(){

    if(head==NULL)
        return 0;

    int len=0;
    node* p=head;

    do{
        len++;
        p=p->next;

    }while(p!=head);

    return len;
}

void insert(int index,int x){

    if(index<0 || index>length())
        return;

    node* t=new node;
    t->data=x;

    if(head==NULL){

        t->next=t;
        head=t;

        return;
    }

    if(index==0){

        node* p=head;

        while(p->next!=head)
            p=p->next;

        t->next=head;
        p->next=t;
        head=t;

        return;
    }

    node* p=head;

    for(int i=0;i<index-1;i++)
        p=p->next;

    t->next=p->next;
    p->next=t;
}

int Delete(int index){

    int len=length();

    if(index<0 || index>=len)
        return -1;

    node* p=head;
    int x;

    if(len==1){

        x=head->data;

        delete head;
        head=NULL;

        return x;
    }

    if(index==0){

        while(p->next!=head)
            p=p->next;

        node* q=head;

        x=q->data;

        head=head->next;
        p->next=head;

        delete q;

        return x;
    }

    for(int i=0;i<index-1;i++)
        p=p->next;

    node* q=p->next;

    p->next=q->next;

    x=q->data;

    delete q;

    return x;
}

void clear(){

    if(head==NULL)
        return;

    node* p=head->next;

    while(p!=head){

        node* q=p;

        p=p->next;

        delete q;
    }

    delete head;
    head=NULL;
}

int main(){

    int A[]={1,3,5,7,9};

    create(A,5);

    display(head);

    cout<<"Length: "<<length()<<endl;

    RDisplay(head,head);
    cout<<endl;

    insert(0,10);
    insert(3,20);

    display(head);

    cout<<"Deleted: "<<Delete(2)<<endl;

    display(head);

    clear();

    return 0;
}