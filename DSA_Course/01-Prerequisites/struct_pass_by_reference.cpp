#include <iostream>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

void fun(Rectangle& r) {
    r.length = 7;
    r.breadth = 8;

    cout << r.length << endl;
    cout << r.breadth << endl;
}

int main() {
    Rectangle r = {10, 5};

    fun(r);

    cout << r.length << endl;
    cout << r.breadth << endl;

    return 0;
}