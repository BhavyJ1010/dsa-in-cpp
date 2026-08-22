#include <iostream>
using namespace std;

struct Array {
    int* A;
    int size;
    int length;
};

void Initialize(Array* arr) {
    cout << "Enter size of array: ";
    cin >> arr->size;

    arr->A = new int[arr->size];

    cout << "Enter number of elements: ";
    cin >> arr->length;

    if (arr->length > arr->size) {
        cout << "Length cannot be greater than size." << endl;
        arr->length = 0;
        return;
    }

    cout << "Enter elements: ";
    for (int i = 0; i < arr->length; i++) {
        cin >> arr->A[i];
    }
}

void Display(Array arr) {
    cout << "Array: ";

    for (int i = 0; i < arr.length; i++) {
        cout << arr.A[i] << " ";
    }

    cout << endl;
}

int Get(Array arr, int index) {
    if (index >= 0 && index < arr.length) {
        return arr.A[index];
    }

    return -1;
}

void Set(Array* arr, int index, int value) {
    if (index >= 0 && index < arr->length) {
        arr->A[index] = value;
    }
}

int Max(Array arr) {
    int max = arr.A[0];

    for (int i = 1; i < arr.length; i++) {
        if (arr.A[i] > max) {
            max = arr.A[i];
        }
    }

    return max;
}

int Min(Array arr) {
    int min = arr.A[0];

    for (int i = 1; i < arr.length; i++) {
        if (arr.A[i] < min) {
            min = arr.A[i];
        }
    }

    return min;
}

int Sum(Array arr) {
    int sum = 0;

    for (int i = 0; i < arr.length; i++) {
        sum += arr.A[i];
    }

    return sum;
}

float Average(Array arr) {
    return (float)Sum(arr) / arr.length;
}

int main() {
    Array arr;

    Initialize(&arr);

    cout << endl;
    Display(arr);

    cout << "Element at index 2: " << Get(arr, 2) << endl;

    Set(&arr, 2, 100);

    cout << "After Set: ";
    Display(arr);

    cout << "Maximum = " << Max(arr) << endl;
    cout << "Minimum = " << Min(arr) << endl;
    cout << "Sum = " << Sum(arr) << endl;
    cout << "Average = " << Average(arr) << endl;

    delete[] arr.A;

    return 0;
}