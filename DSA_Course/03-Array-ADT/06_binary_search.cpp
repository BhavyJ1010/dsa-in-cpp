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

    cout << "Enter elements in sorted order: ";

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

// Iterative Binary Search
int BinarySearch(Array arr, int key) {
    int low = 0;
    int high = arr.length - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (key == arr.A[mid]) {
            return mid;
        }

        if (key < arr.A[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return -1;
}

// Recursive Binary Search
int RecursiveBinarySearch(Array arr, int low, int high, int key) {
    if (low > high) {
        return -1;
    }

    int mid = (low + high) / 2;

    if (key == arr.A[mid]) {
        return mid;
    }

    if (key < arr.A[mid]) {
        return RecursiveBinarySearch(arr, low, mid - 1, key);
    }

    return RecursiveBinarySearch(arr, mid + 1, high, key);
}

int main() {
    Array arr;

    Initialize(&arr);

    cout << endl;
    Display(arr);

    int key;
    cout << "\nEnter element to search: ";
    cin >> key;

    int index = BinarySearch(arr, key);

    if (index != -1) {
        cout << "Iterative Binary Search: Element found at index "
             << index << endl;
    }
    else {
        cout << "Iterative Binary Search: Element not found." << endl;
    }

    index = RecursiveBinarySearch(arr, 0, arr.length - 1, key);

    if (index != -1) {
        cout << "Recursive Binary Search: Element found at index "
             << index << endl;
    }
    else {
        cout << "Recursive Binary Search: Element not found." << endl;
    }

    delete[] arr.A;

    return 0;
}