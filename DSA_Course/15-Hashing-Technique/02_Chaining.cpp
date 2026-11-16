#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

const int SIZE=10;

int Hash(int key){
    return key%SIZE;
}

void SortedInsert(Node* &H, int key){
    Node* t=new Node;
    t->data=key;
    t->next=nullptr;

    if(H==nullptr || H->data>=key){
        t->next=H;
        H=t;
        return;
    }

    Node* p=H;

    while(p->next!=nullptr && p->next->data<key){
        p=p->next;
    }

    t->next=p->next;
    p->next=t;
}

void Insert(Node* HT[], int key){
    int index=Hash(key);
    SortedInsert(HT[index],key);
}

bool Search(Node* HT[], int key){
    int index=Hash(key);
    Node* p=HT[index];

    while(p!=nullptr){
        if(p->data==key){
            return true;
        }

        if(p->data>key){
            return false;
        }

        p=p->next;
    }

    return false;
}

void Display(Node* HT[]){
    for(int i=0;i<SIZE;i++){
        cout<<i<<" : ";

        Node* p=HT[i];

        while(p!=nullptr){
            cout<<p->data<<" -> ";
            p=p->next;
        }

        cout<<"NULL"<<endl;
    }
}

void DeleteTable(Node* HT[]){
    for(int i=0;i<SIZE;i++){
        Node* p=HT[i];

        while(p!=nullptr){
            Node* q=p;
            p=p->next;
            delete q;
        }
    }
}

int main(){
    Node* HT[SIZE]={nullptr};

    int A[]={16,12,25,39,6,122,5,68,75};
    int n=sizeof(A)/sizeof(A[0]);

    for(int i=0;i<n;i++){
        Insert(HT,A[i]);
    }

    Display(HT);

    int key=6;
    cout<<"Search "<<key<<": "
        <<(Search(HT,key)?"Found":"Not Found")<<endl;

    key=95;
    cout<<"Search "<<key<<": "
        <<(Search(HT,key)?"Found":"Not Found")<<endl;

    DeleteTable(HT);

    return 0;
}
