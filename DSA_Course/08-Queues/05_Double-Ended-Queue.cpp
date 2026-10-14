
#include<iostream>
using namespace std;

class Deque{
private:
    int size;
    int front;
    int count;
    int* Q;

public:
    Deque(int size);
    ~Deque();

    bool isEmpty();
    bool isFull();

    void enqueueFront(int x);
    void enqueueRear(int x);
    int dequeueFront();
    int dequeueRear();
    void display();
};

Deque::Deque(int size){
    this->size=size;
    front=0;
    count=0;
    Q=new int[size];
}

Deque::~Deque(){
    delete[] Q;
}

bool Deque::isEmpty(){
    return count==0;
}

bool Deque::isFull(){
    return count==size;
}

void Deque::enqueueFront(int x){
    if(isFull()){
        cout<<"Deque Overflow"<<endl;
        return;
    }

    front=(front-1+size)%size;
    Q[front]=x;
    count++;
}

void Deque::enqueueRear(int x){
    if(isFull()){
        cout<<"Deque Overflow"<<endl;
        return;
    }

    int rear=(front+count)%size;
    Q[rear]=x;
    count++;
}

int Deque::dequeueFront(){
    if(isEmpty()){
        cout<<"Deque Underflow"<<endl;
        return -1;
    }

    int x=Q[front];
    front=(front+1)%size;
    count--;

    return x;
}

int Deque::dequeueRear(){
    if(isEmpty()){
        cout<<"Deque Underflow"<<endl;
        return -1;
    }

    int rear=(front+count-1)%size;
    int x=Q[rear];
    count--;

    return x;
}

void Deque::display(){
    for(int i=0;i<count;i++){
        cout<<Q[(front+i)%size];

        if(i<count-1)
            cout<<" <- ";
    }

    cout<<endl;
}

int main(){
    Deque d(5);

    d.enqueueRear(20);
    d.enqueueRear(30);
    d.enqueueFront(10);
    d.enqueueFront(5);

    d.display();

    cout<<"Removed from front: "<<d.dequeueFront()<<endl;
    cout<<"Removed from rear: "<<d.dequeueRear()<<endl;

    d.display();

    d.enqueueRear(40);
    d.enqueueFront(1);

    d.display();

    return 0;
}
