#include <iostream>
using namespace std;

// Static variable in recursion
int staticExample(int n) {
    static int x = 0;

    if (n > 0) {
        x++;
        return staticExample(n - 1) + x;
    }

    return 0;
}

// Global variable in recursion
int y = 0;

int globalExample(int n) {
    if (n > 0) {
        y++;
        return globalExample(n - 1) + y;
    }

    return 0;
}

int main() {
    cout << "Static Variable: " << staticExample(5) << endl;
    cout << "Global Variable: " << globalExample(5) << endl;

    return 0;
}