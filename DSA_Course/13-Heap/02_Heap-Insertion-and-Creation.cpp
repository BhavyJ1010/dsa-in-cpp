
#include <iostream>
#include <vector>
using namespace std;

// Insert a new element into an existing Max Heap stored in an array.
// A[n] must already contain the new element, and indices 0 to n-1
// must contain a valid Max Heap.
void Insert(int A[], int n){
    int i = n;
    int temp = A[i];

    // Move the new element upward until the Max Heap property is restored.
    while(i > 0 && temp > A[(i-1)/2]){
        A[i] = A[(i-1)/2];
        i = (i-1)/2;
    }

    A[i] = temp;
}

// Insert a key into a Max Heap stored in a vector.
void Insert(vector<int>& A, int key){
    int i = A.size();
    A.push_back(key);

    while(i > 0 && key > A[(i-1)/2]){
        A[i] = A[(i-1)/2];
        i = (i-1)/2;
    }

    A[i] = key;
}

// Create a Max Heap by inserting the elements one by one.
// Time complexity: O(n log n).
void CreateHeap(vector<int>& heap, int A[], int n){
    for(int i=0; i<n; i++){
        Insert(heap, A[i]);
    }
}

template <class T>
void Display(T& A, int n){
    cout << "[";
    for(int i=0; i<n; i++){
        cout << A[i];
        if(i < n-1){
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main(){
    // First n elements form a Max Heap; the new element is at A[n].
    int A[10] = {45, 35, 15, 30, 10, 12, 6, 5, 20, 50};

    cout << "Array before insertion: ";
    Display(A, 9);

    Insert(A, 9);

    cout << "Array after inserting 50: ";
    Display(A, 10);

    // Same insertion operation using vector.
    vector<int> heap = {45, 35, 15, 30, 10, 12, 6, 5, 20};

    cout << "\nVector before insertion: ";
    Display(heap, heap.size());

    Insert(heap, 50);

    cout << "Vector after inserting 50: ";
    Display(heap, heap.size());

    // Create a heap from an unsorted array by repeated insertion.
    int B[] = {10, 20, 30, 25, 5, 40, 35};
    int n = sizeof(B)/sizeof(B[0]);
    vector<int> createdHeap;

    CreateHeap(createdHeap, B, n);

    cout << "\nHeap created by repeated insertion: ";
    Display(createdHeap, createdHeap.size());

    return 0;
}
