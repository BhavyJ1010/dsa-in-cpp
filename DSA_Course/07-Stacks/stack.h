#pragma once

#include<iostream>
#include<new>
using namespace std;

template <class T>
class stack_node{
public:
    T data;
    stack_node<T>* next;
};

template <class T>
class stack{
private:
    stack_node<T>* top;

public:
    stack(){
        top=NULL;
    }

    ~stack(){
        while(top){
            stack_node<T>* del=top;
            top=top->next;
            delete del;
        }
    }

    void push(T val){
        stack_node<T>* t=new(nothrow) stack_node<T>;

        if(t==NULL){
            cout<<"Stack overflow"<<endl;
        }
        else{
            t->data=val;
            t->next=top;
            top=t;
        }
    }

    T pop(){
        if(top==NULL){
            cout<<"Stack underflow"<<endl;
            return -1;
        }

        T x=top->data;
        stack_node<T>* del=top;
        top=top->next;

        delete del;

        return x;
    }

    T StackTop(){
        if(top){
            return top->data;
        }

        return -1;
    }

    void peek(int index){
        stack_node<T>* t=top;

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
        stack_node<T>* t=new(nothrow) stack_node<T>;

        if(t==NULL){
            return true;
        }

        delete t;
        return false;
    }

    void display(){
        stack_node<T>* t=top;

        cout<<"STACK: ";

        while(t){
            cout<<t->data<<" ";
            t=t->next;
        }

        cout<<endl;
    }
};