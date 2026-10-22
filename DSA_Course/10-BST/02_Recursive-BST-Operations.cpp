
#include<iostream>
using namespace std;

struct node{
    node* Lchild;
    int data;
    node* Rchild;
};

// Recursive insertion returns the root of the updated subtree.
// Smaller keys go left, larger keys go right; duplicates are ignored.
node* recursive_insert(node* p,int key){
    if(p==NULL){
        node* t=new node;
        t->data=key;
        t->Lchild=NULL;
        t->Rchild=NULL;
        return t;
    }

    if(key<p->data)
        p->Lchild=recursive_insert(p->Lchild,key);
    else if(key>p->data)
        p->Rchild=recursive_insert(p->Rchild,key);

    return p;
}

// Recursive search compares the key and continues into one subtree.
node* recursive_search(node* p,int key){
    if(p==NULL || p->data==key)
        return p;

    if(key<p->data)
        return recursive_search(p->Lchild,key);
    else
        return recursive_search(p->Rchild,key);
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

    root=recursive_insert(root,10);
    root=recursive_insert(root,5);
    root=recursive_insert(root,20);
    root=recursive_insert(root,8);
    root=recursive_insert(root,30);
    root=recursive_insert(root,20); // Duplicate: ignored.

    cout<<"Inorder: ";
    inorder(root);

    node* temp=recursive_search(root,20);
    if(temp!=NULL)
        cout<<"\nFound: "<<temp->data;
    else
        cout<<"\nNode not found";

    temp=recursive_search(root,2);
    if(temp!=NULL)
        cout<<"\nFound: "<<temp->data;
    else
        cout<<"\nNode not found";

    cout<<endl;
    destroy_tree(root);
    return 0;
}
