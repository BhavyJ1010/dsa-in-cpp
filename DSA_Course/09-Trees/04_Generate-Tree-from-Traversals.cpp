
#include<iostream>
using namespace std;

struct node{
    node* Lchild;
    int data;
    node* Rchild;
};

int search(int in[],int start,int end,int key){
    for(int i=start;i<=end;i++){
        if(in[i]==key)
            return i;
    }

    return -1;
}

// Preorder gives the root.
// Inorder tells us which nodes belong to each subtree.
// This assumes all node values are distinct.
node* generate_tree(int pre[],int in[],int start,int end,int& preIndex){
    if(start>end)
        return NULL;

    int x=pre[preIndex++];
    node* t=new node;
    t->data=x;
    t->Lchild=NULL;
    t->Rchild=NULL;

    int inIndex=search(in,start,end,x);

    t->Lchild=generate_tree(pre,in,start,inIndex-1,preIndex);
    t->Rchild=generate_tree(pre,in,inIndex+1,end,preIndex);

    return t;
}

void preorder(node* p){
    if(p){
        cout<<p->data<<" ";
        preorder(p->Lchild);
        preorder(p->Rchild);
    }
}

void inorder(node* p){
    if(p){
        inorder(p->Lchild);
        cout<<p->data<<" ";
        inorder(p->Rchild);
    }
}

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
    int pre[]={1,2,4,5,3};
    int in[]={4,2,5,1,3};
    int n=5;
    int preIndex=0;

    node* root=generate_tree(pre,in,0,n-1,preIndex);

    cout<<"Preorder: ";
    preorder(root);

    cout<<"\nInorder: ";
    inorder(root);

    cout<<"\nPostorder: ";
    postorder(root);

    cout<<endl;

    destroy_tree(root);
    return 0;
}
