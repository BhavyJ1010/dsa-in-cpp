#include <iostream>
using namespace std;

int main() {
    int* p = new int[5];
    int* q = new int[10];

    for (int i = 0; i < 5; i++) {
        p[i] = i;
    }

    cout << "Elements of original array: ";
    for (int i = 0; i < 5; i++) {
        cout << p[i] << " ";
    }

    cout << endl;

    // Copy elements from old array to new array
    for (int i = 0; i < 5; i++) {
        q[i] = p[i];
    }

    delete[] p;

    // Point p to the new larger array
    p = q;
    q = nullptr;

    cout << "Elements of increased array: ";
    for (int i = 0; i < 10; i++) {
        cout << p[i] << " ";
    }

    cout << endl;

    delete[] p;

    return 0;
}