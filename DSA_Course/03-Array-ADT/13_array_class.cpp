#include <iostream>
using namespace std;

class Array {
private:
    int* A;
    int size;
    int length;

public:
    Array(int size) {
        this->size = size;
        A = new int[size];
        length = 0;
    }

    ~Array() {
        delete[] A;
    }

    void Display() {
        cout << "Array: ";

        for (int i = 0; i < length; i++) {
            cout << A[i] << " ";
        }

        cout << endl;
    }

    void Append(int value) {
        if (length < size) {
            A[length] = value;
            length++;
        }
    }

    void Insert(int index, int value) {
        if (index >= 0 && index <= length && length < size) {
            for (int i = length; i > index; i--) {
                A[i] = A[i - 1];
            }

            A[index] = value;
            length++;
        }
    }

    void Delete(int index) {
        if (index >= 0 && index < length) {
            for (int i = index; i < length - 1; i++) {
                A[i] = A[i + 1];
            }

            length--;
        }
    }

    int LinearSearch(int key) {
        for (int i = 0; i < length; i++) {
            if (A[i] == key) {
                return i;
            }
        }

        return -1;
    }

    int BinarySearch(int key) {
        int low = 0;
        int high = length - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (key == A[mid]) {
                return mid;
            }
            else if (key < A[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return -1;
    }

    int Get(int index) {
        if (index >= 0 && index < length) {
            return A[index];
        }

        return -1;
    }

    void Set(int index, int value) {
        if (index >= 0 && index < length) {
            A[index] = value;
        }
    }

    int Max() {
        int max = A[0];

        for (int i = 1; i < length; i++) {
            if (A[i] > max) {
                max = A[i];
            }
        }

        return max;
    }

    int Min() {
        int min = A[0];

        for (int i = 1; i < length; i++) {
            if (A[i] < min) {
                min = A[i];
            }
        }

        return min;
    }

    int Sum() {
        int sum = 0;

        for (int i = 0; i < length; i++) {
            sum += A[i];
        }

        return sum;
    }

    bool IsSorted() {
        for (int i = 0; i < length - 1; i++) {
            if (A[i] > A[i + 1]) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Array arr(10);

    arr.Append(2);
    arr.Append(4);
    arr.Append(6);
    arr.Append(8);
    arr.Append(10);

    arr.Display();

    arr.Insert(2, 5);
    arr.Display();

    arr.Delete(2);
    arr.Display();

    cout << "Element at index 2: " << arr.Get(2) << endl;

    arr.Set(2, 20);
    arr.Display();

    cout << "Linear Search: " << arr.LinearSearch(20) << endl;
    cout << "Binary Search: " << arr.BinarySearch(20) << endl;

    cout << "Maximum: " << arr.Max() << endl;
    cout << "Minimum: " << arr.Min() << endl;
    cout << "Sum: " << arr.Sum() << endl;

    if (arr.IsSorted()) {
        cout << "Array is sorted." << endl;
    }
    else {
        cout << "Array is not sorted." << endl;
    }

    return 0;
}