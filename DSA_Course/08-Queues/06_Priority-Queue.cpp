
#include<iostream>
using namespace std;

struct element{
    int data;
    int priority;
};

class PriorityQueue{
private:
    int size;
    int rear;
    element* Q;

public:
    PriorityQueue(int size);
    ~PriorityQueue();

    bool isEmpty();
    bool isFull();

    void enqueue(int x,int priority);
    int dequeue();
    void display();
};

PriorityQueue::PriorityQueue(int size){
    this->size=size;
    rear=-1;
    Q=new element[size];
}

PriorityQueue::~PriorityQueue(){
    delete[] Q;
}

bool PriorityQueue::isEmpty(){
    return rear==-1;
}

bool PriorityQueue::isFull(){
    return rear==size-1;
}

void PriorityQueue::enqueue(int x,int priority){
    if(isFull()){
        cout<<"Priority Queue Overflow"<<endl;
        return;
    }

    rear++;
    Q[rear].data=x;
    Q[rear].priority=priority;
}

int PriorityQueue::dequeue(){
    if(isEmpty()){
        cout<<"Priority Queue Underflow"<<endl;
        return -1;
    }

    int highest=0;

    for(int i=1;i<=rear;i++){
        if(Q[i].priority<Q[highest].priority){
            highest=i;
        }
    }

    int x=Q[highest].data;

    for(int i=highest;i<rear;i++){
        Q[i]=Q[i+1];
    }

    rear--;

    return x;
}

void PriorityQueue::display(){
    for(int i=0;i<=rear;i++){
        cout<<"("<<Q[i].data<<", P="
            <<Q[i].priority<<") ";

    }
    cout<<endl;
}

int main(){
    PriorityQueue q(5);

    q.enqueue(10,3);
    q.enqueue(20,1);
    q.enqueue(30,2);
    q.enqueue(40,1);

    q.display();

    cout<<"Removed: "<<q.dequeue()<<endl;
    cout<<"Removed: "<<q.dequeue()<<endl;

    q.display();

    return 0;
}
