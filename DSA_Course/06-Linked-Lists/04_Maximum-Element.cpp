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

int max_element(node* p){
    int maxm=INT_MIN;

    while(p){
        if(p->data>maxm){
            maxm=p->data;
        }
        p=p->next;
    }

    return maxm;
}

int R_max(node* p){
    if(p==NULL){
        return INT_MIN;
    }

    int x=R_max(p->next);
    return x>p->data ? x : p->data;
}

int main(){
    int LL[]={1,2,3,4,5};
    create(LL,5);

    cout<<"Maximum (iterative): "<<max_element(head)<<endl;
    cout<<"Maximum (recursive): "<<R_max(head)<<endl;

    return 0;
}