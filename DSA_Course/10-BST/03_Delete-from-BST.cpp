
#include<iostream>
using namespace std;

struct node{
    node* Lchild;
    int data;
    node* Rchild;
};

node* create_node(int key){
    node* t=new node;
    t->data=key;
    t->Lchild=NULL;
    t->Rchild=NULL;
    return t;
}

node* insertbst(node* p,int key){
    if(p==NULL)
        return create_node(key);

    if(key<p->data)
        p->Lchild=insertbst(p->Lchild,key);
    else if(key>p->data)
        p->Rchild=insertbst(p->Rchild,key);

    return p;
}

node* inorder_predecessor(node* p){
    p=p->Lchild;
    while(p!=NULL && p->Rchild!=NULL)
        p=p->Rchild;
    return p;
}

node* inorder_successor(node* p){
    p=p->Rchild;
    while(p!=NULL && p->Lchild!=NULL)
        p=p->Lchild;
    return p;
}

// Height is measured in nodes. Empty tree has height 0.
int height(node* p){
    if(p==NULL)
        return 0;

    int x=height(p->Lchild);
    int y=height(p->Rchild);

    return (x>y ? x : y)+1;
}

// Delete a key. For two children, use the predecessor
// if the left subtree is taller; otherwise use the successor.
node* delete_node(node* p,int key){
    if(p==NULL)
        return NULL;

    if(key<p->data)
        p->Lchild=delete_node(p->Lchild,key);
    else if(key>p->data)
        p->Rchild=delete_node(p->Rchild,key);
    else{
        if(p->Lchild==NULL){
            node* q=p->Rchild;
            delete p;
            return q;
        }
        else if(p->Rchild==NULL){
            node* q=p->Lchild;
            delete p;
            return q;
        }
        else if(height(p->Lchild)>height(p->Rchild)){
            node* q=inorder_predecessor(p);
            p->data=q->data;
            p->Lchild=delete_node(p->Lchild,q->data);
        }
        else{
            node* q=inorder_successor(p);
            p->data=q->data;
            p->Rchild=delete_node(p->Rchild,q->data);
        }
    }

    return p;
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
    int values[]={50,30,70,20,40,60,80,35};

    for(int x:values)
        root=insertbst(root,x);

    cout<<"Before deletion: ";
    inorder(root);

    root=delete_node(root,20); // Leaf node.
    cout<<"\nAfter deleting 20: ";
    inorder(root);

    root=delete_node(root,30); // Node with one child.
    cout<<"\nAfter deleting 30: ";
    inorder(root);

    root=delete_node(root,50); // Node with two children.
    cout<<"\nAfter deleting 50: ";
    inorder(root);

    root=delete_node(root,999); // Missing key.
    cout<<"\nAfter attempting to delete 999: ";
    inorder(root);

    cout<<endl;
    destroy_tree(root);
    return 0;
}
