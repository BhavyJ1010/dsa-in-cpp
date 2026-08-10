#include <iostream>
using namespace std;

double taylorSeries(double x, int terms) {
    static double power = 1;
    static double factorial = 1;

    if (terms == 0) {
        return 1;
    }

    double result = taylorSeries(x, terms - 1);

    power *= x;
    factorial *= terms;

    return result + power / factorial;
}

int main() {
    double x = 3;
    int terms = 20;

    cout << taylorSeries(x, terms) << endl;

    return 0;
}