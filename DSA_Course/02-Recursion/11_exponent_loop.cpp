#include <iostream>
using namespace std;

int power(int x, int n) {
    int result = 1;

    while (n > 0) {
        if (n % 2 == 1) {
            result *= x;
        }

        x *= x;
        n /= 2;
    }

    return result;
}

int main() {
    cout << power(6, 4);

    return 0;
}