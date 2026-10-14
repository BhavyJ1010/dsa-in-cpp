
#include<iostream>
using namespace std;

class Queue{
private:
    int size;
    int top1;
    int top2;
    int* S1;
    int* S2;

public:
    Queue(int size);
    ~Queue();

    bool isEmpty();
    bool isFull();

    void enqueue(int x);
    int dequeue();
    void display();
};

Queue::Queue(int size){
    this->size=size;
    top1=-1;
    top2=-1;

    S1=new int[size];
    S2=new int[size];
}

Queue::~Queue(){
    delete[] S1;
    delete[] S2;
}

bool Queue::isEmpty(){
    return top1==-1 && top2==-1;
}

bool Queue::isFull(){
    return top1==size-1;
}

void Queue::enqueue(int x){
    if(isFull()){
        cout<<"Queue Overflow"<<endl;
        return;
    }

    S1[++top1]=x;
}

int Queue::dequeue(){
    if(top2==-1){
        while(top1!=-1){
            S2[++top2]=S1[top1--];
        }
    }

    if(top2==-1){
        cout<<"Queue Underflow"<<endl;
        return -1;
    }

    return S2[top2--];
}

void Queue::display(){
    for(int i=top2;i>=0;i--){
        cout<<S2[i]<<" <- ";
    }

    for(int i=0;i<=top1;i++){
        cout<<S1[i];

        if(i<top1)
            cout<<" <- ";
    }

    cout<<endl;
}

int main(){
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout<<"Dequeued: "<<q.dequeue()<<endl;

    q.enqueue(40);
    q.enqueue(50);

    q.display();

    cout<<"Dequeued: "<<q.dequeue()<<endl;
    cout<<"Dequeued: "<<q.dequeue()<<endl;

    q.display();

    cout<<"Dequeued: "<<q.dequeue()<<endl;
    cout<<"Dequeued: "<<q.dequeue()<<endl;

    cout<<"Empty: "<<q.isEmpty()<<endl;

    return 0;
}
