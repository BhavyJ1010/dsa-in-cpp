#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
}* head=NULL;

void create(int A[],int n){

    head=NULL;

    if(n<=0){
        return;
    }

    node* last;

    head=new node;
    head->data=A[0];
    head->next=NULL;
    last=head;

    for(int i=1;i<n;i++){

        node* t=new node;

        t->data=A[i];
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

int length(node* p){

    int n=0;

    while(p){
        n++;
        p=p->next;
    }

    return n;
}

// Method 1: Reverse by using an array
void reverse_array(node* p){

    int n=length(p);

    if(n<=1){
        return;
    }

    int* A=new int[n];

    node* q=p;

    for(int i=0;i<n;i++){
        A[i]=q->data;
        q=q->next;
    }

    q=p;

    for(int i=n-1;i>=0;i--){
        q->data=A[i];
        q=q->next;
    }

    delete[] A;
}

// Method 2: Reverse by changing links
void reverse_links(){

    node* p=head;
    node* q=NULL;
    node* r=NULL;

    while(p){

        r=q;
        q=p;
        p=p->next;

        q->next=r;
    }

    head=q;
}

// Method 3: Recursive reversal
void reverse_recursive(node* q,node* p){

    if(p){

        reverse_recursive(p,p->next);

        p->next=q;
    }
    else{
        head=q;
    }
}

int main(){

    int A[]={10,20,30,40,50};

    create(A,5);

    cout<<"Original Linked List: ";
    display(head);

    reverse_array(head);

    cout<<"After array reversal: ";
    display(head);

    reverse_links();

    cout<<"After pointer reversal: ";
    display(head);

    reverse_recursive(NULL,head);

    cout<<"After recursive reversal: ";
    display(head);

    return 0;
}