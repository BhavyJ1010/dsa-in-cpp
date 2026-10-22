
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

// A leaf node has no children.
int count_leaf_nodes(node* p){
    if(p==NULL)
        return 0;

    if(p->Lchild==NULL && p->Rchild==NULL)
        return 1;

    return count_leaf_nodes(p->Lchild)+count_leaf_nodes(p->Rchild);
}

// Degree 1 means the node has exactly one child.
int count_degree_one_nodes(node* p){
    if(p==NULL)
        return 0;

    int count=0;

    if((p->Lchild==NULL && p->Rchild!=NULL) ||
       (p->Lchild!=NULL && p->Rchild==NULL))
        count=1;

    return count_degree_one_nodes(p->Lchild)+
           count_degree_one_nodes(p->Rchild)+count;
}

// Degree 2 means the node has both left and right children.
int count_degree_two_nodes(node* p){
    if(p==NULL)
        return 0;

    int count=0;

    if(p->Lchild!=NULL && p->Rchild!=NULL)
        count=1;

    return count_degree_two_nodes(p->Lchild)+
           count_degree_two_nodes(p->Rchild)+count;
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
    // Example tree with 8 nodes.
    node* root=create_node(1);
    root->Lchild=create_node(2);
    root->Rchild=create_node(3);
    root->Lchild->Lchild=create_node(4);
    root->Lchild->Rchild=create_node(5);
    root->Rchild->Rchild=create_node(6);
    root->Lchild->Rchild->Lchild=create_node(7);
    root->Rchild->Rchild->Rchild=create_node(8);

    cout<<"Preorder: ";
    preorder(root);

    cout<<"\nLeaf nodes: "<<count_leaf_nodes(root);
    cout<<"\nDegree 1 nodes: "<<count_degree_one_nodes(root);
    cout<<"\nDegree 2 nodes: "<<count_degree_two_nodes(root)<<endl;

    destroy_tree(root);
    return 0;
}
