
#include<iostream>
using namespace std;

/*
    RED-BLACK TREE

    A Red-Black Tree is a self-balancing Binary Search Tree.

    Every node has an additional colour: RED or BLACK.

    PROPERTIES:

    1. Every node is either RED or BLACK.
    2. Root is always BLACK.
    3. Every NULL leaf (NIL leaf) is considered BLACK.
    4. A RED node cannot have a RED parent or child.
    5. Every path from a node to its descendant NIL leaves
       must contain the same number of BLACK nodes.

    The number of BLACK nodes on such a path is called
    BLACK HEIGHT.

    These properties ensure that the tree remains balanced
    enough to guarantee O(log n) operations.
*/

struct Node
{
    int data;
    bool color;             // 1 = RED, 0 = BLACK
    Node* Lchild;
    Node* Rchild;
    Node* parent;
};

Node* CreateNode(int key, bool color)
{
    Node* p = new Node;

    p->data = key;
    p->color = color;
    p->Lchild = NULL;
    p->Rchild = NULL;
    p->parent = NULL;

    return p;
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
    /*
              20(B)
             /     \
          10(B)   30(B)
                     \
                     50(R)

        This is a valid Red-Black Tree.
    */

    Node* root = CreateNode(20, 0);

    root->Lchild = CreateNode(10, 0);
    root->Rchild = CreateNode(30, 0);

    root->Lchild->parent = root;
    root->Rchild->parent = root;

    root->Rchild->Rchild = CreateNode(50, 1);
    root->Rchild->Rchild->parent = root->Rchild;

    cout<<"Inorder Traversal: ";
    Inorder(root);

    cout<<"\n\nTree Structure:\n";
    Display(root);

    DeleteTree(root);

    return 0;
}
