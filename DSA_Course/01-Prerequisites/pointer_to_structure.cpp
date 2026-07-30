#include <iostream>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

int main() {
    Rectangle rect = {10, 5};
    Rectangle* ptr = &rect;

    cout << rect.length << endl;

    cout << endl;
    cout << endl;

    rect.length = 11;

    cout << rect.length << endl;

    ptr->length = 20;

    cout << endl;
    cout << endl;

    cout << rect.length << endl;

    return 0;
}