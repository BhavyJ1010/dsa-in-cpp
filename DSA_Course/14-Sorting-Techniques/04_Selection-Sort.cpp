
#include <iostream>
using namespace std;

// Selection Sort
void SelectionSort(int A[], int n){

    for(int i=0; i<n-1; i++){

        // Assume the first element of the unsorted portion is minimum.
        int min = i;

        // Find the actual minimum element in the remaining array.
        for(int j=i+1; j<n; j++){

            if(A[j] < A[min]){
                min = j;
            }
        }

        // Place the minimum element at its correct position.
        if(min != i){
            int temp = A[i];
            A[i] = A[min];
            A[min] = temp;
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

    SelectionSort(A, n);

    cout << "Sorted Array:   ";
    Display(A, n);


    int B[] = {10, 20, 30, 40, 50};
    int m = sizeof(B)/sizeof(B[0]);

    cout << "\nAlready Sorted Array: ";
    Display(B, m);

    SelectionSort(B, m);

    cout << "After Selection Sort: ";
    Display(B, m);


    int C[] = {50, 40, 30, 20, 10};
    int k = sizeof(C)/sizeof(C[0]);

    cout << "\nReverse Sorted Array: ";
    Display(C, k);

    SelectionSort(C, k);

    cout << "After Selection Sort: ";
    Display(C, k);

    return 0;
}
