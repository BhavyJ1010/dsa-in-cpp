
#include<iostream>
using namespace std;

struct Node{
    Node* lchild;
    int data;
    Node* rchild;
    int height;
};

int NodeHeight(Node* p){
    if(p==NULL) return 0;

    int x = p->lchild ? p->lchild->height : 0;
    int y = p->rchild ? p->rchild->height : 0;

    return x>y ? x+1 : y+1;
}

int BalanceFactor(Node* p){
    if(p==NULL) return 0;

    int x = p->lchild ? p->lchild->height : 0;
    int y = p->rchild ? p->rchild->height : 0;

    return x-y;
}

// LL Rotation: right rotation at p.
//
//         p                 q
//        / \               / \
//       q   T3    ->      T1  p
//      / \                   / \
//     T1  T2                T2 T3
//
// The links are changed first, then heights are updated from
// the lower node to the new root.

Node* LLRotation(Node* p){
    Node* q = p->lchild;
    Node* T2 = q->rchild;

    q->rchild = p;
    p->lchild = T2;

    p->height = NodeHeight(p);
    q->height = NodeHeight(q);

    return q;
}

// RR Rotation: left rotation at p.
//
//       p                     q
//      / \                   / \
//     T1  q       ->        p  T3
//        / \               / \
//       T2 T3             T1 T2

Node* RRRotation(Node* p){
    Node* q = p->rchild;
    Node* T2 = q->lchild;

    q->lchild = p;
    p->rchild = T2;

    p->height = NodeHeight(p);
    q->height = NodeHeight(q);

    return q;
}

// LR Rotation: left rotation at the left child, then
// right rotation at p.
//
//       p                 p                  q
//      / \               / \                / \
//     A   T3    ->      q   T3     ->       A   p
//        / \           / \                    / \
//       B   C         A   B                  C   T3
// where q is the left child and B is q's right child.
//
// Implemented as two single rotations.

Node* LRRotation(Node* p){
    p->lchild = RRRotation(p->lchild);
    return LLRotation(p);
}

// RL Rotation: right rotation at the right child, then
// left rotation at p.

Node* RLRotation(Node* p){
    p->rchild = LLRotation(p->rchild);
    return RRRotation(p);
}

Node* Insert(Node* p, int key){
    if(p==NULL){
        Node* t = new Node;
        t->lchild = NULL;
        t->data = key;
        t->rchild = NULL;
        t->height = 1;
        return t;
    }

    if(key < p->data){
        p->lchild = Insert(p->lchild, key);
    }
    else if(key > p->data){
        p->rchild = Insert(p->rchild, key);
    }
    else{
        // Duplicate keys are not inserted.
        return p;
    }

    // Update height after insertion into a subtree.
    p->height = NodeHeight(p);

    int bf = BalanceFactor(p);

    // LL case: left subtree is too tall, and key was inserted
    // into the left subtree of the left child.
    if(bf > 1 && key < p->lchild->data){
        return LLRotation(p);
    }

    // RR case: right subtree is too tall, and key was inserted
    // into the right subtree of the right child.
    if(bf < -1 && key > p->rchild->data){
        return RRRotation(p);
    }

    // LR case: left subtree is too tall, and key was inserted
    // into the right subtree of the left child.
    if(bf > 1 && key > p->lchild->data){
        return LRRotation(p);
    }

    // RL case: right subtree is too tall, and key was inserted
    // into the left subtree of the right child.
    if(bf < -1 && key < p->rchild->data){
        return RLRotation(p);
    }

    return p;
}

void Inorder(Node* p){
    if(p==NULL) return;

    Inorder(p->lchild);
    cout << p->data << " ";
    Inorder(p->rchild);
}

void DeleteTree(Node* p){
    if(p==NULL) return;

    DeleteTree(p->lchild);
    DeleteTree(p->rchild);
    delete p;
}

void TestRotation(int keys[], int n, const char* name){
    Node* root = NULL;

    for(int i=0; i<n; i++){
        root = Insert(root, keys[i]);
    }

    cout << name << endl;
    cout << "Inorder: ";
    Inorder(root);
    cout << endl;
    cout << "Root: " << root->data << endl;
    cout << "Height: " << root->height << endl;
    cout << "--------------------" << endl;

    DeleteTree(root);
}

int main(){
    int LL[] = {30, 20, 10};
    int RR[] = {10, 20, 30};
    int LR[] = {30, 10, 20};
    int RL[] = {10, 30, 20};

    TestRotation(LL, 3, "LL Rotation");
    TestRotation(RR, 3, "RR Rotation");
    TestRotation(LR, 3, "LR Rotation");
    TestRotation(RL, 3, "RL Rotation");

    return 0;
}
