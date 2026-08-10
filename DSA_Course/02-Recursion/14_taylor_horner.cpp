#include <iostream>
using namespace std;

double taylorHorner(double x, int terms) {
    if (terms == 0) {
        return 1;
    }

    return 1 + (x / terms) * taylorHorner(x, terms - 1);
}

int main() {
    double x = 3;
    int terms = 20;

    cout << taylorHorner(x, terms) << endl;

    return 0;
}