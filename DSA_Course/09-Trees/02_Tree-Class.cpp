
#include<iostream>
#include<queue>
using namespace std;

struct node{
    node* Lchild;
    int data;
    node* Rchild;
};

class Tree{
private:
    node* root;

    void destroy(node* p){
        if(p){
            destroy(p->Lchild);
            destroy(p->Rchild);
            delete p;
        }
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

public:
    Tree(){
        root=NULL;
    }

    ~Tree(){
        destroy(root);
    }

    void create(){
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

            cout<<"Enter left child of "<<p->data
                <<" (-1 for none): ";
            cin>>x;

            if(x!=-1){
                t=new node;
                t->data=x;
                t->Lchild=NULL;
                t->Rchild=NULL;

                p->Lchild=t;
                q.push(t);
            }

            cout<<"Enter right child of "<<p->data
                <<" (-1 for none): ";
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

    // Visit nodes level by level using a queue.
    void levelorder(){
        if(root==NULL){
            cout<<"Tree is empty";
            return;
        }

        queue<node*> q;
        q.push(root);

        while(!q.empty()){
            node* p=q.front();
            q.pop();

            cout<<p->data<<" ";

            if(p->Lchild)
                q.push(p->Lchild);

            if(p->Rchild)
                q.push(p->Rchild);
        }
    }

    void display_traversals(){
        cout<<"Preorder: ";
        preorder(root);

        cout<<"\nInorder: ";
        inorder(root);

        cout<<"\nPostorder: ";
        postorder(root);

        cout<<"\nLevel order: ";
        levelorder();

        cout<<endl;
    }
};

int main(){
    Tree t;

    t.create();
    t.display_traversals();

    return 0;
}
