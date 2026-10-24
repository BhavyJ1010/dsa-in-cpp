
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

// Build a BST by inserting keys in preorder order.
node* insertbst(node* p,int key){
    if(p==NULL)
        return create_node(key);

    if(key<p->data)
        p->Lchild=insertbst(p->Lchild,key);
    else if(key>p->data)
        p->Rchild=insertbst(p->Rchild,key);

    return p;
}

// Build directly from preorder using valid value ranges.
// This implementation assumes all keys are distinct.
node* generate_bst(int pre[],int n,int& index,long long low,long long high){
    if(index==n)
        return NULL;

    int key=pre[index];

    if(key<low || key>high)
        return NULL;

    index++;

    node* t=create_node(key);
    t->Lchild=generate_bst(pre,n,index,low,(long long)key-1);
    t->Rchild=generate_bst(pre,n,index,(long long)key+1,high);

    return t;
}

void preorder(node* p){
    if(p!=NULL){
        cout<<p->data<<" ";
        preorder(p->Lchild);
        preorder(p->Rchild);
    }
}

void inorder(node* p){
    if(p!=NULL){
        inorder(p->Lchild);
        cout<<p->data<<" ";
        inorder(p->Rchild);
    }
}

int height(node* p){
    if(p==NULL)
        return 0;

    int x=height(p->Lchild);
    int y=height(p->Rchild);

    return (x>y ? x : y)+1;
}

void destroy_tree(node* p){
    if(p!=NULL){
        destroy_tree(p->Lchild);
        destroy_tree(p->Rchild);
        delete p;
    }
}

int main(){
    int pre[]={30,20,10,25,40,35,50};
    int n=sizeof(pre)/sizeof(pre[0]);
    int index=0;

    node* root=generate_bst(pre,n,index,-2147483648LL,2147483647LL);

    cout<<"Preorder: ";
    preorder(root);

    cout<<"\nInorder: ";
    inorder(root);

    cout<<"\nHeight: "<<height(root)<<endl;

    // A skewed BST can have height n, so search, insertion
    // and deletion may take O(n) instead of O(log n).
    destroy_tree(root);
    return 0;
}
