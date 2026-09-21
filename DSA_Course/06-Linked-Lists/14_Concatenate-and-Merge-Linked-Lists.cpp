#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* create(int A[],int n){

    if(n<=0){
        return NULL;
    }

    node* head=new node;
    head->data=A[0];
    head->next=NULL;

    node* last=head;

    for(int i=1;i<n;i++){

        node* t=new node;

        t->data=A[i];
        t->next=NULL;

        last->next=t;
        last=t;
    }

    return head;
}

void display(node* p){

    while(p){
        cout<<p->data<<"\t";
        p=p->next;
    }

    cout<<endl;
}

node* concatenate(node* p,node* q){

    if(p==NULL){
        return q;
    }

    node* head=p;

    while(p->next){
        p=p->next;
    }

    p->next=q;

    return head;
}

node* merge(node* p,node* q){

    if(p==NULL){
        return q;
    }

    if(q==NULL){
        return p;
    }

    node* head=NULL;
    node* last=NULL;

    if(p->data<=q->data){
        head=p;
        last=p;
        p=p->next;
    }
    else{
        head=q;
        last=q;
        q=q->next;
    }

    while(p && q){

        if(p->data<=q->data){
            last->next=p;
            last=p;
            p=p->next;
        }
        else{
            last->next=q;
            last=q;
            q=q->next;
        }
    }

    if(p){
        last->next=p;
    }
    else{
        last->next=q;
    }

    return head;
}

int main(){

    int A[]={1,5,6,11};
    int B[]={0,3,5,8,10,13,16};

    node* list1=create(A,4);
    node* list2=create(B,7);

    cout<<"List 1: ";
    display(list1);

    cout<<"List 2: ";
    display(list2);

    node* merged=merge(list1,list2);

    cout<<"Merged List: ";
    display(merged);

    int C[]={20,30,40};
    int D[]={50,60,70};

    node* list3=create(C,3);
    node* list4=create(D,3);

    node* concatenated=concatenate(list3,list4);

    cout<<"Concatenated List: ";
    display(concatenated);

    return 0;
}