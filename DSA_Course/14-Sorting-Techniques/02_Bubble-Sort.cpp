
#include <iostream>
using namespace std;

// Basic Bubble Sort
// Repeatedly compares adjacent elements and swaps them
// if they are in the wrong order.
void BubbleSort(int A[], int n){

    for(int i=0; i<n-1; i++){

        for(int j=0; j<n-1-i; j++){

            if(A[j] > A[j+1]){
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

// Optimized Bubble Sort
// Stops early if no swapping takes place during a pass.
void BubbleSortOptimized(int A[], int n){

    for(int i=0; i<n-1; i++){

        int swapped = 0;

        for(int j=0; j<n-1-i; j++){

            if(A[j] > A[j+1]){
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;

                swapped = 1;
            }
        }

        // If no elements were swapped, the array is already sorted.
        if(swapped == 0){
            break;
        }
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

    int A[] = {40, 10, 30, 20, 50};
    int n = sizeof(A)/sizeof(A[0]);

    cout << "Original Array: ";
    Display(A, n);

    BubbleSort(A, n);

    cout << "Basic Bubble Sort: ";
    Display(A, n);


    int B[] = {5, 3, 8, 2, 1};
    int m = sizeof(B)/sizeof(B[0]);

    cout << "\nBefore Optimized Bubble Sort: ";
    Display(B, m);

    BubbleSortOptimized(B, m);

    cout << "After Optimized Bubble Sort:  ";
    Display(B, m);


    int C[] = {10, 20, 30, 40, 50};
    int k = sizeof(C)/sizeof(C[0]);

    cout << "\nAlready Sorted Array: ";
    Display(C, k);

    BubbleSortOptimized(C, k);

    cout << "After Optimized Bubble Sort: ";
    Display(C, k);

    return 0;
}
