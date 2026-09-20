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

void remove_duplicates(node* p){

    if(p==NULL){
        return;
    }

    node* q=p->next;

    while(q!=NULL){

        if(p->data==q->data){

            p->next=q->next;
            delete q;
            q=p->next;
        }
        else{

            p=q;
            q=q->next;
        }
    }
}

int main(){

    int LL[]={1,1,2,2,2,3,4,4,5,5};

    create(LL,10);

    cout<<"Original Linked List: ";
    display(head);

    remove_duplicates(head);

    cout<<"After removing duplicates: ";
    display(head);

    return 0;
}