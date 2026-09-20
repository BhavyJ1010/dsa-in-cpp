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

bool is_sorted(node* p){

    if(p==NULL){
        return true;
    }

    while(p->next!=NULL){

        if(p->data>p->next->data){
            return false;
        }

        p=p->next;
    }

    return true;
}

int main(){

    int LL1[]={10,20,30,40,50};
    int LL2[]={10,20,15,40,50};

    create(LL1,5);

    cout<<"Linked List 1: ";
    display(head);

    if(is_sorted(head)){
        cout<<"Linked List 1 is sorted."<<endl;
    }
    else{
        cout<<"Linked List 1 is not sorted."<<endl;
    }

    create(LL2,5);

    cout<<endl<<"Linked List 2: ";
    display(head);

    if(is_sorted(head)){
        cout<<"Linked List 2 is sorted."<<endl;
    }
    else{
        cout<<"Linked List 2 is not sorted."<<endl;
    }

    return 0;
}