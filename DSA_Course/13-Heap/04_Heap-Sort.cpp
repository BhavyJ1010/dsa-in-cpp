
#include <iostream>
using namespace std;

// Restore the Max Heap property in the first n elements,
// assuming the left and right subtrees are already Max Heaps.
void Delete(int A[], int n){
    int x = A[0];
    A[0] = A[n-1];
    A[n-1] = x;

    int i = 0;
    int j = 2*i + 1;

    // The last element is now in its correct sorted position,
    // so the active heap contains only indices 0 to n-2.
    while(j < n-1){
        if(j+1 < n-1 && A[j+1] > A[j]){
            j = j+1;
        }

        if(A[i] >= A[j]){
            break;
        }

        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;

        i = j;
        j = 2*i + 1;
    }
}

// Build a Max Heap by repeated insertion.
void Insert(int A[], int n){
    int i = n;
    int temp = A[i];

    while(i > 0 && temp > A[(i-1)/2]){
        A[i] = A[(i-1)/2];
        i = (i-1)/2;
    }

    A[i] = temp;
}

void HeapSort(int A[], int n){
    // First create a Max Heap from the given array.
    for(int i=1; i<n; i++){
        Insert(A, i);
    }

    // Repeatedly delete the maximum and place it at the end.
    for(int i=n; i>1; i--){
        Delete(A, i);
    }
}

void Display(int A[], int n){
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
    int A[] = {14, 15, 5, 20, 30, 8, 40};
    int n = sizeof(A)/sizeof(A[0]);

    cout << "Original Array: ";
    Display(A, n);

    HeapSort(A, n);

    cout << "Sorted Array:   ";
    Display(A, n);

    return 0;
}
