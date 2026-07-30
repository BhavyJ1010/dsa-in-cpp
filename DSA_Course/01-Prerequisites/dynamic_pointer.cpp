#include <iostream>
using namespace std;

int main() {
    int arr[5] = {0, 2, 4, 6, 8};
    int* p = arr;

    for (int i = 0; i < 5; i++) {
        cout << p[i] << endl;
    }

    int* ptr = new int[5];

    ptr[0] = 0;
    ptr[1] = 2;
    ptr[2] = 4;
    ptr[3] = 6;
    ptr[4] = 8;

    for (int i = 0; i < 5; i++) {
        cout << ptr[i] << endl;
    }

    delete[] ptr;

    return 0;
}