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

// Insert an element while keeping the array sorted
void InsertInSorted(Array* arr, int value) {
    if (arr->length >= arr->size) {
        return;
    }

    int i = arr->length - 1;

    while (i >= 0 && arr->A[i] > value) {
        arr->A[i + 1] = arr->A[i];
        i--;
    }

    arr->A[i + 1] = value;
    arr->length++;
}

// Check whether the array is sorted
bool IsSorted(Array arr) {
    for (int i = 0; i < arr.length - 1; i++) {
        if (arr.A[i] > arr.A[i + 1]) {
            return false;
        }
    }

    return true;
}

// Rearrange the array so that negative elements
// appear on the left and positive elements on the right.
void RearrangeNegativePositive(Array* arr) {
    int i = 0;
    int j = arr->length - 1;

    while (i < j) {
        while (i < arr->length && arr->A[i] < 0) {
            i++;
        }

        while (j >= 0 && arr->A[j] >= 0) {
            j--;
        }

        if (i < j) {
            swap(arr->A[i], arr->A[j]);
        }
    }
}

int main() {
    Array arr;

    Initialize(&arr);

    cout << "\nOriginal ";
    Display(arr);

    cout << "\nIs Sorted: ";

    if (IsSorted(arr)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    if (IsSorted(arr)) {
        int value;

        cout << "\nEnter element to insert: ";
        cin >> value;

        InsertInSorted(&arr, value);

        cout << "After Sorted Insertion: ";
        Display(arr);
    }

    RearrangeNegativePositive(&arr);

    cout << "After Negative/Positive Rearrangement: ";
    Display(arr);

    delete[] arr.A;

    return 0;
}