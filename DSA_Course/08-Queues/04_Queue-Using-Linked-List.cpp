
#include<iostream>
#include<new>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class Queue{
private:
    Node* front;
    Node* rear;

public:
    Queue();
    ~Queue();

    bool isEmpty();
    bool isFull();

    void enqueue(int x);
    int dequeue();
    void display();
};

Queue::Queue(){
    front=NULL;
    rear=NULL;
}

Queue::~Queue(){
    while(front){
        Node* del=front;
        front=front->next;
        delete del;
    }

    rear=NULL;
}

bool Queue::isEmpty(){
    return front==NULL;
}

bool Queue::isFull(){
    Node* t=new(nothrow) Node;

    if(t==NULL)
        return true;

    delete t;
    return false;
}

void Queue::enqueue(int x){
    Node* t=new(nothrow) Node;

    if(t==NULL){
        cout<<"Queue Overflow"<<endl;
        return;
    }

    t->data=x;
    t->next=NULL;

    if(front==NULL){
        front=rear=t;
    }
    else{
        rear->next=t;
        rear=t;
    }
}

int Queue::dequeue(){
    if(front==NULL){
        cout<<"Queue Underflow"<<endl;
        return -1;
    }

    int x=front->data;

    Node* del=front;
    front=front->next;

    if(front==NULL)
        rear=NULL;

    delete del;

    return x;
}

void Queue::display(){
    Node* p=front;

    while(p){
        cout<<p->data;

        if(p->next)
            cout<<" <- ";

        p=p->next;
    }

    cout<<endl;
}

int main(){
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    cout<<"Dequeued: "<<q.dequeue()<<endl;

    q.display();

    q.enqueue(50);
    q.enqueue(60);

    q.display();

    cout<<"Dequeued: "<<q.dequeue()<<endl;
    cout<<"Dequeued: "<<q.dequeue()<<endl;
    cout<<"Dequeued: "<<q.dequeue()<<endl;
    cout<<"Dequeued: "<<q.dequeue()<<endl;

    cout<<"Empty: "<<q.isEmpty()<<endl;

    return 0;
}
