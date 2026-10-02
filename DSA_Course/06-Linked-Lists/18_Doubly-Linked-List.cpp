#include<iostream>
using namespace std;

struct node{
    node* prev;
    int data;
    node* next;
};

class DoublyLinkedList{
private:
    node* head;

public:
    DoublyLinkedList(){ head=NULL; }
    DoublyLinkedList(int A[],int n);
    ~DoublyLinkedList();

    void Display();
    int Length();
    void Insert(int index,int x);
    int Delete(int index);
    void Reverse();
};

DoublyLinkedList::DoublyLinkedList(int A[],int n){

    head=NULL;

    if(n==0)
        return;

    head=new node;

    head->prev=NULL;
    head->data=A[0];
    head->next=NULL;

    node* last=head;

    for(int i=1;i<n;i++){

        node* t=new node;

        t->prev=last;
        t->data=A[i];
        t->next=NULL;

        last->next=t;
        last=t;
    }
}

DoublyLinkedList::~DoublyLinkedList(){

    node* p=head;

    while(head){

        head=head->next;

        delete p;

        p=head;
    }
}

void DoublyLinkedList::Display(){

    node* p=head;

    while(p){

        cout<<p->data;

        if(p->next)
            cout<<" <-> ";

        p=p->next;
    }

    cout<<endl;
}

int DoublyLinkedList::Length(){

    int len=0;
    node* p=head;

    while(p){

        len++;
        p=p->next;
    }

    return len;
}

void DoublyLinkedList::Insert(int index,int x){

    if(index<0 || index>Length())
        return;

    node* t=new node;

    t->data=x;

    if(index==0){

        t->prev=NULL;
        t->next=head;

        if(head)
            head->prev=t;

        head=t;

        return;
    }

    node* p=head;

    for(int i=0;i<index-1;i++)
        p=p->next;

    t->prev=p;
    t->next=p->next;

    if(p->next)
        p->next->prev=t;

    p->next=t;
}

int DoublyLinkedList::Delete(int index){

    if(index<0 || index>=Length())
        return -1;

    node* p=head;

    for(int i=0;i<index;i++)
        p=p->next;

    int x=p->data;

    if(p->prev)
        p->prev->next=p->next;
    else
        head=p->next;

    if(p->next)
        p->next->prev=p->prev;

    delete p;

    return x;
}

void DoublyLinkedList::Reverse(){

    node* p=head;
    node* temp=NULL;

    while(p){

        temp=p->prev;

        p->prev=p->next;
        p->next=temp;

        p=p->prev;
    }

    if(temp)
        head=temp->prev;
}

int main(){

    int A[]={1,3,5,7,9};

    DoublyLinkedList l(A,5);

    l.Display();

    cout<<"Length: "<<l.Length()<<endl;

    l.Insert(0,11);
    l.Insert(5,13);

    l.Display();

    cout<<"Deleted: "<<l.Delete(1)<<endl;

    l.Display();

    l.Reverse();

    l.Display();

    return 0;
}