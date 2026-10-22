
#include<iostream>
using namespace std;

struct node{
    node* Lchild;
    int data;
    node* Rchild;
};

node* create_node(int x){
    node* t=new node;
    t->data=x;
    t->Lchild=NULL;
    t->Rchild=NULL;
    return t;
}

// A leaf node has no children, so its degree is 0.
int count_degree_zero(node* p){
    if(p==NULL)
        return 0;

    if(p->Lchild==NULL && p->Rchild==NULL)
        return 1;

    return count_degree_zero(p->Lchild)+count_degree_zero(p->Rchild);
}

// A node with exactly one child has degree 1.
int count_degree_one(node* p){
    if(p==NULL)
        return 0;

    int count=0;
    if((p->Lchild==NULL && p->Rchild!=NULL) ||
       (p->Lchild!=NULL && p->Rchild==NULL))
        count=1;

    return count+count_degree_one(p->Lchild)+count_degree_one(p->Rchild);
}

// A node with both children has degree 2.
int count_degree_two(node* p){
    if(p==NULL)
        return 0;

    int count=0;
    if(p->Lchild!=NULL && p->Rchild!=NULL)
        count=1;

    return count+count_degree_two(p->Lchild)+count_degree_two(p->Rchild);
}

void preorder(node* p){
    if(p){
        cout<<p->data<<" ";
        preorder(p->Lchild);
        preorder(p->Rchild);
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
    // Example tree: 1 has children 2 and 3.
    // Node 2 has children 4 and 5. Node 5 has one child, 6.
    node* root=create_node(1);
    root->Lchild=create_node(2);
    root->Rchild=create_node(3);
    root->Lchild->Lchild=create_node(4);
    root->Lchild->Rchild=create_node(5);
    root->Lchild->Rchild->Lchild=create_node(6);

    cout<<"Preorder: ";
    preorder(root);
    cout<<"\nDegree 0 (leaf) nodes: "<<count_degree_zero(root);
    cout<<"\nDegree 1 (one child) nodes: "<<count_degree_one(root);
    cout<<"\nDegree 2 (two children) nodes: "<<count_degree_two(root)<<endl;

    destroy_tree(root);
    return 0;
}
