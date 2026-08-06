#include <iostream>
using namespace std;

// McCarthy 91 Function
int nestedRecursion(int n) {
    if (n > 100) {
        return n - 10;
    }

    return nestedRecursion(nestedRecursion(n + 11));
}

int main() {
    cout << nestedRecursion(95) << endl;
    cout << nestedRecursion(100) << endl;
    cout << nestedRecursion(200) << endl;

    return 0;
}