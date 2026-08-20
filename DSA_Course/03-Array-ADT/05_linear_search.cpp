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

// Basic Linear Search
int LinearSearch(Array arr, int key) {
    for (int i = 0; i < arr.length; i++) {
        if (arr.A[i] == key) {
            return i;
        }
    }

    return -1;
}

// Linear Search with Transposition
int LinearSearchTranspose(Array* arr, int key) {
    for (int i = 0; i < arr->length; i++) {
        if (arr->A[i] == key) {

            if (i > 0) {
                swap(arr->A[i], arr->A[i - 1]);
                return i - 1;
            }

            return i;
        }
    }

    return -1;
}

// Linear Search with Move-to-Front
int LinearSearchMoveToFront(Array* arr, int key) {
    for (int i = 0; i < arr->length; i++) {
        if (arr->A[i] == key) {

            if (i > 0) {
                int temp = arr->A[i];

                for (int j = i; j > 0; j--) {
                    arr->A[j] = arr->A[j - 1];
                }

                arr->A[0] = temp;
                return 0;
            }

            return i;
        }
    }

    return -1;
}

int main() {
    Array arr;

    Initialize(&arr);

    cout << "\nOriginal ";
    Display(arr);

    int key;
    cout << "\nEnter element to search: ";
    cin >> key;

    int index = LinearSearch(arr, key);

    if (index != -1) {
        cout << "Element found at index " << index << endl;
    }
    else {
        cout << "Element not found." << endl;
    }

    cout << "\nUsing Transposition:" << endl;

    index = LinearSearchTranspose(&arr, key);

    if (index != -1) {
        cout << "Element found at index " << index << endl;
        Display(arr);
    }
    else {
        cout << "Element not found." << endl;
    }

    cout << "\nUsing Move-to-Front:" << endl;

    index = LinearSearchMoveToFront(&arr, key);

    if (index != -1) {
        cout << "Element found at index " << index << endl;
        Display(arr);
    }
    else {
        cout << "Element not found." << endl;
    }

    delete[] arr.A;

    return 0;
}