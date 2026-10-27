
#include<iostream>
using namespace std;

// An AVL tree is a Binary Search Tree in which the balance factor
// of every node must be -1, 0, or +1.
//
// Balance Factor (BF) = Height of Left Subtree - Height of Right Subtree
//
// BF = +1 : left subtree is one level taller
// BF =  0 : both subtrees have equal height
// BF = -1 : right subtree is one level taller
//
// If BF becomes greater than +1 or less than -1, that node is
// unbalanced and rotations may be required.

struct Node{
    Node* lchild;
    int data;
    Node* rchild;
};

int Height(Node* p){
    if(p==NULL) return 0;

    int x = Height(p->lchild);
    int y = Height(p->rchild);

    return x>y ? x+1 : y+1;
}

int BalanceFactor(Node* p){
    if(p==NULL) return 0;

    return Height(p->lchild) - Height(p->rchild);
}

// Checks whether every node satisfies the AVL balance condition.
// This function checks balance; it does not check the BST ordering property.
bool IsBalanced(Node* p){
    if(p==NULL) return true;

    int bf = BalanceFactor(p);

    if(bf < -1 || bf > 1) return false;

    return IsBalanced(p->lchild) && IsBalanced(p->rchild);
}

Node* CreateNode(int key){
    Node* p = new Node;
    p->lchild = NULL;
    p->data = key;
    p->rchild = NULL;
    return p;
}

void DisplayBalanceFactors(Node* p){
    if(p==NULL) return;

    DisplayBalanceFactors(p->lchild);

    cout << "Node: " << p->data
         << ", Height: " << Height(p)
         << ", BF: " << BalanceFactor(p) << endl;

    DisplayBalanceFactors(p->rchild);
}

void DeleteTree(Node* p){
    if(p==NULL) return;

    DeleteTree(p->lchild);
    DeleteTree(p->rchild);
    delete p;
}

int main(){
    // Construct a tree manually to observe height and balance factor.
    //
    //       20
    //      /  \
    //    10    30
    //             \
    //              40
    //                 \
    //                  50
    //
    // Node 20 has BF = 1 - 3 = -2, so this tree is not AVL-balanced.

    Node* root = CreateNode(20);
    root->lchild = CreateNode(10);
    root->rchild = CreateNode(30);
    root->rchild->rchild = CreateNode(40);
    root->rchild->rchild->rchild = CreateNode(50);

    DisplayBalanceFactors(root);

    cout << "Tree is AVL-balanced: "
         << (IsBalanced(root) ? "Yes" : "No") << endl;

    DeleteTree(root);

    return 0;
}
