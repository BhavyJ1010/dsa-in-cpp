
#include<iostream>
using namespace std;

struct Node
{
    int data;
    bool color;             // 1 = RED, 0 = BLACK
    Node* Lchild;
    Node* Rchild;
    Node* parent;
};

Node* CreateNode(int key)
{
    Node* p = new Node;

    p->data = key;
    p->color = 1;           // New node is always RED
    p->Lchild = NULL;
    p->Rchild = NULL;
    p->parent = NULL;

    return p;
}

bool IsRed(Node* p)
{
    if(p == NULL)
        return 0;

    return p->color;
}

// Left Rotation
Node* RotateLeft(Node* root, Node* p)
{
    Node* q = p->Rchild;

    p->Rchild = q->Lchild;

    if(q->Lchild)
        q->Lchild->parent = p;

    q->parent = p->parent;

    if(p->parent == NULL)
        root = q;

    else if(p == p->parent->Lchild)
        p->parent->Lchild = q;

    else
        p->parent->Rchild = q;

    q->Lchild = p;
    p->parent = q;

    return root;
}

// Right Rotation
Node* RotateRight(Node* root, Node* p)
{
    Node* q = p->Lchild;

    p->Lchild = q->Rchild;

    if(q->Rchild)
        q->Rchild->parent = p;

    q->parent = p->parent;

    if(p->parent == NULL)
        root = q;

    else if(p == p->parent->Lchild)
        p->parent->Lchild = q;

    else
        p->parent->Rchild = q;

    q->Rchild = p;
    p->parent = q;

    return root;
}

// Ordinary BST Insertion
Node* BSTInsert(Node* root, Node* p)
{
    if(root == NULL)
        return p;

    if(p->data < root->data)
    {
        root->Lchild = BSTInsert(root->Lchild, p);
        root->Lchild->parent = root;
    }

    else
    {
        root->Rchild = BSTInsert(root->Rchild, p);
        root->Rchild->parent = root;
    }

    return root;
}

// Fix Red-Black Tree property violations
Node* FixInsert(Node* root, Node* p)
{
    while(p != root && IsRed(p->parent))
    {
        Node* parent = p->parent;
        Node* grandparent = parent->parent;

        // Parent is the left child of grandparent
        if(parent == grandparent->Lchild)
        {
            Node* uncle = grandparent->Rchild;

            // CASE 1: Uncle is RED
            if(IsRed(uncle))
            {
                parent->color = 0;
                uncle->color = 0;
                grandparent->color = 1;

                p = grandparent;
            }

            else
            {
                // CASE 2: LR
                if(p == parent->Rchild)
                {
                    p = parent;
                    root = RotateLeft(root, p);

                    parent = p->parent;
                    grandparent = parent->parent;
                }

                // CASE 3: LL
                parent->color = 0;
                grandparent->color = 1;

                root = RotateRight(root, grandparent);
            }
        }

        // Parent is the right child of grandparent
        else
        {
            Node* uncle = grandparent->Lchild;

            // CASE 1: Uncle is RED
            if(IsRed(uncle))
            {
                parent->color = 0;
                uncle->color = 0;
                grandparent->color = 1;

                p = grandparent;
            }

            else
            {
                // CASE 2: RL
                if(p == parent->Lchild)
                {
                    p = parent;
                    root = RotateRight(root, p);

                    parent = p->parent;
                    grandparent = parent->parent;
                }

                // CASE 3: RR
                parent->color = 0;
                grandparent->color = 1;

                root = RotateLeft(root, grandparent);
            }
        }
    }

    // Root must always be BLACK
    root->color = 0;

    return root;
}

Node* Insert(Node* root, int key)
{
    // Check for duplicate keys before allocating a node
    Node* q = root;

    while(q)
    {
        if(key == q->data)
            return root;

        if(key < q->data)
            q = q->Lchild;
        else
            q = q->Rchild;
    }

    Node* p = CreateNode(key);

    // First perform ordinary BST insertion
    root = BSTInsert(root, p);

    // Then restore Red-Black Tree properties
    root = FixInsert(root, p);

    return root;
}

void Inorder(Node* p)
{
    if(p)
    {
        Inorder(p->Lchild);

        cout<<p->data;

        if(p->color)
            cout<<"(R) ";
        else
            cout<<"(B) ";

        Inorder(p->Rchild);
    }
}

void Display(Node* p, int space = 0)
{
    if(p == NULL)
        return;

    space += 5;

    Display(p->Rchild, space);

    cout<<endl;

    for(int i=5; i<space; i++)
        cout<<" ";

    cout<<p->data;

    if(p->color)
        cout<<"(R)";
    else
        cout<<"(B)";

    Display(p->Lchild, space);
}

void DeleteTree(Node* p)
{
    if(p)
    {
        DeleteTree(p->Lchild);
        DeleteTree(p->Rchild);
        delete p;
    }
}

int main()
{
    Node* root = NULL;

    int keys[] = {10, 20, 30, 50};

    for(int i=0; i<4; i++)
        root = Insert(root, keys[i]);

    cout<<"Inorder Traversal: ";
    Inorder(root);

    cout<<"\n\nRed-Black Tree:\n";
    Display(root);

    DeleteTree(root);

    return 0;
}
