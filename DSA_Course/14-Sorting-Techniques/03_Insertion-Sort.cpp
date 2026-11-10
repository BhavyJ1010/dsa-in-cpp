
#include <iostream>
using namespace std;

// Insertion Sort
void InsertionSort(int A[], int n){

    // Consider the first element as already sorted.
    // Start from the second element.
    for(int i=1; i<n; i++){

        int x = A[i];
        int j = i-1;

        // Shift elements greater than x one position to the right.
        while(j >= 0 && A[j] > x){
            A[j+1] = A[j];
            j--;
        }

        // Insert x into its correct position.
        A[j+1] = x;
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

    int A[] = {40, 20, 30, 10, 50};
    int n = sizeof(A)/sizeof(A[0]);

    cout << "Original Array: ";
    Display(A, n);

    InsertionSort(A, n);

    cout << "Sorted Array:   ";
    Display(A, n);


    int B[] = {10, 20, 30, 40, 50};
    int m = sizeof(B)/sizeof(B[0]);

    cout << "\nAlready Sorted Array: ";
    Display(B, m);

    InsertionSort(B, m);

    cout << "After Insertion Sort: ";
    Display(B, m);


    int C[] = {50, 40, 30, 20, 10};
    int k = sizeof(C)/sizeof(C[0]);

    cout << "\nReverse Sorted Array: ";
    Display(C, k);

    InsertionSort(C, k);

    cout << "After Insertion Sort: ";
    Display(C, k);

    return 0;
}
