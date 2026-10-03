#include<iostream>
#include<stack>
using namespace std;

struct node{
    int data;
    node* next;
};

node* create(int A[],int n){

    if(n==0)
        return NULL;

    node* head=new node;

    head->data=A[0];
    head->next=NULL;

    node* last=head;

    for(int i=1;i<n;i++){

        node* t=new node;

        t->data=A[i];
        t->next=NULL;

        last->next=t;
        last=t;
    }

    return head;
}

node* get_node(node* p,int index){

    while(p && index--)
        p=p->next;

    return p;
}

node* intersection(node* p,node* q){

    stack<node*> stk1;
    stack<node*> stk2;

    while(p){
        stk1.push(p);
        p=p->next;
    }

    while(q){
        stk2.push(q);
        q=q->next;
    }

    node* result=NULL;

    while(!stk1.empty() &&
          !stk2.empty() &&
          stk1.top()==stk2.top()){

        result=stk1.top();

        stk1.pop();
        stk2.pop();
    }

    return result;
}

void display(node* p){

    while(p){

        cout<<p->data<<" ";

        p=p->next;
    }

    cout<<endl;
}

int main(){

    // Create first linked list
    int A[]={1,3,5,7,9,11,13,15,17,19,21};

    node* first=create(A,11);

    // Select the node where both lists will intersect
    node* intersection_point=get_node(first,5);

    // Create second linked list
    int B[]={2,4,6,8,10};

    node* second=create(B,5);

    // Connect second list to first list
    node* tail=second;

    while(tail->next)
        tail=tail->next;

    tail->next=intersection_point;

    display(first);
    display(second);

    node* result=intersection(first,second);

    if(result)
        cout<<"Intersecting Node: "<<result->data<<endl;
    else
        cout<<"No intersection"<<endl;

    return 0;
}