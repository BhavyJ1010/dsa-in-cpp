#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class LinkedList{
private:
    Node* first;

public:
    LinkedList(){ first=NULL; }
    LinkedList(int A[], int n);
    ~LinkedList();

    void Display();
    int Length();
    void Insert(int index, int x);
    int Delete(int index);
};

LinkedList::LinkedList(int A[], int n){
    first=NULL;

    if(n==0)
        return;

    Node* last;

    first=new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++){
        Node* t=new Node;

        t->data=A[i];
        t->next=NULL;

        last->next=t;
        last=t;
    }
}

LinkedList::~LinkedList(){
    Node* p=first;

    while(first){
        first=first->next;
        delete p;
        p=first;
    }
}

void LinkedList::Display(){
    Node* p=first;

    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }

    cout<<endl;
}

int LinkedList::Length(){
    Node* p=first;
    int len=0;

    while(p){
        len++;
        p=p->next;
    }

    return len;
}

void LinkedList::Insert(int index,int x){
    if(index<0 || index>Length())
        return;

    Node* t=new Node;
    t->data=x;

    if(index==0){
        t->next=first;
        first=t;
    }
    else{
        Node* p=first;

        for(int i=0;i<index-1;i++)
            p=p->next;

        t->next=p->next;
        p->next=t;
    }
}

int LinkedList::Delete(int index){
    if(index<0 || index>=Length())
        return -1;

    Node* p=first;
    int x;

    if(index==0){
        first=first->next;
        x=p->data;

        delete p;
        return x;
    }

    Node* q=NULL;

    for(int i=0;i<index;i++){
        q=p;
        p=p->next;
    }

    q->next=p->next;
    x=p->data;

    delete p;

    return x;
}

int main(){

    int A[]={1,2,3,4,5};

    LinkedList l(A,5);

    l.Display();

    cout<<"Length: "<<l.Length()<<endl;

    l.Insert(0,10);
    l.Insert(3,20);

    l.Display();

    cout<<"Deleted: "<<l.Delete(2)<<endl;

    l.Display();

    return 0;
}