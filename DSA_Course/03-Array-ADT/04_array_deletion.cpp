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

void Append(Array* arr, int value) {
    if (arr->length < arr->size) {
        arr->A[arr->length] = value;
        arr->length++;
    }
}

void Delete(Array* arr, int index) {
    if (index >= 0 && index < arr->length) {
        for (int i = index; i < arr->length - 1; i++) {
            arr->A[i] = arr->A[i + 1];
        }

        arr->length--;
    }
}

int main() {
    Array arr;

    Initialize(&arr);

    cout << "\nOriginal ";
    Display(arr);

    cout << "\nAfter deleting element at index 2: ";
    Delete(&arr, 2);
    Display(arr);

    delete[] arr.A;

    return 0;
}