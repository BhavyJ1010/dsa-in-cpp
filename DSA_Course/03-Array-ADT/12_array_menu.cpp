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

void Insert(Array* arr, int index, int value) {
    if (index >= 0 && index <= arr->length && arr->length < arr->size) {
        for (int i = arr->length; i > index; i--) {
            arr->A[i] = arr->A[i - 1];
        }

        arr->A[index] = value;
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

int LinearSearch(Array arr, int key) {
    for (int i = 0; i < arr.length; i++) {
        if (arr.A[i] == key) {
            return i;
        }
    }

    return -1;
}

int BinarySearch(Array arr, int key) {
    int low = 0;
    int high = arr.length - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (key == arr.A[mid]) {
            return mid;
        }
        else if (key < arr.A[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return -1;
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

bool IsSorted(Array arr) {
    for (int i = 0; i < arr.length - 1; i++) {
        if (arr.A[i] > arr.A[i + 1]) {
            return false;
        }
    }

    return true;
}

void InsertInSorted(Array* arr, int value) {
    if (arr->length < arr->size && IsSorted(*arr)) {
        int i = arr->length - 1;

        while (i >= 0 && arr->A[i] > value) {
            arr->A[i + 1] = arr->A[i];
            i--;
        }

        arr->A[i + 1] = value;
        arr->length++;
    }
}

int main() {
    Array arr;

    Initialize(&arr);

    int choice;
    int index;
    int value;

    do {
        cout << "\n----- ARRAY MENU -----" << endl;
        cout << "1. Display" << endl;
        cout << "2. Append" << endl;
        cout << "3. Insert" << endl;
        cout << "4. Delete" << endl;
        cout << "5. Linear Search" << endl;
        cout << "6. Binary Search" << endl;
        cout << "7. Get" << endl;
        cout << "8. Set" << endl;
        cout << "9. Maximum" << endl;
        cout << "10. Minimum" << endl;
        cout << "11. Sum" << endl;
        cout << "12. Check Sorted" << endl;
        cout << "13. Insert in Sorted Array" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            Display(arr);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            Append(&arr, value);
            break;

        case 3:
            cout << "Enter index and value: ";
            cin >> index >> value;
            Insert(&arr, index, value);
            break;

        case 4:
            cout << "Enter index: ";
            cin >> index;
            Delete(&arr, index);
            break;

        case 5:
            cout << "Enter value to search: ";
            cin >> value;
            cout << "Index: " << LinearSearch(arr, value) << endl;
            break;

        case 6:
            cout << "Enter value to search: ";
            cin >> value;
            cout << "Index: " << BinarySearch(arr, value) << endl;
            break;

        case 7:
            cout << "Enter index: ";
            cin >> index;
            cout << "Element: " << Get(arr, index) << endl;
            break;

        case 8:
            cout << "Enter index and value: ";
            cin >> index >> value;
            Set(&arr, index, value);
            break;

        case 9:
            cout << "Maximum: " << Max(arr) << endl;
            break;

        case 10:
            cout << "Minimum: " << Min(arr) << endl;
            break;

        case 11:
            cout << "Sum: " << Sum(arr) << endl;
            break;

        case 12:
            if (IsSorted(arr)) {
                cout << "Array is sorted." << endl;
            }
            else {
                cout << "Array is not sorted." << endl;
            }
            break;

        case 13:
            cout << "Enter value: ";
            cin >> value;
            InsertInSorted(&arr, value);
            break;

        case 0:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        }

    } while (choice != 0);

    delete[] arr.A;

    return 0;
}