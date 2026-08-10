#include <iostream>
using namespace std;

double taylorSeries(double x, int terms) {
    double result = 1;
    double power = 1;
    double factorial = 1;

    for (int i = 1; i <= terms; i++) {
        power *= x;
        factorial *= i;

        result += power / factorial;
    }

    return result;
}

int main() {
    double x = 3;
    int terms = 20;

    cout << taylorSeries(x, terms) << endl;

    return 0;
}