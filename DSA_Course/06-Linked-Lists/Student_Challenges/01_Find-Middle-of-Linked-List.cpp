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
    head->next=NULL;

    last=head;

    for(int i=1;i<n;i++){

        t=new node;

        t->data=A[i];
        t->next=NULL;

        last->next=t;
        last=t;
    }
}

node* middle_node(){

    node* p=head;
    node* q=head;

    while(q){

        q=q->next;

        if(q)
            q=q->next;

        if(q)
            p=p->next;
    }

    return p;
}

int main(){

    int A[]={1,3,5,7,9,11,13,15,17,19,21};

    create(A,11);

    node* middle=middle_node();

    cout<<"Middle Element: "<<middle->data<<endl;

    return 0;
}