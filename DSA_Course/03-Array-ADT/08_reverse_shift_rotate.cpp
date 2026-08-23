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

// Reverse using an auxiliary array
void ReverseByArray(Array* arr) {
    int* B = new int[arr->length];

    for (int i = arr->length - 1, j = 0; i >= 0; i--, j++) {
        B[j] = arr->A[i];
    }

    for (int i = 0; i < arr->length; i++) {
        arr->A[i] = B[i];
    }

    delete[] B;
}

// Reverse by swapping elements
void ReverseBySwap(Array* arr) {
    for (int i = 0, j = arr->length - 1; i < j; i++, j--) {
        swap(arr->A[i], arr->A[j]);
    }
}

// Left Shift
void LeftShift(Array* arr) {
    if (arr->length == 0) {
        return;
    }

    for (int i = 0; i < arr->length - 1; i++) {
        arr->A[i] = arr->A[i + 1];
    }

    arr->A[arr->length - 1] = 0;
}

// Right Shift
void RightShift(Array* arr) {
    if (arr->length == 0) {
        return;
    }

    for (int i = arr->length - 1; i > 0; i--) {
        arr->A[i] = arr->A[i - 1];
    }

    arr->A[0] = 0;
}

// Left Rotate
void LeftRotate(Array* arr) {
    if (arr->length == 0) {
        return;
    }

    int first = arr->A[0];

    for (int i = 0; i < arr->length - 1; i++) {
        arr->A[i] = arr->A[i + 1];
    }

    arr->A[arr->length - 1] = first;
}

// Right Rotate
void RightRotate(Array* arr) {
    if (arr->length == 0) {
        return;
    }

    int last = arr->A[arr->length - 1];

    for (int i = arr->length - 1; i > 0; i--) {
        arr->A[i] = arr->A[i - 1];
    }

    arr->A[0] = last;
}

int main() {
    Array arr;

    Initialize(&arr);

    cout << "\nOriginal ";
    Display(arr);

    ReverseBySwap(&arr);

    cout << "After Reverse: ";
    Display(arr);

    LeftShift(&arr);

    cout << "After Left Shift: ";
    Display(arr);

    RightShift(&arr);

    cout << "After Right Shift: ";
    Display(arr);

    LeftRotate(&arr);

    cout << "After Left Rotate: ";
    Display(arr);

    RightRotate(&arr);

    cout << "After Right Rotate: ";
    Display(arr);

    delete[] arr.A;

    return 0;
}