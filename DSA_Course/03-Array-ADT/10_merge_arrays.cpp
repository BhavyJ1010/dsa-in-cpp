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

Array Merge(Array arr1, Array arr2) {
    Array arr3;

    arr3.size = arr1.length + arr2.length;
    arr3.length = 0;
    arr3.A = new int[arr3.size];

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < arr1.length && j < arr2.length) {
        if (arr1.A[i] < arr2.A[j]) {
            arr3.A[k++] = arr1.A[i++];
        }
        else {
            arr3.A[k++] = arr2.A[j++];
        }
    }

    while (i < arr1.length) {
        arr3.A[k++] = arr1.A[i++];
    }

    while (j < arr2.length) {
        arr3.A[k++] = arr2.A[j++];
    }

    arr3.length = k;

    return arr3;
}

int main() {
    Array arr1;
    Array arr2;

    cout << "First sorted array:" << endl;
    Initialize(&arr1);

    cout << "\nSecond sorted array:" << endl;
    Initialize(&arr2);

    cout << "\nArray 1: ";
    Display(arr1);

    cout << "Array 2: ";
    Display(arr2);

    Array arr3 = Merge(arr1, arr2);

    cout << "Merged array: ";
    Display(arr3);

    delete[] arr1.A;
    delete[] arr2.A;
    delete[] arr3.A;

    return 0;
}