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

bool IsSorted(Array arr) {
    for (int i = 0; i < arr.length - 1; i++) {
        if (arr.A[i] > arr.A[i + 1]) {
            return false;
        }
    }

    return true;
}

// Union of two arrays
Array Union(Array arr1, Array arr2) {
    Array uni;

    uni.size = arr1.length + arr2.length;
    uni.length = 0;
    uni.A = new int[uni.size];

    if (IsSorted(arr1) && IsSorted(arr2)) {
        int i = 0;
        int j = 0;
        int k = 0;

        while (i < arr1.length && j < arr2.length) {
            if (arr1.A[i] < arr2.A[j]) {
                uni.A[k++] = arr1.A[i++];
            }
            else if (arr1.A[i] > arr2.A[j]) {
                uni.A[k++] = arr2.A[j++];
            }
            else {
                uni.A[k++] = arr1.A[i++];
                j++;
            }
        }

        while (i < arr1.length) {
            uni.A[k++] = arr1.A[i++];
        }

        while (j < arr2.length) {
            uni.A[k++] = arr2.A[j++];
        }

        uni.length = k;
    }
    else {
        for (int i = 0; i < arr1.length; i++) {
            Append(&uni, arr1.A[i]);
        }

        for (int i = 0; i < arr2.length; i++) {
            bool found = false;

            for (int j = 0; j < uni.length; j++) {
                if (uni.A[j] == arr2.A[i]) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                Append(&uni, arr2.A[i]);
            }
        }
    }

    return uni;
}

// Intersection of two arrays
Array Intersection(Array arr1, Array arr2) {
    Array inter;

    inter.size = arr1.length + arr2.length;
    inter.length = 0;
    inter.A = new int[inter.size];

    if (IsSorted(arr1) && IsSorted(arr2)) {
        int i = 0;
        int j = 0;

        while (i < arr1.length && j < arr2.length) {
            if (arr1.A[i] < arr2.A[j]) {
                i++;
            }
            else if (arr1.A[i] > arr2.A[j]) {
                j++;
            }
            else {
                Append(&inter, arr1.A[i]);
                i++;
                j++;
            }
        }
    }
    else {
        for (int i = 0; i < arr1.length; i++) {
            bool found = false;

            for (int j = 0; j < arr2.length; j++) {
                if (arr1.A[i] == arr2.A[j]) {
                    found = true;
                    break;
                }
            }

            if (found) {
                bool alreadyAdded = false;

                for (int j = 0; j < inter.length; j++) {
                    if (inter.A[j] == arr1.A[i]) {
                        alreadyAdded = true;
                        break;
                    }
                }

                if (!alreadyAdded) {
                    Append(&inter, arr1.A[i]);
                }
            }
        }
    }

    return inter;
}

// Difference: arr1 - arr2
Array Difference(Array arr1, Array arr2) {
    Array diff;

    diff.size = arr1.length + arr2.length;
    diff.length = 0;
    diff.A = new int[diff.size];

    if (IsSorted(arr1) && IsSorted(arr2)) {
        int i = 0;
        int j = 0;

        while (i < arr1.length && j < arr2.length) {
            if (arr1.A[i] < arr2.A[j]) {
                Append(&diff, arr1.A[i]);
                i++;
            }
            else if (arr1.A[i] > arr2.A[j]) {
                j++;
            }
            else {
                i++;
                j++;
            }
        }

        while (i < arr1.length) {
            Append(&diff, arr1.A[i]);
            i++;
        }
    }
    else {
        for (int i = 0; i < arr1.length; i++) {
            bool found = false;

            for (int j = 0; j < arr2.length; j++) {
                if (arr1.A[i] == arr2.A[j]) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                Append(&diff, arr1.A[i]);
            }
        }
    }

    return diff;
}

// Check whether an element belongs to an array
bool Membership(Array arr, int value) {
    for (int i = 0; i < arr.length; i++) {
        if (arr.A[i] == value) {
            return true;
        }
    }

    return false;
}

int main() {
    Array arr1;
    Array arr2;

    cout << "First array:" << endl;
    Initialize(&arr1);

    cout << "\nSecond array:" << endl;
    Initialize(&arr2);

    cout << "\nArray 1: ";
    Display(arr1);

    cout << "Array 2: ";
    Display(arr2);

    Array uni = Union(arr1, arr2);
    Array inter = Intersection(arr1, arr2);
    Array diff = Difference(arr1, arr2);

    cout << "\nUnion: ";
    Display(uni);

    cout << "Intersection: ";
    Display(inter);

    cout << "Difference (Array 1 - Array 2): ";
    Display(diff);

    int value;
    cout << "\nEnter element to check for membership in Array 1: ";
    cin >> value;

    if (Membership(arr1, value)) {
        cout << value << " is a member of Array 1." << endl;
    }
    else {
        cout << value << " is not a member of Array 1." << endl;
    }

    delete[] arr1.A;
    delete[] arr2.A;
    delete[] uni.A;
    delete[] inter.A;
    delete[] diff.A;

    return 0;
}