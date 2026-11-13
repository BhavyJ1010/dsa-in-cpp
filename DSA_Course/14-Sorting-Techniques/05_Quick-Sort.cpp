
#include <iostream>
using namespace std;

// Partition using the last element as pivot.
// Places the pivot in its correct position.
int Partition(int A[], int low, int high){

    int pivot = A[high];

    // i represents the boundary of elements <= pivot.
    int i = low-1;

    for(int j=low; j<high; j++){

        if(A[j] <= pivot){

            i++;

            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    // Place pivot immediately after the smaller elements.
    int temp = A[i+1];
    A[i+1] = A[high];
    A[high] = temp;

    return i+1;
}

// Quick Sort
void QuickSort(int A[], int low, int high){

    if(low < high){

        int p = Partition(A, low, high);

        // Sort elements before the pivot.
        QuickSort(A, low, p-1);

        // Sort elements after the pivot.
        QuickSort(A, p+1, high);
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

    int A[] = {40, 20, 60, 10, 30, 50};
    int n = sizeof(A)/sizeof(A[0]);

    cout << "Original Array: ";
    Display(A, n);

    QuickSort(A, 0, n-1);

    cout << "Sorted Array:   ";
    Display(A, n);


    int B[] = {10, 20, 30, 40, 50};
    int m = sizeof(B)/sizeof(B[0]);

    cout << "\nAlready Sorted Array: ";
    Display(B, m);

    QuickSort(B, 0, m-1);

    cout << "After Quick Sort: ";
    Display(B, m);


    int C[] = {50, 40, 30, 20, 10};
    int k = sizeof(C)/sizeof(C[0]);

    cout << "\nReverse Sorted Array: ";
    Display(C, k);

    QuickSort(C, 0, k-1);

    cout << "After Quick Sort: ";
    Display(C, k);


    int D[] = {30, 10, 30, 20, 10, 40};
    int l = sizeof(D)/sizeof(D[0]);

    cout << "\nArray with Duplicates: ";
    Display(D, l);

    QuickSort(D, 0, l-1);

    cout << "After Quick Sort: ";
    Display(D, l);

    return 0;
}
