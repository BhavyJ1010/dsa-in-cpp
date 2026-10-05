#include<iostream>
using namespace std;

struct stack{
    int size;
    int top;
    int* s;
};

void create(stack* st){
    cout<<"Enter size of stack: ";
    cin>>st->size;
    st->top=-1;
    st->s=new int[st->size];
}

void push(stack* st,int val){
    if(st->top+1==st->size){
        cout<<"Stack overflow"<<endl;
    }
    else{
        st->s[st->top+1]=val;
        st->top++;
    }
}

int pop(stack* st){
    if(st->top==-1){
        cout<<"Stack underflow"<<endl;
        return -1;
    }

    int x=st->s[st->top];
    st->top--;
    return x;
}

void peek(stack st,int index){
    if(index>=1 && index<=st.top+1){
        cout<<st.s[st.top-(index-1)]<<endl;
    }
    else{
        cout<<"Element not at given index"<<endl;
    }
}

bool isEmpty(stack st){
    return st.top==-1;
}

bool isFull(stack st){
    return st.top+1==st.size;
}

void display(stack st){
    cout<<"STACK: ";
    for(int i=st.top;i>=0;i--){
        cout<<st.s[i]<<" ";
    }
    cout<<endl;
}

int main(){
    stack s;
    create(&s);

    push(&s,10);
    push(&s,20);
    push(&s,30);

    cout<<"Popped: "<<pop(&s)<<endl;

    cout<<"Peek: ";
    peek(s,1);

    cout<<"Empty: "<<isEmpty(s)<<endl;
    cout<<"Full: "<<isFull(s)<<endl;

    display(s);

    delete[] s.s;

    return 0;
}