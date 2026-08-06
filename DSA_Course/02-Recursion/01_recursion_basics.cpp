#include <iostream>
using namespace std;

// Tail Recursion
void tailRecursion(int n) {
    if (n > 0) {
        cout << n << " ";
        tailRecursion(n - 1);
    }
}

// Head Recursion
void headRecursion(int n) {
    if (n > 0) {
        headRecursion(n - 1);
        cout << n << " ";
    }
}

int main() {
    int n = 5;

    cout << "Tail Recursion: ";
    tailRecursion(n);

    cout << endl;

    cout << "Head Recursion: ";
    headRecursion(n);

    return 0;
}