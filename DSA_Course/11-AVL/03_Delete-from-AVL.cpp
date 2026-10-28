
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

Node* LLRotation(Node* p){
    Node* q = p->lchild;
    Node* T2 = q->rchild;

    q->rchild = p;
    p->lchild = T2;

    p->height = NodeHeight(p);
    q->height = NodeHeight(q);

    return q;
}

Node* RRRotation(Node* p){
    Node* q = p->rchild;
    Node* T2 = q->lchild;

    q->lchild = p;
    p->rchild = T2;

    p->height = NodeHeight(p);
    q->height = NodeHeight(q);

    return q;
}

Node* LRRotation(Node* p){
    p->lchild = RRRotation(p->lchild);
    return LLRotation(p);
}

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
        return p;
    }

    p->height = NodeHeight(p);
    int bf = BalanceFactor(p);

    if(bf > 1 && key < p->lchild->data)
        return LLRotation(p);

    if(bf < -1 && key > p->rchild->data)
        return RRRotation(p);

    if(bf > 1 && key > p->lchild->data)
        return LRRotation(p);

    if(bf < -1 && key < p->rchild->data)
        return RLRotation(p);

    return p;
}

// Returns the node with the largest key in a subtree.
// This is the inorder predecessor when called on the left subtree.

Node* InPre(Node* p){
    while(p && p->rchild!=NULL){
        p = p->rchild;
    }

    return p;
}

Node* Delete(Node* p, int key){
    if(p==NULL) return NULL;

    // First locate the key. Do not delete a leaf merely because
    // recursion has reached it: it must actually match the key.

    if(key < p->data){
        p->lchild = Delete(p->lchild, key);
    }
    else if(key > p->data){
        p->rchild = Delete(p->rchild, key);
    }
    else{
        // The key has been found.

        // Case 1 and 2: leaf or node with one child.
        if(p->lchild==NULL || p->rchild==NULL){
            Node* q = p->lchild ? p->lchild : p->rchild;

            // If q is NULL, p is a leaf.
            // Otherwise, q is the only child.
            delete p;
            return q;
        }

        // Case 3: node has two children.
        // Replace its value with its inorder predecessor, then
        // remove the predecessor from the left subtree.
        Node* q = InPre(p->lchild);
        p->data = q->data;
        p->lchild = Delete(p->lchild, q->data);
    }

    // The deleted node may have been the root of this subtree.
    if(p==NULL) return NULL;

    p->height = NodeHeight(p);
    int bf = BalanceFactor(p);

    // After deletion, choose rotations using the balance factor
    // of the heavy child, not the key being deleted.

    // Left-heavy: LL or LR.
    if(bf > 1 && BalanceFactor(p->lchild) >= 0){
        return LLRotation(p);
    }

    if(bf > 1 && BalanceFactor(p->lchild) < 0){
        return LRRotation(p);
    }

    // Right-heavy: RR or RL.
    if(bf < -1 && BalanceFactor(p->rchild) <= 0){
        return RRRotation(p);
    }

    if(bf < -1 && BalanceFactor(p->rchild) > 0){
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

void Display(Node* p){
    if(p==NULL) return;

    cout << "Node: " << p->data
         << ", Height: " << p->height
         << ", BF: " << BalanceFactor(p) << endl;

    Display(p->lchild);
    Display(p->rchild);
}

void DeleteTree(Node* p){
    if(p==NULL) return;

    DeleteTree(p->lchild);
    DeleteTree(p->rchild);
    delete p;
}

int main(){
    Node* root = NULL;

    int keys[] = {50, 30, 70, 20, 40, 60, 80, 35};

    for(int i=0; i<8; i++){
        root = Insert(root, keys[i]);
    }

    cout << "Initial inorder: ";
    Inorder(root);
    cout << endl;

    // Delete a leaf.
    root = Delete(root, 20);
    cout << "After deleting 20: ";
    Inorder(root);
    cout << endl;

    // Delete a node with one child.
    root = Delete(root, 30);
    cout << "After deleting 30: ";
    Inorder(root);
    cout << endl;

    // Delete a node with two children.
    root = Delete(root, 70);
    cout << "After deleting 70: ";
    Inorder(root);
    cout << endl;

    // Deleting a missing key must not delete another node.
    root = Delete(root, 999);
    cout << "After deleting missing key 999: ";
    Inorder(root);
    cout << endl;

    cout << "Final tree:" << endl;
    Display(root);

    DeleteTree(root);

    return 0;
}
