#include<iostream>
#include<climits>
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

int min_element(node* p){
    int minm=INT_MAX;

    while(p){
        if(p->data<minm){
            minm=p->data;
        }
        p=p->next;
    }

    return minm;
}

int R_min(node* p){
    if(p==NULL){
        return INT_MAX;
    }

    int x=R_min(p->next);
    return x<p->data ? x : p->data;
}

int main(){
    int LL[]={1,2,3,4,5};
    create(LL,5);

    cout<<"Minimum (iterative): "<<min_element(head)<<endl;
    cout<<"Minimum (recursive): "<<R_min(head)<<endl;

    return 0;
}