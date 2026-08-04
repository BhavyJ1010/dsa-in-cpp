#include <iostream>
using namespace std;

void swap(int x, int y) {
    // Change only inside the function

    int temp = x;
    x = y;
    y = temp;

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    cout << endl;
}

int main() {
    int a = 10;
    int b = 20;

    swap(a, b);

    // No change here

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}