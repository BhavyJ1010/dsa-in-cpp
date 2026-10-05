#include<iostream>
#include<new>
using namespace std;

struct stack_node{
    int data;
    stack_node* next;
};

void push(stack_node*& st,int val){
    stack_node* t=new(nothrow) stack_node;

    if(t==NULL){
        cout<<"Stack overflow"<<endl;
    }
    else{
        t->data=val;
        t->next=st;
        st=t;
    }
}

int pop(stack_node*& st){
    if(st==NULL){
        cout<<"Stack underflow"<<endl;
        return -1;
    }

    int x=st->data;
    stack_node* del=st;
    st=st->next;

    delete del;

    return x;
}

void peek(stack_node* st,int index){
    for(int i=0;i<index-1 && st;i++){
        st=st->next;
    }

    if(st){
        cout<<st->data<<endl;
    }
    else{
        cout<<"Invalid index"<<endl;
    }
}

bool isEmpty(stack_node* st){
    return st==NULL;
}

bool isFull(stack_node* st){
    (void)st;

    stack_node* t=new(nothrow) stack_node;

    if(t==NULL){
        return true;
    }

    delete t;
    return false;
}

void display(stack_node* st){
    cout<<"STACK: ";

    while(st){
        cout<<st->data<<" ";
        st=st->next;
    }

    cout<<endl;
}

void clear(stack_node*& st){
    while(st){
        pop(st);
    }
}

int main(){
    stack_node* s=NULL;

    push(s,10);
    push(s,20);
    push(s,30);
    push(s,40);
    push(s,50);

    cout<<"Popped: "<<pop(s)<<endl;
    cout<<"Popped: "<<pop(s)<<endl;

    cout<<"Peek: ";
    peek(s,3);

    cout<<"Empty: "<<isEmpty(s)<<endl;
    cout<<"Full: "<<isFull(s)<<endl;

    display(s);

    clear(s);

    return 0;
}