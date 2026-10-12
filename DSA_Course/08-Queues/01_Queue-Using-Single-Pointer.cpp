#include<iostream>
using namespace std;

class Queue{
private:
    int size;
    int rear;
    int* Q;

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
    rear=-1;
    Q=new int[size];
}

Queue::~Queue(){
    delete[] Q;
}

bool Queue::isEmpty(){
    return rear==-1;
}

bool Queue::isFull(){
    return rear==size-1;
}

void Queue::enqueue(int x){

    if(isFull()){
        cout<<"Queue Overflow"<<endl;
        return;
    }

    rear++;
    Q[rear]=x;
}

int Queue::dequeue(){

    if(isEmpty()){
        cout<<"Queue Underflow"<<endl;
        return -1;
    }

    int x=Q[0];

    for(int i=0;i<rear;i++){
        Q[i]=Q[i+1];
    }

    rear--;

    return x;
}

void Queue::display(){

    for(int i=0;i<=rear;i++){
        cout<<Q[i];

        if(i<rear)
            cout<<" <- ";
    }

    cout<<endl;
}

int main(){

    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    cout<<"Dequeued: "<<q.dequeue()<<endl;

    q.display();

    q.enqueue(50);

    q.display();

    return 0;
}