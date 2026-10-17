
#include<iostream>
#include<stack>
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

// Preorder: Root, Left, Right
void preorder(node* root){
    if(root==NULL)
        return;

    stack<node*> stk;
    stk.push(root);

    while(!stk.empty()){
        node* p=stk.top();
        stk.pop();

        cout<<p->data<<" ";

        // Push right first so left is processed first.
        if(p->Rchild)
            stk.push(p->Rchild);

        if(p->Lchild)
            stk.push(p->Lchild);
    }
}

// Inorder: Left, Root, Right
void inorder(node* root){
    stack<node*> stk;
    node* p=root;

    while(p || !stk.empty()){
        if(p){
            stk.push(p);
            p=p->Lchild;
        }
        else{
            p=stk.top();
            stk.pop();

            cout<<p->data<<" ";
            p=p->Rchild;
        }
    }
}

// Postorder: Left, Right, Root
// Two stacks make the order easier to obtain.
void postorder(node* root){
    if(root==NULL)
        return;

    stack<node*> stk1,stk2;
    stk1.push(root);

    while(!stk1.empty()){
        node* p=stk1.top();
        stk1.pop();

        stk2.push(p);

        if(p->Lchild)
            stk1.push(p->Lchild);

        if(p->Rchild)
            stk1.push(p->Rchild);
    }

    while(!stk2.empty()){
        cout<<stk2.top()->data<<" ";
        stk2.pop();
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
    // Example tree: root 1, children 2 and 3,
    // with 4 and 5 under node 2.
    node* root=create_node(1);
    root->Lchild=create_node(2);
    root->Rchild=create_node(3);
    root->Lchild->Lchild=create_node(4);
    root->Lchild->Rchild=create_node(5);

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
