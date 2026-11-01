
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

bool IsRed(Node* p)
{
    return p != NULL && p->color;
}

Node* CreateNode(int key)
{
    Node* p = new Node;

    p->data = key;
    p->color = 1;
    p->Lchild = NULL;
    p->Rchild = NULL;
    p->parent = NULL;

    return p;
}

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

// Fix Red-Black properties after insertion
Node* FixInsert(Node* root, Node* p)
{
    while(p != root && IsRed(p->parent))
    {
        Node* parent = p->parent;
        Node* grandparent = parent->parent;

        if(parent == grandparent->Lchild)
        {
            Node* uncle = grandparent->Rchild;

            if(IsRed(uncle))
            {
                parent->color = 0;
                uncle->color = 0;
                grandparent->color = 1;

                p = grandparent;
            }
            else
            {
                if(p == parent->Rchild)
                {
                    p = parent;
                    root = RotateLeft(root, p);

                    parent = p->parent;
                    grandparent = parent->parent;
                }

                parent->color = 0;
                grandparent->color = 1;

                root = RotateRight(root, grandparent);
            }
        }
        else
        {
            Node* uncle = grandparent->Lchild;

            if(IsRed(uncle))
            {
                parent->color = 0;
                uncle->color = 0;
                grandparent->color = 1;

                p = grandparent;
            }
            else
            {
                if(p == parent->Lchild)
                {
                    p = parent;
                    root = RotateRight(root, p);

                    parent = p->parent;
                    grandparent = parent->parent;
                }

                parent->color = 0;
                grandparent->color = 1;

                root = RotateLeft(root, grandparent);
            }
        }
    }

    root->color = 0;

    return root;
}

Node* Insert(Node* root, int key)
{
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

    root = BSTInsert(root, p);

    return FixInsert(root, p);
}

// Find the smallest node in a subtree
Node* Minimum(Node* p)
{
    while(p->Lchild)
        p = p->Lchild;

    return p;
}

// Replace one subtree with another
Node* Transplant(Node* root, Node* u, Node* v)
{
    if(u->parent == NULL)
        root = v;

    else if(u == u->parent->Lchild)
        u->parent->Lchild = v;

    else
        u->parent->Rchild = v;

    if(v)
        v->parent = u->parent;

    return root;
}

// Fix Red-Black properties after deletion
// xIsLeft is needed when x is NULL because NULL has no parent.
Node* FixDelete(Node* root, Node* x, Node* parent, bool xIsLeft)
{
    while(x != root && !IsRed(x))
    {
        if(parent == NULL)
            break;

        if(x != NULL)
            xIsLeft = (x == parent->Lchild);

        // x is the left child
        if(xIsLeft)
        {
            Node* sibling = parent->Rchild;

            // CASE 1: Sibling is RED
            if(IsRed(sibling))
            {
                sibling->color = 0;
                parent->color = 1;

                root = RotateLeft(root, parent);
                sibling = parent->Rchild;
            }

            // CASE 2: Sibling is BLACK and both children are BLACK
            if(!IsRed(sibling ? sibling->Lchild : NULL) &&
               !IsRed(sibling ? sibling->Rchild : NULL))
            {
                if(sibling)
                    sibling->color = 1;

                x = parent;
                parent = x->parent;
            }
            else
            {
                // CASE 3: Near child RED, far child BLACK
                if(!IsRed(sibling->Rchild))
                {
                    if(sibling->Lchild)
                        sibling->Lchild->color = 0;

                    sibling->color = 1;

                    root = RotateRight(root, sibling);
                    sibling = parent->Rchild;
                }

                // CASE 4: Far child RED
                sibling->color = parent->color;
                parent->color = 0;

                if(sibling->Rchild)
                    sibling->Rchild->color = 0;

                root = RotateLeft(root, parent);

                x = root;
                parent = NULL;
            }
        }

        // x is the right child (mirror cases)
        else
        {
            Node* sibling = parent->Lchild;

            // CASE 1: Sibling is RED
            if(IsRed(sibling))
            {
                sibling->color = 0;
                parent->color = 1;

                root = RotateRight(root, parent);
                sibling = parent->Lchild;
            }

            // CASE 2: Sibling is BLACK and both children are BLACK
            if(!IsRed(sibling ? sibling->Lchild : NULL) &&
               !IsRed(sibling ? sibling->Rchild : NULL))
            {
                if(sibling)
                    sibling->color = 1;

                x = parent;
                parent = x->parent;
            }
            else
            {
                // CASE 3: Near child RED, far child BLACK
                if(!IsRed(sibling->Lchild))
                {
                    if(sibling->Rchild)
                        sibling->Rchild->color = 0;

                    sibling->color = 1;

                    root = RotateLeft(root, sibling);
                    sibling = parent->Lchild;
                }

                // CASE 4: Far child RED
                sibling->color = parent->color;
                parent->color = 0;

                if(sibling->Lchild)
                    sibling->Lchild->color = 0;

                root = RotateRight(root, parent);

                x = root;
                parent = NULL;
            }
        }
    }

    if(x)
        x->color = 0;

    return root;
}

Node* Delete(Node* root, int key)
{
    // Search for the node to be deleted
    Node* z = root;

    while(z && z->data != key)
    {
        if(key < z->data)
            z = z->Lchild;
        else
            z = z->Rchild;
    }

    if(z == NULL)
        return root;

    Node* y = z;
    Node* x = NULL;
    Node* xParent = NULL;

    bool xIsLeft = 0;
    bool originalColor = y->color;

    // CASE 1: Node has no left child
    if(z->Lchild == NULL)
    {
        x = z->Rchild;
        xParent = z->parent;

        xIsLeft = xParent && z == xParent->Lchild;

        root = Transplant(root, z, z->Rchild);

        if(x)
        {
            xParent = x->parent;
            xIsLeft = xParent && x == xParent->Lchild;
        }
    }

    // CASE 2: Node has no right child
    else if(z->Rchild == NULL)
    {
        x = z->Lchild;
        xParent = z->parent;

        xIsLeft = xParent && z == xParent->Lchild;

        root = Transplant(root, z, z->Lchild);

        if(x)
        {
            xParent = x->parent;
            xIsLeft = xParent && x == xParent->Lchild;
        }
    }

    // CASE 3: Node has two children
    else
    {
        // Replace using inorder successor
        y = Minimum(z->Rchild);

        originalColor = y->color;
        x = y->Rchild;

        if(y->parent == z)
        {
            xParent = y;
            xIsLeft = 0;

            if(x)
                x->parent = y;
        }
        else
        {
            xParent = y->parent;
            xIsLeft = (y == xParent->Lchild);

            root = Transplant(root, y, y->Rchild);

            if(x)
            {
                xParent = x->parent;
                xIsLeft = xParent && x == xParent->Lchild;
            }

            y->Rchild = z->Rchild;
            y->Rchild->parent = y;
        }

        root = Transplant(root, z, y);

        y->Lchild = z->Lchild;
        y->Lchild->parent = y;

        y->color = z->color;
    }

    delete z;

    // Only deleting a BLACK node can violate black height
    if(originalColor == 0)
        root = FixDelete(root, x, xParent, xIsLeft);

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

    int keys[] = {10, 20, 30, 40, 50, 60, 70};

    for(int i=0; i<7; i++)
        root = Insert(root, keys[i]);

    cout<<"Before Deletion:\n";
    Inorder(root);

    cout<<"\n\n";

    root = Delete(root, 40);

    cout<<"After Deleting 40:\n";
    Inorder(root);

    cout<<"\n\nTree Structure:\n";
    Display(root);

    DeleteTree(root);

    return 0;
}
