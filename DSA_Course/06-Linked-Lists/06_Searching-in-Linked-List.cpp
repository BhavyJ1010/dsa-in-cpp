#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
}* head=NULL;

void create(int LL[], int n){
    node* t,*last;

    head=NULL;

    if(n<=0){
        return;
    }

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

int search(node* p,int key){
    int index=0;

    while(p){
        if(p->data==key){
            return index;
        }

        p=p->next;
        index++;
    }

    return -1;
}

int Rsearch(node* p,int key){
    if(p==NULL){
        return -1;
    }

    if(p->data==key){
        return 0;
    }

    int index=Rsearch(p->next,key);

    if(index==-1){
        return -1;
    }

    return index+1;
}

int search_improved(int key){
    node* p=head;
    node* q=NULL;
    int index=0;

    while(p){

        if(p->data==key){

            if(q!=NULL){
                q->next=p->next;
                p->next=head;
                head=p;
            }

            return index;
        }

        q=p;
        p=p->next;
        index++;
    }

    return -1;
}

int main(){

    int LL[]={1,2,3,4,5};

    create(LL,5);

    cout<<"Linked List: ";
    display(head);

    cout<<"Search 4 (iterative): "
        <<search(head,4)<<endl;

    cout<<"Search 4 (recursive): "
        <<Rsearch(head,4)<<endl;

    cout<<"Improved search 4: "
        <<search_improved(4)<<endl;

    cout<<"List after improved search: ";
    display(head);

    return 0;
}