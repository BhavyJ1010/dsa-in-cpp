#include<iostream>
using namespace std;

struct node{
    node* prev;
    int data;
    node* next;
}*head=NULL;

void create(int A[],int n){

    if(n==0){
        head=NULL;
        return;
    }

    head=new node;

    head->data=A[0];
    head->next=head;
    head->prev=head;

    node* last=head;

    for(int i=1;i<n;i++){

        node* t=new node;

        t->data=A[i];

        t->prev=last;
        t->next=head;

        last->next=t;
        head->prev=t;

        last=t;
    }
}

void display(){

    if(head==NULL)
        return;

    node* p=head;

    do{

        cout<<p->data<<" ";

        p=p->next;

    }while(p!=head);

    cout<<endl;
}

void display_reverse(){

    if(head==NULL)
        return;

    node* p=head->prev;
    node* last=p;

    do{

        cout<<p->data<<" ";

        p=p->prev;

    }while(p!=last);

    cout<<endl;
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
        t->prev=t;

        head=t;

        return;
    }

    if(index==0){

        t->next=head;
        t->prev=head->prev;

        head->prev->next=t;
        head->prev=t;

        head=t;

        return;
    }

    node* p=head;

    for(int i=0;i<index-1;i++)
        p=p->next;

    t->next=p->next;
    t->prev=p;

    p->next->prev=t;
    p->next=t;
}

int Delete(int index){

    int len=length();

    if(index<0 || index>=len)
        return -1;

    node* p=head;

    for(int i=0;i<index;i++)
        p=p->next;

    int x=p->data;

    if(len==1){

        delete p;
        head=NULL;

        return x;
    }

    p->prev->next=p->next;
    p->next->prev=p->prev;

    if(p==head)
        head=p->next;

    delete p;

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

    int A[]={1,2,3,4,5};

    create(A,5);

    display();

    cout<<"Length: "<<length()<<endl;

    display_reverse();

    insert(0,10);
    insert(3,20);

    display();

    cout<<"Deleted: "<<Delete(2)<<endl;

    display();

    clear();

    return 0;
}