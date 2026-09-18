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

int count_nodes(node* p){
    int count=0;
    while(p){
        count++;
        p=p->next;
    }
    return count;
}

int Rcount_nodes(node* p){
    if(p==NULL){
        return 0;
    }
    return Rcount_nodes(p->next)+1;
}

int main(){
    int LL[]={1,2,3,4,5};
    create(LL,5);

    cout<<"Number of nodes (iterative): "<<count_nodes(head)<<endl;
    cout<<"Number of nodes (recursive): "<<Rcount_nodes(head)<<endl;

    return 0;
}