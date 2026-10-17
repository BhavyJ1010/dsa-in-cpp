
#include<iostream>
#include<queue>
using namespace std;

struct node{
    node* Lchild;
    int data;
    node* Rchild;
};

node* root=NULL;

// Enter -1 when a child does not exist.
void create_tree(){
    node* p;
    node* t;
    int x;
    queue<node*> q;

    cout<<"Enter root data (-1 for empty tree): ";
    cin>>x;

    if(x==-1){
        root=NULL;
        return;
    }

    root=new node;
    root->data=x;
    root->Lchild=NULL;
    root->Rchild=NULL;
    q.push(root);

    while(!q.empty()){
        p=q.front();
        q.pop();

        cout<<"Enter left child of "<<p->data<<" (-1 for none): ";
        cin>>x;

        if(x!=-1){
            t=new node;
            t->data=x;
            t->Lchild=NULL;
            t->Rchild=NULL;
            p->Lchild=t;
            q.push(t);
        }

        cout<<"Enter right child of "<<p->data<<" (-1 for none): ";
        cin>>x;

        if(x!=-1){
            t=new node;
            t->data=x;
            t->Lchild=NULL;
            t->Rchild=NULL;
            p->Rchild=t;
            q.push(t);
        }
    }
}

// Root, Left, Right
void preorder(node* p){
    if(p){
        cout<<p->data<<" ";
        preorder(p->Lchild);
        preorder(p->Rchild);
    }
}

// Left, Root, Right
void inorder(node* p){
    if(p){
        inorder(p->Lchild);
        cout<<p->data<<" ";
        inorder(p->Rchild);
    }
}

// Left, Right, Root
void postorder(node* p){
    if(p){
        postorder(p->Lchild);
        postorder(p->Rchild);
        cout<<p->data<<" ";
    }
}

void destroy_tree(node* p){
    if(p){
        destroy_tree(p->Lchild);
        destroy_tree(p->Rchild);
        delete p;
    }
}

int main(){
    create_tree();

    cout<<"\nPreorder: ";
    preorder(root);

    cout<<"\nInorder: ";
    inorder(root);

    cout<<"\nPostorder: ";
    postorder(root);

    cout<<endl;

    destroy_tree(root);
    root=NULL;

    return 0;
}
