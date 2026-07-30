#include <iostream>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

int main() {
    Rectangle r1 = {10, 5};

    cout << sizeof(r1);

    return 0;
}