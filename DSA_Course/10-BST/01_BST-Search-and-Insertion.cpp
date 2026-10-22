
#include<iostream>
using namespace std;

struct node{
    node* Lchild;
    int data;
    node* Rchild;
};

// In a BST, smaller values go left and larger values go right.
// This version ignores duplicate values.
void insertbst(node*& root,int data){
    node* t=new node;
    t->data=data;
    t->Lchild=NULL;
    t->Rchild=NULL;

    if(root==NULL){
        root=t;
        return;
    }

    node* p=root;
    node* r=NULL;

    while(p!=NULL){
        r=p;

        if(data<p->data)
            p=p->Lchild;
        else if(data>p->data)
            p=p->Rchild;
        else{
            delete t;
            return;
        }
    }

    if(data<r->data)
        r->Lchild=t;
    else
        r->Rchild=t;
}

// Search follows only one branch at each step.
// If the key is absent, return NULL.
node* search(node* root,int data){
    node* p=root;

    while(p!=NULL){
        if(data==p->data)
            return p;
        else if(data<p->data)
            p=p->Lchild;
        else
            p=p->Rchild;
    }

    return NULL;
}

void inorder(node* p){
    if(p!=NULL){
        inorder(p->Lchild);
        cout<<p->data<<" ";
        inorder(p->Rchild);
    }
}

void destroy_tree(node* p){
    if(p!=NULL){
        destroy_tree(p->Lchild);
        destroy_tree(p->Rchild);
        delete p;
    }
}

int main(){
    node* root=NULL;

    insertbst(root,10);
    insertbst(root,20);
    insertbst(root,25);
    insertbst(root,15);
    insertbst(root,5);
    insertbst(root,10); // Duplicate: ignored.

    cout<<"Inorder: ";
    inorder(root);

    node* temp=search(root,20);
    if(temp!=NULL)
        cout<<"\nFound: "<<temp->data;
    else
        cout<<"\nNode not found";

    temp=search(root,99);
    if(temp!=NULL)
        cout<<"\nFound: "<<temp->data;
    else
        cout<<"\nNode not found";

    cout<<endl;
    destroy_tree(root);
    return 0;
}
