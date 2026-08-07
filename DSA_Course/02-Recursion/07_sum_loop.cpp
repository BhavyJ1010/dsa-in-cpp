#include <iostream>
using namespace std;

int sum(int n) {
    int total = 0;

    for (int i = 1; i <= n; i++) {
        total += i;
    }

    return total;
}

int main() {
    int n;
    cout << "Enter a natural number: ";
    cin >> n;

    cout << "Sum = " << sum(n) << endl;

    return 0;
}