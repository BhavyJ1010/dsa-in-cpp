#include<iostream>
#include<new>
using namespace std;

class stack_node{
public:
    int data;
    stack_node* next;
};

class stack{
private:
    stack_node* top;

public:
    stack(){
        top=NULL;
    }

    ~stack(){
        while(top){
            stack_node* del=top;
            top=top->next;
            delete del;
        }
    }

    void push(int val){
        stack_node* t=new(nothrow) stack_node;

        if(t==NULL){
            cout<<"Stack overflow"<<endl;
        }
        else{
            t->data=val;
            t->next=top;
            top=t;
        }
    }

    int pop(){
        if(top==NULL){
            cout<<"Stack underflow"<<endl;
            return -1;
        }

        int x=top->data;
        stack_node* del=top;
        top=top->next;

        delete del;

        return x;
    }

    void peek(int index){
        stack_node* t=top;

        for(int i=0;i<index-1 && t;i++){
            t=t->next;
        }

        if(t){
            cout<<t->data<<endl;
        }
        else{
            cout<<"Invalid index"<<endl;
        }
    }

    bool isEmpty(){
        return top==NULL;
    }

    bool isFull(){
        stack_node* t=new(nothrow) stack_node;

        if(t==NULL){
            return true;
        }

        delete t;
        return false;
    }

    void display(){
        stack_node* t=top;

        cout<<"STACK: ";

        while(t){
            cout<<t->data<<" ";
            t=t->next;
        }

        cout<<endl;
    }
};

int main(){
    stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    s.display();

    cout<<"Popped: "<<s.pop()<<endl;
    cout<<"Popped: "<<s.pop()<<endl;

    cout<<"Peek: ";
    s.peek(3);

    cout<<"Empty: "<<s.isEmpty()<<endl;
    cout<<"Full: "<<s.isFull()<<endl;

    s.display();

    return 0;
}