
#include<iostream>
using namespace std;

class Queue{
private:
    int size;
    int front;
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
    front=0;
    rear=0;
    Q=new int[size];
}

Queue::~Queue(){
    delete[] Q;
}

bool Queue::isEmpty(){
    return front==rear;
}

bool Queue::isFull(){
    return (rear+1)%size==front;
}

void Queue::enqueue(int x){
    if(isFull()){
        cout<<"Queue Overflow"<<endl;
        return;
    }

    rear=(rear+1)%size;
    Q[rear]=x;
}

int Queue::dequeue(){
    if(isEmpty()){
        cout<<"Queue Underflow"<<endl;
        return -1;
    }

    front=(front+1)%size;
    return Q[front];
}

void Queue::display(){
    if(isEmpty()){
        cout<<"Queue is empty"<<endl;
        return;
    }

    int i=(front+1)%size;

    while(true){
        cout<<Q[i];

        if(i==rear)
            break;

        cout<<" <- ";
        i=(i+1)%size;
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
    cout<<"Dequeued: "<<q.dequeue()<<endl;

    q.display();

    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);

    q.display();

    return 0;
}
