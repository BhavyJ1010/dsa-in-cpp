
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

// Height is the number of nodes on the longest root-to-leaf path.
// An empty tree has height 0.
int height(node* p){
    if(p==NULL)
        return 0;

    int x=height(p->Lchild);
    int y=height(p->Rchild);

    return x>y ? x+1 : y+1;
}

// Count every node in the left and right subtrees, then count the root.
int count_nodes(node* p){
    if(p==NULL)
        return 0;

    return count_nodes(p->Lchild)+count_nodes(p->Rchild)+1;
}

// Add the values in both subtrees and the current node.
int sum_nodes(node* p){
    if(p==NULL)
        return 0;

    return sum_nodes(p->Lchild)+sum_nodes(p->Rchild)+p->data;
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
    // Node 2 has children 4 and 5.
    node* root=create_node(1);
    root->Lchild=create_node(2);
    root->Rchild=create_node(3);
    root->Lchild->Lchild=create_node(4);
    root->Lchild->Rchild=create_node(5);

    cout<<"Preorder: ";
    preorder(root);
    cout<<"\nHeight: "<<height(root);
    cout<<"\nTotal nodes: "<<count_nodes(root);
    cout<<"\nSum of node values: "<<sum_nodes(root)<<endl;

    destroy_tree(root);
    return 0;
}
