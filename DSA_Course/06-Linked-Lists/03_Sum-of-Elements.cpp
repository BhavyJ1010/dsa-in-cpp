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

int sum(node* p){
    int total=0;
    while(p){
        total+=p->data;
        p=p->next;
    }
    return total;
}

int Rsum(node* p){
    if(p){
        return p->data+Rsum(p->next);
    }
    return 0;
}

int main(){
    int LL[]={1,2,3,4,5};
    create(LL,5);

    cout<<"Sum (iterative): "<<sum(head)<<endl;
    cout<<"Sum (recursive): "<<Rsum(head)<<endl;

    return 0;
}