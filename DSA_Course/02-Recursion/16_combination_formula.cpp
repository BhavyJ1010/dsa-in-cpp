#include <iostream>
using namespace std;

// nCr using the recursive factorial formula
long long combinationFormula(int n, int r) {
    if (r == 0 || r == n) {
        return 1;
    }

    return combinationFormula(n - 1, r - 1) *
           n / r;
}

// nCr using Pascal's identity
long long combinationPascal(int n, int r) {
    if (r == 0 || r == n) {
        return 1;
    }

    return combinationPascal(n - 1, r - 1) +
           combinationPascal(n - 1, r);
}

int main() {
    int n = 6;
    int r = 2;

    cout << "Using formula: "
         << combinationFormula(n, r) << endl;

    cout << "Using Pascal's identity: "
         << combinationPascal(n, r) << endl;

    return 0;
}