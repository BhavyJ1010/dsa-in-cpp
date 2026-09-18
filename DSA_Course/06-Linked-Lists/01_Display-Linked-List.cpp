#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
}* head=NULL;

void create(int LL[], int n){
    node* t,*last;
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

void display_recur(node* p){
    if(p!=NULL){
        cout<<p->data<<"\t";
        display_recur(p->next);
    }
}

void display_recur_rev(node* p){
    if(p!=NULL){
        display_recur_rev(p->next);
        cout<<p->data<<"\t";
    }
}

int main(){
    int LL[]={1,2,3,4,5};
    create(LL,5);

    cout<<"Display: ";
    display(head);

    cout<<"Recursive display: ";
    display_recur(head);
    cout<<endl;

    cout<<"Recursive reverse display: ";
    display_recur_rev(head);
    cout<<endl;

    return 0;
}