#include <iostream>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

Rectangle* createRectangle() {
    Rectangle* p = new Rectangle;

    p->length = 10;
    p->breadth = 8;

    return p;
}

int main() {
    Rectangle* ptr = createRectangle();

    cout << ptr->breadth << endl;
    cout << ptr->length << endl;

    delete ptr;

    return 0;
}